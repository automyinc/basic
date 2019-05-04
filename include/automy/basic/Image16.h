
#ifndef INCLUDE_AUTOMY_BASIC_IMAGE16_H_
#define INCLUDE_AUTOMY_BASIC_IMAGE16_H_

#include "Image.h"
#include <memory>


namespace automy {
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
} // automy


namespace vnx {

void read(TypeInput& in, ::automy::basic::Image16& value, const TypeCode* type_code, const uint16_t* code);

void write(TypeOutput& out, const ::automy::basic::Image16& value, const TypeCode* type_code, const uint16_t* code);

void read(std::istream& in, ::automy::basic::Image16& value);

void write(std::ostream& out, const ::automy::basic::Image16& value);

void accept(Visitor& visitor, const ::automy::basic::Image16& value);


} // vnx

#endif /* INCLUDE_AUTOMY_BASIC_IMAGE16_H_ */
