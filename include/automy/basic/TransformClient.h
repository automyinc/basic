
#ifndef INCLUDE_AUTOMY_BASIC_TRANSFORMCLIENT_H_
#define INCLUDE_AUTOMY_BASIC_TRANSFORMCLIENT_H_

#include <automy/basic/TransformBuffer.h>

#include <vnx/Subscriber.h>
#include <vnx/Sample.hxx>
#include <vnx/TopicPtr.h>
#include <vnx/Process.h>


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
		subscribe(topic, history_ms, vnx::Pipe::UNLIMITED, vnx::PIPE_PRIORITY_DEFAULT, vnx::PIPE_MODE_LATEST);
	}
	
	/*
	 * @param domain Base name for topics, eg. "tf".
	 * @param from Source frame for transformation.
	 * @param to Resulting frame after transformation.
	 * @param history_ms History length in ms.
	 */
	TransformClient(	const std::string& domain,
						const std::string& from,
						const std::string& to,
						int64_t history_ms = 10000)
		:	TransformClient(domain + "." + to + "." + from, history_ms)
	{
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
	 * @param timeout_ms Maximum wait time in ms. (zero = no waiting, -1 = infinite wait)
	 */
	std::shared_ptr<const Transform3D> query(int64_t time, int64_t timeout_ms) {
		const auto time_begin = vnx::get_time_millis();
		poll();
		while(vnx::do_run()) {
			if(!m_buffer.empty()) {
				if(time == 0) {
					return m_buffer.back();
				}
				if(time <= m_buffer.back_time()) {
					return m_buffer.query(time);
				}
			}
			if(timeout_ms > 0) {
				const auto now = vnx::get_time_millis();
				if(now >= time_begin) {
					const auto time_left = timeout_ms - (now - time_begin);
					if(time_left > 0) {
						poll(time_left);
					} else {
						break;
					}
				} else {
					break;
				}
			} else if(timeout_ms < 0) {
				poll(-1);
			} else {
				break;
			}
		}
		return nullptr;
	}
	
protected:
	void poll(int64_t timeout_ms = 0) {
		while(auto msg = read_blocking(timeout_ms * 1000)) {
			if(auto sample = std::dynamic_pointer_cast<const vnx::Sample>(msg)) {
				if(auto transform = std::dynamic_pointer_cast<const Transform3D>(sample->value)) {
					m_buffer.push(transform);
				}
			}
			timeout_ms = 0;		// wait only once
		}
	}
	
private:
	TransformBuffer m_buffer;
	
};


} // basic
} // automy

#endif /* INCLUDE_AUTOMY_BASIC_TRANSFORMCLIENT_H_ */
