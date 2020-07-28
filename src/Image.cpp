
#include <automy/basic/Image.hpp>

#include <algorithm>

#define cimg_display 0
#define cimg_use_png 1
#define cimg_use_jpeg 1

#include "CImg.h"
using namespace cimg_library;


namespace automy {
namespace basic {

template<typename T>
CImg<T> convert_to_cimg(const Image<T>& image) {
	CImg<T> out;
	out.resize(image.width(), image.height(), 1, image.depth());
	for(int y = 0; y < image.height(); ++y) {
		for(int x = 0; x < image.width(); ++x) {
			for(int c = 0; c < image.depth(); ++c) {
				out(x, image.height()-y-1, 0, c) = image(x, y, c);
			}
		}
	}
	return out;
}

template<typename T>
Image<T> convert_from_cimg(const CImg<T>& image) {
	Image<T> out;
	out.resize(image.width(), image.height(), image.spectrum());
	for(int y = 0; y < image.height(); ++y) {
		for(int x = 0; x < image.width(); ++x) {
			for(int c = 0; c < image.spectrum(); ++c) {
				out(x, image.height()-y-1, c) = image(x, y, 0, c);
			}
		}
	}
	return out;
}

template<>
void read_image(Image<uint8_t>& image, const std::string& filename) {
	CImg<uint8_t> tmp(filename.c_str());
	image = convert_from_cimg(tmp);
}

template<>
void write_image(const Image<uint8_t>& image, const std::string& filename, int number, int digits) {
	convert_to_cimg(image).save(filename.c_str(), number, digits);
}

template<>
Image<uint8_t> draw_text(int width, int font_size, const std::vector<std::string>& text, const float front_color[3], const float back_color[3]) {
	CImg<uint8_t> tmp;
	tmp.resize(width, font_size * text.size(), 1, 3);
	for(int y = 0; y < tmp.height(); ++y) {
		for(int x = 0; x < tmp.width(); ++x) {
			for(int c = 0; c < 3; ++c) {
				tmp(x, y, c) = back_color[c];
			}
		}
	}
	int offset = 0;
	for(const std::string& line : text) {
		tmp.draw_text(2, offset, line.c_str(), front_color, back_color, 1, font_size);
		offset += font_size;
	}
	return convert_from_cimg<uint8_t>(tmp);
}

template<>
void draw_polygon(Image<uint8_t>& image, const Image<float>& points, const uint8_t* color, bool fill) {
	auto image_ = convert_to_cimg(image);
	CImg<float> points_(points.width(), points.height());
	for(int i = 0; i < points.width(); ++i) {
		points_(i, 0) = points(i, 0);
		points_(i, 1) = image_.height() - points(i, 1);
	}
	if(fill) {
		image_.draw_polygon(points_, color);
	} else {
		image_.draw_polygon(points_, color, 1, 0xFFFFFFFF);
	}
	image = convert_from_cimg(image_);
}


} // basic
} // automy
