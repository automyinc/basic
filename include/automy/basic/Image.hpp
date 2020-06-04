
#ifndef INCLUDE_AUTOMY_BASIC_IMAGE_HPP_
#define INCLUDE_AUTOMY_BASIC_IMAGE_HPP_

#include <automy/basic/Image.h>

#include <vnx/Input.hpp>
#include <vnx/Output.hpp>


namespace automy {
namespace basic {

template<typename T>
void Image<T>::read_from_file(const std::string& filename) {
	basic::read_image(*this, filename);
}

template<typename T>
void Image<T>::write_to_file(const std::string& filename, int number, int digits) const {
	basic::write_image(*this, filename, number, digits);
}

template<typename T>
void Image<T>::read(vnx::TypeInput& in, const vnx::TypeCode* type_code, const uint16_t* code) {
	if(code[0] == vnx::CODE_IMAGE || code[0] == vnx::CODE_ALT_IMAGE) {		// new format since vnx-1.2.0
		std::array<size_t, 3> size_;
		vnx::read_image_size<3>(in, size_, code);
		resize(size_[1], size_[2], size_[0]);
		vnx::read_image_data<T, 3>(in, data_, size_, code);
	} else if(code[0] == vnx::CODE_ARRAY && code[1] == 4 && code[2] == vnx::CODE_DYNAMIC) {		// old format
		{
			uint32_t size[3] = {0, 0, 0};
			vnx::read_dynamic(in, size[0]);
			vnx::read_dynamic(in, size[1]);
			vnx::read_dynamic(in, size[2]);
			resize(size[0], size[1], size[2]);
		}
		uint16_t code[VNX_MAX_BYTE_CODE_SIZE];
		size_t size = 0;
		vnx::read_dynamic_list_size<T>(in, code, size);
		if(size == get_size()) {
			vnx::read_dynamic_list_data<T>(in, data_, code, size);
		} else {
			vnx::read_dynamic_list_data<T>(in, 0, code, size);
			clear();
		}
	} else {
		vnx::skip(in, type_code, code);
		clear();
	}
}

template<typename T>
void Image<T>::write(vnx::TypeOutput& out, const vnx::TypeCode* type_code, const uint16_t* code) const {
	vnx::write_image<T, 3>(out, data_, {depth_, width_, height_}, code);
}

template<typename T>
void Image<T>::read(std::istream& in) {
	// not supported
}

template<typename T>
void Image<T>::write(std::ostream& out) const {
	vnx::DefaultPrinter printer(out);
	accept(printer);
}

template<typename T>
void Image<T>::accept(vnx::Visitor& visitor) const {
	vnx::accept_image<T, 3>(visitor, data_, {depth_, width_, height_});
}


template<typename T>
void read_image(Image<T>& image, const std::string& filename) {
	throw std::logic_error("not implemented");
}

template<>
void read_image(Image<uint8_t>& image, const std::string& filename);

template<typename T>
void write_image(const Image<T>& image, const std::string& filename, int number, int digits) {
	throw std::logic_error("not implemented");
}

template<>
void write_image(const Image<uint8_t>& image, const std::string& filename, int number, int digits);

template<typename T>
Image<T> draw_text(int width, int font_size, const std::vector<std::string>& text, const float front_color[3], const float back_color[3]) {
	throw std::logic_error("not implemented");
}

template<>
Image<uint8_t> draw_text(int width, int font_size, const std::vector<std::string>& text, const float front_color[3], const float back_color[3]);


} // basic
} // automy

#endif /* INCLUDE_AUTOMY_BASIC_IMAGE_HPP_ */
