
#ifndef BASIC_INCLUDE_BASIC_IMAGEF64_H_
#define BASIC_INCLUDE_BASIC_IMAGEF64_H_

#include "Image.h"
#include <memory>


namespace basic {

class ImageF64 : public Image<double> {
public:
	ImageF64() {}
	
	ImageF64(size_t width_, size_t height_, size_t depth_ = 1) : Image(width_, height_, depth_) {}
	
	ImageF64(const Image<double>& image) : Image(image) {}
	
	static std::shared_ptr<ImageF64> create() {
		return std::make_shared<ImageF64>();
	}
	
};


} // basic


namespace vnx {

void read(TypeInput& in, ::basic::ImageF64& value, const TypeCode* type_code, const uint16_t* code);

void write(TypeOutput& out, const ::basic::ImageF64& value, const TypeCode* type_code, const uint16_t* code);

void read(std::istream& in, ::basic::ImageF64& value);

void write(std::ostream& out, const ::basic::ImageF64& value);

void accept(Visitor& visitor, const ::basic::ImageF64& value);


} // vnx

#endif /* BASIC_INCLUDE_BASIC_IMAGEF64_H_ */
