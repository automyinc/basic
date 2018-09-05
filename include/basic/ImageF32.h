
#ifndef BASIC_INCLUDE_BASIC_IMAGEF32_H_
#define BASIC_INCLUDE_BASIC_IMAGEF32_H_

#include "Image.h"
#include <memory>


namespace basic {

class ImageF32 : public Image<float> {
public:
	ImageF32() {}
	
	ImageF32(size_t width_, size_t height_, size_t depth_ = 1) : Image(width_, height_, depth_) {}
	
	ImageF32(const Image<float>& image) : Image(image) {}
	
	static std::shared_ptr<ImageF32> create() {
		return std::make_shared<ImageF32>();
	}
	
};


} // basic


namespace vnx {

void read(TypeInput& in, ::basic::ImageF32& value, const TypeCode* type_code, const uint16_t* code);

void write(TypeOutput& out, const ::basic::ImageF32& value, const TypeCode* type_code, const uint16_t* code);

void read(std::istream& in, ::basic::ImageF32& value);

void write(std::ostream& out, const ::basic::ImageF32& value);

void accept(Visitor& visitor, const ::basic::ImageF32& value);


} // vnx

#endif /* BASIC_INCLUDE_BASIC_IMAGEF32_H_ */
