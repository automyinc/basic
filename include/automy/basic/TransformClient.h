
#ifndef INCLUDE_AUTOMY_BASIC_TRANSFORMCLIENT_H_
#define INCLUDE_AUTOMY_BASIC_TRANSFORMCLIENT_H_

#include <automy/basic/TransformBuffer.h>
#include <vnx/Subscriber.h>
#include <vnx/Sample.hxx>
#include <vnx/TopicPtr.h>

#include <unistd.h>


namespace automy {
namespace basic {

class TransformClient : public vnx::Subscriber {
public:
	TransformClient(vnx::TopicPtr topic, int64_t history_ms = 1000)
		:	buffer(history_ms)
	{
		subscribe(vnx::shutdown);
		subscribe(topic, history_ms);
	}
	
	bool empty() {
		poll();
		return buffer.empty();
	}
	
	int64_t front_time() {
		poll();
		return buffer.front_time();
	}
	
	int64_t back_time() {
		poll();
		return buffer.back_time();
	}
	
	std::shared_ptr<const Transform3D> query(int64_t time, int64_t timeout_ms = 100) {
		while(vnx_do_run) {
			poll();
			if(time <= buffer.back_time()) {
				return buffer.query(time);
			}
			const int64_t wait_time = time - buffer.back_time();
			if(wait_time > timeout_ms * 1000) {
				return 0;
			}
			::usleep(wait_time + 1000);
		}
		return 0;
	}
	
protected:
	void poll() {
		while(std::shared_ptr<const vnx::Message> message = read()) {
			std::shared_ptr<const vnx::Sample> sample = std::dynamic_pointer_cast<const vnx::Sample>(message);
			if(sample) {
				auto transform = std::dynamic_pointer_cast<const Transform3D>(sample->value);
				if(transform) {
					buffer.push(transform);
				}
				if(!sample->value) {
					exit();
				}
			}
		}
	}
	
private:
	TransformBuffer buffer;
	
};


} // basic
} // automy

#endif /* INCLUDE_AUTOMY_BASIC_TRANSFORMCLIENT_H_ */
