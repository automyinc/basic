
#ifndef INCLUDE_AUTOMY_BASIC_TRANSFORMCLIENT_H_
#define INCLUDE_AUTOMY_BASIC_TRANSFORMCLIENT_H_

#include <automy/basic/TransformBuffer.h>

#include <vnx/Subscriber.h>
#include <vnx/Sample.hxx>
#include <vnx/TopicPtr.h>
#include <vnx/Process.h>

#include <unistd.h>


namespace automy {
namespace basic {

/*
 * Query a transformation at a given time.
 */
class TransformClient : public vnx::Subscriber {
public:
	/*
	 * @param topic Topic to listen on.
	 * @param history_ms History length in ms.
	 */
	TransformClient(vnx::TopicPtr topic, int64_t history_ms = 10000)
		:	m_buffer(history_ms)
	{
		subscribe(topic, history_ms);
	}
	
	bool empty() {
		poll();
		return m_buffer.empty();
	}
	
	const TransformBuffer& buffer() const {
		return m_buffer;
	}

	int64_t front_time() {
		poll();
		return m_buffer.front_time();
	}
	
	int64_t back_time() {
		poll();
		return m_buffer.back_time();
	}
	
	/*
	 * @param time Timestamp in usec, zero = latest available.
	 * @param timeout_ms Maximum wait time in ms.
	 */
	std::shared_ptr<const Transform3D> query(int64_t time, int64_t timeout_ms) {
		while(vnx::do_run()) {
			poll();
			if(time == 0) {
				return m_buffer.back();
			}
			if(time <= m_buffer.back_time()) {
				return m_buffer.query(time);
			}
			const int64_t wait_time = time - m_buffer.back_time();
			if(wait_time > timeout_ms * 1000) {
				return 0;
			}
			::usleep(wait_time + 100);
		}
		return 0;
	}
	
protected:
	void poll() {
		while(auto msg = read()) {
			auto sample = std::dynamic_pointer_cast<const vnx::Sample>(msg);
			if(sample) {
				auto transform = std::dynamic_pointer_cast<const Transform3D>(sample->value);
				if(transform) {
					m_buffer.push(transform);
				}
			}
		}
	}
	
private:
	TransformBuffer m_buffer;
	
};


} // basic
} // automy

#endif /* INCLUDE_AUTOMY_BASIC_TRANSFORMCLIENT_H_ */
