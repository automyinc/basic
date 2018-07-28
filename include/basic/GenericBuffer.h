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

#ifndef BASIC_INCLUDE_BASIC_GENERICBUFFER_H_
#define BASIC_INCLUDE_BASIC_GENERICBUFFER_H_

#include <vnx/Value.h>


namespace basic {

class GenericBuffer {
public:
	template<typename T>
	std::shared_ptr<T> get() {
		std::shared_ptr<T> result;
		for(const std::shared_ptr<vnx::Value>& sample : buffer) {
			if(sample.use_count() == 1) {
				result = std::dynamic_pointer_cast<T>(sample);
			}
			if(result) {
				break;
			}
		}
		if(!result) {
			result = std::make_shared<T>();
			buffer.push_back(result);
		}
		return result;
	}
	
private:
	std::vector<std::shared_ptr<vnx::Value>> buffer;
	
};


} // vision

#endif /* BASIC_INCLUDE_BASIC_GENERICBUFFER_H_ */
