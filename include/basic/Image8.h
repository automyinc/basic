
#ifndef BASIC_INCLUDE_BASIC_IMAGE8_H_
#define BASIC_INCLUDE_BASIC_IMAGE8_H_

#include "Image.h"
#include <memory>


namespace basic {

class Image8 : public Image<uint8_t> {
public:
	Image8() {}
	
	Image8(size_t width_, size_t height_, size_t depth_ = 1) : Image(width_, height_, depth_) {}
	
	Image8(const Image<uint8_t>& image) : Image(image) {}
	
	static std::shared_ptr<Image8> create() {
		return std::make_shared<Image8>();
	}
	
};


} // basic


namespace vnx {

void read(TypeInput& in, ::basic::Image8& value, const TypeCode* type_code, const uint16_t* code);

void write(TypeOutput& out, const ::basic::Image8& value, const TypeCode* type_code, const uint16_t* code);

void read(std::istream& in, ::basic::Image8& value);

void write(std::ostream& out, const ::basic::Image8& value);

void accept(Visitor& visitor, const ::basic::Image8& value);


} // vnx

#endif /* BASIC_INCLUDE_BASIC_IMAGE8_H_ */
