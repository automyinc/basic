
#ifndef INCLUDE_AUTOMY_BASIC_TRANSFORMBUFFER_H_
#define INCLUDE_AUTOMY_BASIC_TRANSFORMBUFFER_H_

#include <automy/basic/Transform3D.hxx>

#include <list>


namespace automy {
namespace basic {

class TransformBuffer {
public:
	TransformBuffer(int buffer_window_ms = 1000) {
		buffer_window = buffer_window_ms * 1000;
	}
	
	bool empty() const {
		return history.empty();
	}
	
	std::shared_ptr<const Transform3D> front() const {
		if(history.empty()) {
			return 0;
		}
		return history.front();
	}

	std::shared_ptr<const Transform3D> back() const {
		if(history.empty()) {
			return 0;
		}
		return history.back();
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
		// TODO: interpolate transform
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
} // automy

#endif /* INCLUDE_AUTOMY_BASIC_TRANSFORMBUFFER_H_ */
