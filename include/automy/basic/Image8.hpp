
#ifndef INCLUDE_AUTOMY_BASIC_IMAGE8_HPP_
#define INCLUDE_AUTOMY_BASIC_IMAGE8_HPP_

#include <automy/basic/Image.hpp>


namespace automy {
namespace basic {

class Image8 : public Image<uint8_t> {
public:
	Image8() = default;

	Image8(size_t width_, size_t height_, size_t depth_ = 1) : Image(width_, height_, depth_) {}

	Image8(const Image<uint8_t>& image) : Image(image) {}

	template<typename S>
	explicit Image8(const Image<S>& image) : Image(image) {}

	static std::shared_ptr<Image8> create() {
		return std::make_shared<Image8>();
	}

};


} // basic
} // automy


namespace vnx {

void read(TypeInput& in, ::automy::basic::Image8& value, const TypeCode* type_code, const uint16_t* code);

void write(TypeOutput& out, const ::automy::basic::Image8& value, const TypeCode* type_code, const uint16_t* code);

void read(std::istream& in, ::automy::basic::Image8& value);

void write(std::ostream& out, const ::automy::basic::Image8& value);

void accept(Visitor& visitor, const ::automy::basic::Image8& value);


} // vnx

#endif /* INCLUDE_AUTOMY_BASIC_IMAGE8_HPP_ */
