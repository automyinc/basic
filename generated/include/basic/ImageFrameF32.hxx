
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_basic_ImageFrameF32_HXX_
#define INCLUDE_basic_ImageFrameF32_HXX_

#include <basic/package.hxx>
#include <basic/ImageF32.h>
#include <basic/ImageFrame.hxx>


namespace basic {

class ImageFrameF32 : public ::basic::ImageFrame {
public:
	
	::basic::ImageF32 image;
	
	typedef ::basic::ImageFrame Super;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	vnx::Hash64 get_type_hash() const;
	const char* get_type_name() const;
	
	static std::shared_ptr<ImageFrameF32> create();
	std::shared_ptr<vnx::Value> clone() const;
	
	void read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code);
	void write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const;
	
	void read(std::istream& _in);
	void write(std::ostream& _out) const;
	
	void accept(vnx::Visitor& _visitor) const;
	
	friend std::ostream& operator<<(std::ostream& _out, const ImageFrameF32& _value);
	friend std::istream& operator>>(std::istream& _in, ImageFrameF32& _value);
	
	static const vnx::TypeCode* get_type_code();
	static std::shared_ptr<vnx::TypeCode> create_type_code();
	
};


} // namespace basic

#endif // INCLUDE_basic_ImageFrameF32_HXX_
