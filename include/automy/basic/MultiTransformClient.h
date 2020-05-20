/*
 * MultiTransformClient.h
 *
 *  Created on: May 18, 2020
 *      Author: mad
 */

#ifndef INCLUDE_AUTOMY_BASIC_MULTITRANSFORMCLIENT_H_
#define INCLUDE_AUTOMY_BASIC_MULTITRANSFORMCLIENT_H_

#include <automy/basic/TransformClient.h>


namespace automy {
namespace basic {

/*
 * Query a transformation that is a chain of sub-transformations.
 */
class MultiTransformClient {
public:
	/*
	 * Each frame in the chain needs a dedicated topic with the same name, in a domain matching the parent frame.
	 *
	 * For example: domain = "tf", chain = ["odom", "base", "sensor"]
	 * 	- Will subscribe to "tf.odom.base" and "tf.base.sensor".
	 * 	- Will compute the following transformation: base_to_odom * sensor_to_base
	 *
	 * @param domain Base name for topics, eg. "tf"
	 * @param chain Chain of transformations, given as a list of frames.
	 * @param history_ms History length in ms.
	 */
	MultiTransformClient(const std::string& domain, const std::vector<std::string>& chain, int64_t history_ms = 10000)
		:	m_chain(chain)
	{
		std::string parent;
		for(const auto& frame : chain) {
			if(!parent.empty()) {
				m_buffers.push_back(std::make_shared<TransformClient>(domain + "." + parent + "." + frame, history_ms));
			}
			parent = frame;
		}
	}

	bool empty() {
		for(auto buffer : m_buffers) {
			if(buffer->empty()) {
				return true;
			}
		}
		return false;
	}

	int64_t front_time() {
		int64_t time = 0;
		for(auto buffer : m_buffers) {
			time = std::max(buffer->front_time(), time);
		}
		return time;
	}

	int64_t back_time() {
		int64_t time = 0;
		for(auto buffer : m_buffers) {
			time = time > 0 ? std::min(buffer->back_time(), time) : buffer->back_time();
		}
		return time;
	}

	/*
	 * @param time Timestamp in usec, zero = latest available.
	 * @param timeout_ms Maximum wait time in ms.
	 */
	std::shared_ptr<const Transform3D> query(int64_t time, int64_t timeout_ms) {
		if(time == 0) {
			time = back_time();
		}
		std::vector<std::shared_ptr<const Transform3D>> transforms;
		for(auto buffer : m_buffers) {
			auto sample = buffer->query(time, timeout_ms);
			if(sample) {
				transforms.push_back(sample);
			} else {
				return 0;		// timeout
			}
		}
		auto result = Transform3D::create();
		result->time = time;
		result->frame = m_chain.back();
		result->parent = m_chain.front();
		result->matrix = automy::math::Matrix4d::Identity();
		for(auto trans : transforms) {
			result->matrix = result->matrix * trans->matrix;
		}
		return result;
	}

private:
	std::vector<std::string> m_chain;
	std::vector<std::shared_ptr<TransformClient>> m_buffers;

};


} // basic
} // automy

#endif /* INCLUDE_AUTOMY_BASIC_MULTITRANSFORMCLIENT_H_ */
