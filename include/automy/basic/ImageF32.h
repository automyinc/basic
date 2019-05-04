
#ifndef INCLUDE_AUTOMY_BASIC_IMAGEF32_H_
#define INCLUDE_AUTOMY_BASIC_IMAGEF32_H_

#include "Image.h"
#include <memory>


namespace automy {
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
} // automy


namespace vnx {

void read(TypeInput& in, ::automy::basic::ImageF32& value, const TypeCode* type_code, const uint16_t* code);

void write(TypeOutput& out, const ::automy::basic::ImageF32& value, const TypeCode* type_code, const uint16_t* code);

void read(std::istream& in, ::automy::basic::ImageF32& value);

void write(std::ostream& out, const ::automy::basic::ImageF32& value);

void accept(Visitor& visitor, const ::automy::basic::ImageF32& value);


} // vnx

#endif /* INCLUDE_AUTOMY_BASIC_IMAGEF32_H_ */
