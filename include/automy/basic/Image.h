
#ifndef INCLUDE_AUTOMY_BASIC_IMAGE_H_
#define INCLUDE_AUTOMY_BASIC_IMAGE_H_

#include <automy/basic/package.hxx>

#include <vnx/Visitor.h>
#include <vnx/DefaultPrinter.h>

#include <cmath>
#include <cstring>
#include <vector>
#include <memory>


namespace automy {
namespace basic {

template<typename T>
class Image;

template<typename T>
void read_image(Image<T>& image, const std::string& filename);

template<typename T>
void write_image(const Image<T>& image, const std::string& filename, int number = -1, int digits = 6, bool flip_y = true);

template<typename T>
Image<T> draw_text(int width, int font_size, const std::vector<std::string>& text, const float front_color[3], const float back_color[3]);

template<typename T>
void draw_polygon(Image<T>& image, const Image<float>& points, const T* color, bool fill = true);


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
		resize(image.width(), image.height(), image.depth());
		for(size_t i = 0; i < image.get_size(); ++i) {
			(*this)[i] = image[i];
		}
	}
	
	virtual ~Image() {
		clear();
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
				data_= nullptr;
			}
			if(new_size) {
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
		data_ = nullptr;
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
	
	size_t size() const {
		return size_t(width_) * size_t(height_) * size_t(depth_);
	}

	size_t get_size() const {
		return size();
	}
	
	T* data() {
		return data_;
	}

	const T* data() const {
		return data_;
	}

	T* get_data() {
		return data_;
	}
	
	const T* get_data() const {
		return data_;
	}
	
	void fill(const T& value) {
		for(size_t i = 0; i < get_size(); ++i) {
			data_[i] = value;
		}
	}
	
	void fill_layer(size_t z, const T& value) {
		for(uint32_t y = 0; y < height_; ++y) {
			for(uint32_t x = 0; x < width_; ++x) {
				(*this)(x, y, z) = value;
			}
		}
	}
	
	/*
	 * Element wise addition.
	 */
	template<typename S>
	void add(const S value) {
		for(size_t i = 0; i < get_size(); ++i) {
			(*this)[i] += value;
		}
	}
	
	/*
	 * Element wise multiplication.
	 */
	template<typename S>
	void mul(const S factor) {
		for(size_t i = 0; i < get_size(); ++i) {
			(*this)[i] *= factor;
		}
	}
	
	/*
	 * Performs nearest neighbor lookup on the xy plane.
	 * Pixel centers are at 0.5 offsets, ie. 0.5, 1.5, 2.5, etc..
	 */
	template<typename S>
	const T& lookup_nearest(const S x, const S y, const size_t z = 0) const
	{
		const uint32_t x0 = std::min(std::max(int32_t(x), 0), int32_t(width_) - 1);
		const uint32_t y0 = std::min(std::max(int32_t(y), 0), int32_t(height_) - 1);
		return (*this)(x0, y0, z);
	}
	
	/*
	 * Performs bi-linear interpolation on the xy plane.
	 * Pixel centers are at 0.5 offsets, ie. 0.5, 1.5, 2.5, etc..
	 */
	template<typename S>
	S lookup_bilinear(const S x, const S y, const size_t z = 0) const
	{
		const S x_ = x - S(0.5);
		const S y_ = y - S(0.5);
		const uint32_t x0 = std::min(std::max(int32_t(x_), 0), int32_t(width_) - 1);
		const uint32_t x1 = std::min(int32_t(x0) + 1, int32_t(width_) - 1);
		const uint32_t y0 = std::min(std::max(int32_t(y_), 0), int32_t(height_) - 1);
		const uint32_t y1 = std::min(int32_t(y0) + 1, int32_t(height_) - 1);
		
		const S a = x_ - std::floor(x_);
		const S b = y_ - std::floor(y_);
		
		return		S((*this)(x0, y0, z)) * ((S(1) - a) * (S(1) - b))
				+	S((*this)(x1, y0, z)) * (a * (S(1) - b))
				+	S((*this)(x0, y1, z)) * ((S(1) - a) * b)
				+	S((*this)(x1, y1, z)) * (a * b);
	}
	
	/*
	 * Computes element wise sum using SumType for summation.
	 */
	template<typename SumType>
	std::vector<SumType> get_element_sum() const
	{
		std::vector<SumType> sum(depth_);
		for(uint32_t y = 0; y < height_; ++y) {
			for(uint32_t x = 0; x < width_; ++x) {
				for(uint32_t z = 0; z < depth_; ++z) {
					sum[z] += (*this)(x, y, z);
				}
			}
		}
		return sum;
	}
	
	/*
	 * Computes average pixel values using SumType for summation
	 * and ResultType for return type.
	 */
	template<typename ResultType, typename SumType>
	std::vector<ResultType> get_average() const
	{
		const auto sum = get_element_sum<SumType>();
		std::vector<ResultType> result(depth_);
		for(uint32_t i = 0; i < depth_; ++i) {
			result[i] = sum[i] / ResultType(size_t(width_) * size_t(height_));
		}
		return result;
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
	
	void draw_polygon(const Image<float>& points, const T* color, bool fill) {
		basic::draw_polygon(*this, points, color, fill);
	}

	void read_from_file(const std::string& filename);
	
	void write_to_file(const std::string& filename, int number = -1, int digits = 6, bool flip_y = true) const;
	
	void read(vnx::TypeInput& in, const vnx::TypeCode* type_code, const uint16_t* code);
	
	void write(vnx::TypeOutput& out, const vnx::TypeCode* type_code, const uint16_t* code) const;
	
	void read(std::istream& in);
	
	void write(std::ostream& out) const;
	
	void accept(vnx::Visitor& visitor) const;
	
private:
	T* data_ = 0;
	uint32_t width_ = 0;
	uint32_t height_ = 0;
	uint32_t depth_ = 0;
	
};


} // basic
} // automy

#endif /* INCLUDE_AUTOMY_BASIC_IMAGE_H_ */
