/*
 * GenericTransformClient.h
 *
 *  Created on: Aug 13, 2020
 *      Author: mad
 */

#ifndef BASIC_INCLUDE_AUTOMY_BASIC_GENERICTRANSFORMCLIENT_H_
#define BASIC_INCLUDE_AUTOMY_BASIC_GENERICTRANSFORMCLIENT_H_

#include <automy/basic/TransformBuffer.h>

#include <vnx/Subscriber.h>
#include <vnx/Sample.hxx>
#include <vnx/TopicPtr.h>
#include <vnx/Process.h>


namespace automy {
namespace basic {

/*
 * Query a given transformation at a given time.
 * Only supports direct transformations, no chains.
 */
class GenericTransformClient : public vnx::Subscriber {
public:
	GenericTransformClient(const std::string& domain, int64_t history_ms = 10000)
		:	max_history_ms(history_ms)
	{
		subscribe(domain, history_ms);
	}

	/*
	 * @param time Timestamp in usec, zero = latest available.
	 * @param from Source frame
	 * @param to Target frame
	 * @param timeout_ms Maximum wait time in ms. (zero = no waiting, -1 = infinite wait)
	 */
	std::shared_ptr<const Transform3D> query(	int64_t time,
												const std::string& from,
												const std::string& to,
												int64_t timeout_ms)
	{
		const auto time_begin = vnx::get_time_millis();
		const auto key = std::make_pair(to, from);
		poll();
		while(vnx::do_run()) {
			auto buffer = m_buffer[key];
			if(buffer && !buffer->empty()) {
				if(time == 0) {
					return buffer->back();
				}
				if(time <= buffer->back_time()) {
					return buffer->query(time);
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
			auto sample = std::dynamic_pointer_cast<const vnx::Sample>(msg);
			if(sample) {
				auto transform = std::dynamic_pointer_cast<const Transform3D>(sample->value);
				if(transform) {
					auto& buffer = m_buffer[std::make_pair(transform->parent, transform->frame)];
					if(!buffer) {
						buffer = std::make_shared<TransformBuffer>(max_history_ms);
					}
					buffer->push(transform);
				}
			}
			timeout_ms = 0;		// wait only once
		}
	}

private:
	int64_t max_history_ms = 0;
	std::map<std::pair<std::string, std::string>, std::shared_ptr<TransformBuffer>> m_buffer;

};


} // basic
} // automy

#endif /* BASIC_INCLUDE_AUTOMY_BASIC_GENERICTRANSFORMCLIENT_H_ */
