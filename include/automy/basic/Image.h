
#ifndef INCLUDE_AUTOMY_BASIC_IMAGE_H_
#define INCLUDE_AUTOMY_BASIC_IMAGE_H_

#include <vnx/Type.h>
#include <vnx/Input.h>
#include <vnx/Output.h>
#include <vnx/Visitor.h>
#include <vnx/DefaultPrinter.h>


namespace automy {
namespace basic {

template<typename T>
class Image;

template<typename T>
void read_image(Image<T>& image, const std::string& filename);

template<typename T>
void write_image(const Image<T>& image, const std::string& filename, int number = -1, int digits = 6);

template<typename T>
Image<T> draw_text(int width, int font_size, const std::vector<std::string>& text, const float front_color[3], const float back_color[3]);


/** \brief Generic image class for 2D and 2.5D images.
 * 
 * The memory layout for a single-channel image is as follows:
 * [x0_y0, x1_y0, x2_y0, ..., x0_y1, x1_y1, x2_y1, ...]
 * 
 * The memory layout for a multi-channel image is as follows:
 * [	x0_y0_c0, x0_y0_c1, x0_y0_c2, ..., x1_y0_c0, x1_y0_c1, x1_y0_c2, ...
 * 		x0_y1_c0, x0_y1_c1, x0_y1_c2, ...]
 * 
 */
template<typename T>
class Image {
public:
	Image() {}
	
	Image(size_t width_, size_t height_, size_t depth_ = 1) {
		resize(width_, height_, depth_);
	}
	
	Image(const Image& image) {
		*this = image;
	}
	
	template<typename S>
	explicit Image(const Image<S>& image) {
		resize(image.width_, image.height_, image.depth_);
		for(size_t i = 0; i < image.get_size(); ++i) {
			data_[i] = image.data_[i];
		}
	}
	
	virtual ~Image() {
		delete [] data_;
	}
	
	static std::shared_ptr<Image<T>> create() {
		return std::make_shared<Image<T>>();
	}
	
	Image& operator=(const Image& image) {
		resize(image.width_, image.height_, image.depth_);
		::memcpy(data_, image.data_, get_size() * sizeof(T));
		return *this;
	}
	
	uint32_t width() const {
		return width_;
	}
	
	uint32_t height() const {
		return height_;
	}
	
	uint32_t depth() const {
		return depth_;
	}
	
	void resize(size_t new_width, size_t new_height, size_t new_depth = 1) {
		if(new_width > 0xFFFFFFFF || new_height > 0xFFFFFFFF || new_depth > 0xFFFFFFFF) {
			throw std::invalid_argument("new_width, new_height or new_depth out of bounds");
		}
		const size_t new_size = new_width * new_height * new_depth;
		if(new_size != get_size()) {
			if(data_) {
				delete [] data_;
				data_= 0;
			}
			if(new_size > 0) {
				data_ = new T[new_size];
			}
		}
		width_ = uint32_t(new_width);
		height_ = uint32_t(new_height);
		depth_ = uint32_t(new_depth);
	}
	
	void clear() {
		width_ = 0;
		height_ = 0;
		depth_ = 0;
		delete [] data_;
		data_ = 0;
	}
	
	void fill(const T& value) {
		for(size_t i = 0; i < get_size(); ++i) {
			data_[i] = value;
		}
	}
	
	void fill_layer(size_t layer, const T& value) {
		for(size_t y = 0; y < height_; ++y) {
			for(size_t x = 0; x < width_; ++x) {
				(*this)(x, y, layer) = value;
			}
		}
	}
	
	T& operator[](size_t i) {
		return data_[i];
	}
	
	const T& operator[](size_t i) const {
		return data_[i];
	}
	
	T& operator()(size_t x, size_t y, size_t z = 0) {
		return data_[(y * width_ + x) * depth_ + z];
	}
	
	const T& operator()(size_t x, size_t y, size_t z = 0) const {
		return data_[(y * width_ + x) * depth_ + z];
	}
	
	size_t get_size() const {
		return size_t(width_) * size_t(height_) * size_t(depth_);
	}
	
	T* get_data() {
		return data_;
	}
	
	const T* get_data() const {
		return data_;
	}
	
	/*
	 * Draw another image on top. Origin is upper left corner.
	 */
	void draw_image_ul(size_t x0, size_t y0, const Image<T>& image) {
		draw_image_ll(x0, y0 - image.height_, image);
	}
	
	/*
	 * Draw another image on top. Origin is lower left corner.
	 */
	void draw_image_ll(size_t x0, size_t y0, const Image<T>& image) {
		const size_t max_width = image->width + std::min(width_ - (x0 + image->width), 0u);
		const size_t max_height = image->height + std::min(height_ - (y0 + image->height), 0u);
		const size_t max_depth = std::min(image->depth, depth_);
		for(size_t y = 0; y < max_height; ++y) {
			for(size_t x = 0; x < max_width; ++x) {
				for(size_t c = 0; c < max_depth; ++c) {
					(*this)(x0 + x, y0 + y, c) = image(x, y, c);
				}
			}
		}
	}
	
	/*
	 * Draw single line text. Origin is upper left corner.
	 */
	void draw_text_ul(size_t x0, size_t y0, int width, int font_size, const std::string& text,
						const float front_color[3], const float back_color[3])
	{
		std::vector<std::string> tmp;
		tmp.push_back(text);
		draw_text_ul(x0, y0, width, font_size, tmp, front_color, back_color);
	}
	
	/*
	 * Draw multi-line text. Origin is upper left corner.
	 */
	void draw_text_ul(size_t x0, size_t y0, int width, int font_size, const std::vector<std::string>& text,
						const float front_color[3], const float back_color[3])
	{
		Image<T> tmp = basic::draw_text<T>(width, font_size, text, front_color, back_color);
		draw_image_ul(x0, y0, tmp);
	}
	
	/*
	 * Draw single line text. Origin is lower left corner.
	 */
	void draw_text_ll(size_t x0, size_t y0, int width, int font_size, const std::string& text,
						const float front_color[3], const float back_color[3])
	{
		std::vector<std::string> tmp;
		tmp.push_back(text);
		draw_text_ll(x0, y0, width, font_size, tmp, front_color, back_color);
	}
	
	/*
	 * Draw multi-line text. Origin is lower left corner.
	 */
	void draw_text_ll(size_t x0, size_t y0, int width, int font_size, const std::vector<std::string>& text,
						const float front_color[3], const float back_color[3])
	{
		Image<T> tmp = basic::draw_text<T>(width, font_size, text, front_color, back_color);
		draw_image_ll(x0, y0, tmp);
	}
	
	void read_from_file(const std::string& filename) {
		basic::read_image(*this, filename);
	}
	
	void write_to_file(const std::string& filename, int number = -1, int digits = 6) {
		basic::write_image(*this, filename, number, digits);
	}
	
	void read(vnx::TypeInput& in, const vnx::TypeCode* type_code, const uint16_t* code) {
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
	
	void write(vnx::TypeOutput& out, const vnx::TypeCode* type_code, const uint16_t* code) const {
		vnx::write_image<T, 3>(out, data_, {depth_, width_, height_}, code);
	}
	
	void read(std::istream& in) {
		// not supported
	}
	
	void write(std::ostream& out) const {
		vnx::DefaultPrinter printer(out);
		accept(printer);
	}
	
	void accept(vnx::Visitor& visitor) const {
		vnx::accept_image<T, 3>(visitor, data_, {depth_, width_, height_});
	}
	
private:
	T* data_ = 0;
	uint32_t width_ = 0;
	uint32_t height_ = 0;
	uint32_t depth_ = 0;
	
};


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

#endif /* INCLUDE_AUTOMY_BASIC_IMAGE_H_ */
