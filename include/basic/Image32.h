
#ifndef BASIC_INCLUDE_BASIC_IMAGE32_H_
#define BASIC_INCLUDE_BASIC_IMAGE32_H_

#include "Image.h"
#include <memory>


namespace basic {

class Image32 : public Image<uint32_t> {
public:
	Image32() {}
	
	Image32(size_t width_, size_t height_, size_t depth_ = 1) : Image(width_, height_, depth_) {}
	
	Image32(const Image<uint32_t>& image) : Image(image) {}
	
	static std::shared_ptr<Image32> create() {
		return std::make_shared<Image32>();
	}
	
};


} // basic


namespace vnx {

void read(TypeInput& in, ::basic::Image32& value, const TypeCode* type_code, const uint16_t* code);

void write(TypeOutput& out, const ::basic::Image32& value, const TypeCode* type_code, const uint16_t* code);

void read(std::istream& in, ::basic::Image32& value);

void write(std::ostream& out, const ::basic::Image32& value);

void accept(Visitor& visitor, const ::basic::Image32& value);


} // vnx

#endif /* BASIC_INCLUDE_BASIC_IMAGE32_H_ */
