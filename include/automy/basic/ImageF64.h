
#ifndef INCLUDE_AUTOMY_BASIC_IMAGEF64_H_
#define INCLUDE_AUTOMY_BASIC_IMAGEF64_H_

#include "Image.h"
#include <memory>


namespace automy {
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
} // automy


namespace vnx {

void read(TypeInput& in, ::automy::basic::ImageF64& value, const TypeCode* type_code, const uint16_t* code);

void write(TypeOutput& out, const ::automy::basic::ImageF64& value, const TypeCode* type_code, const uint16_t* code);

void read(std::istream& in, ::automy::basic::ImageF64& value);

void write(std::ostream& out, const ::automy::basic::ImageF64& value);

void accept(Visitor& visitor, const ::automy::basic::ImageF64& value);


} // vnx

#endif /* INCLUDE_AUTOMY_BASIC_IMAGEF64_H_ */
