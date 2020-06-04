
#ifndef INCLUDE_AUTOMY_BASIC_IMAGE32_HPP_
#define INCLUDE_AUTOMY_BASIC_IMAGE32_HPP_

#include <automy/basic/Image.hpp>


namespace automy {
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
} // automy


namespace vnx {

void read(TypeInput& in, ::automy::basic::Image32& value, const TypeCode* type_code, const uint16_t* code);

void write(TypeOutput& out, const ::automy::basic::Image32& value, const TypeCode* type_code, const uint16_t* code);

void read(std::istream& in, ::automy::basic::Image32& value);

void write(std::ostream& out, const ::automy::basic::Image32& value);

void accept(Visitor& visitor, const ::automy::basic::Image32& value);


} // vnx

#endif /* INCLUDE_AUTOMY_BASIC_IMAGE32_HPP_ */
