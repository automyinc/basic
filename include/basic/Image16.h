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

#ifndef BASIC_INCLUDE_BASIC_IMAGE16_H_
#define BASIC_INCLUDE_BASIC_IMAGE16_H_

#include "Image.h"
#include <memory>


namespace basic {

class Image16 : public Image<uint16_t> {
public:
	Image16() {}
	
	Image16(size_t width_, size_t height_, size_t depth_ = 1) : Image(width_, height_, depth_) {}
	
	Image16(const Image<uint16_t>& image) : Image(image) {}
	
	static std::shared_ptr<Image16> create() {
		return std::make_shared<Image16>();
	}
	
};


} // basic


namespace vnx {

void read(TypeInput& in, ::basic::Image16& value, const TypeCode* type_code, const uint16_t* code);

void write(TypeOutput& out, const ::basic::Image16& value, const TypeCode* type_code, const uint16_t* code);

void read(std::istream& in, ::basic::Image16& value);

void write(std::ostream& out, const ::basic::Image16& value);

void accept(Visitor& visitor, const ::basic::Image16& value);


} // vnx

#endif /* BASIC_INCLUDE_BASIC_IMAGE16_H_ */
