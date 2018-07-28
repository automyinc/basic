 /*************************************************************************
 * 
 *  [2017] - [2018] Automy Inc. 
 *  All Rights Reserved.
 * 
 * NOTICE:  All information contained herein is, and remains
 * the property of Automy Incorporated and its suppliers,
 * if any.  The intellectual and technical concepts contained
 * herein are proprietary to Automy Incorporated
 * and its suppliers and may be covered by U.S. and Foreign Patents,
 * patents in process, and are protected by trade secret or copyright law.
 * Dissemination of this information or reproduction of this material
 * is strictly forbidden unless prior written permission is obtained
 * from Automy Incorporated.
 */

#ifndef BASIC_INCLUDE_BASIC_TRANSFORMBUFFER_H_
#define BASIC_INCLUDE_BASIC_TRANSFORMBUFFER_H_

#include <basic/Transform3D.hxx>

#include <list>


namespace basic {

class TransformBuffer {
public:
	TransformBuffer(int buffer_window_ms = 1000) {
		buffer_window = buffer_window_ms * 1000;
	}
	
	bool empty() const {
		return history.empty();
	}
	
	int64_t front_time() const {
		if(history.empty()) {
			return -1;
		}
		return history.front()->time;
	}
	
	int64_t back_time() const {
		if(history.empty()) {
			return -1;
		}
		return history.back()->time;
	}
	
	void push(std::shared_ptr<const Transform3D> sample) {
		if(!history.empty() && sample->time < history.front()->time) {
			history.clear();
		}
		if(history.empty() || sample->time > history.back()->time) {
			history.push_back(sample);
		}
		while(history.back()->time - history.front()->time > buffer_window) {
			history.pop_front();
		}
	}
	
	std::shared_ptr<const Transform3D> query(int64_t time) const {
		if(history.empty()) {
			return 0;
		}
		if(time < history.front()->time) {
			return 0;
		}
		if(time > history.back()->time) {
			return 0;
		}
		auto iter = --history.cend();
		if(time >= (*iter)->time) {
			return *iter;
		}
		auto prev = iter;
		while(true) {
			if(iter == history.cbegin()) {
				break;
			}
			prev = iter--;
			const int64_t delta_0 = time - (*iter)->time;
			const int64_t delta_1 = (*prev)->time - time;
			if(delta_0 >= 0 && delta_1 >= 0) {
				if(delta_0 < delta_1) {
					return *iter;
				} else {
					return *prev;
				}
			}
		}
		return *iter;
	}
	
private:
	int64_t buffer_window = 0;
	std::list<std::shared_ptr<const Transform3D>> history;
	
};


} // basic

#endif /* BASIC_INCLUDE_BASIC_TRANSFORMBUFFER_H_ */
