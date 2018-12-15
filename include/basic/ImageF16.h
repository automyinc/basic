
#ifndef BASIC_INCLUDE_BASIC_IMAGEF16_H_
#define BASIC_INCLUDE_BASIC_IMAGEF16_H_

#include "Image.h"
#include <memory>


namespace basic {

class ImageF16 : public Image<uint16_t> {
public:
	ImageF16() {}
	
	ImageF16(size_t width_, size_t height_, size_t depth_ = 1) : Image(width_, height_, depth_) {}
	
	ImageF16(const Image<uint16_t>& image) : Image(image) {}
	
	static std::shared_ptr<ImageF16> create() {
		return std::make_shared<ImageF16>();
	}
	
};


} // basic


namespace vnx {

void read(TypeInput& in, ::basic::ImageF16& value, const TypeCode* type_code, const uint16_t* code);

void write(TypeOutput& out, const ::basic::ImageF16& value, const TypeCode* type_code, const uint16_t* code);

void read(std::istream& in, ::basic::ImageF16& value);

void write(std::ostream& out, const ::basic::ImageF16& value);

void accept(Visitor& visitor, const ::basic::ImageF16& value);


} // vnx

#endif /* BASIC_INCLUDE_BASIC_IMAGEF16_H_ */
