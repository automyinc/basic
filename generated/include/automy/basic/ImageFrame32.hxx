
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_automy_basic_ImageFrame32_HXX_
#define INCLUDE_automy_basic_ImageFrame32_HXX_

#include <automy/basic/package.hxx>
#include <automy/basic/Image32.hpp>
#include <automy/basic/ImageFrame.hxx>


namespace automy {
namespace basic {

class ImageFrame32 : public ::automy::basic::ImageFrame {
public:
	
	::automy::basic::Image32 image;
	
	typedef ::automy::basic::ImageFrame Super;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	vnx::Hash64 get_type_hash() const override;
	const char* get_type_name() const override;
	const vnx::TypeCode* get_type_code() const override;
	
	static std::shared_ptr<ImageFrame32> create();
	std::shared_ptr<vnx::Value> clone() const override;
	
	void read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) override;
	void write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const override;
	
	void read(std::istream& _in) override;
	void write(std::ostream& _out) const override;
	
	void accept(vnx::Visitor& _visitor) const override;
	
	vnx::Object to_object() const override;
	void from_object(const vnx::Object& object) override;
	
	vnx::Variant get_field(const std::string& name) const override;
	void set_field(const std::string& name, const vnx::Variant& value) override;
	
	friend std::ostream& operator<<(std::ostream& _out, const ImageFrame32& _value);
	friend std::istream& operator>>(std::istream& _in, ImageFrame32& _value);
	
	static const vnx::TypeCode* static_get_type_code();
	static std::shared_ptr<vnx::TypeCode> static_create_type_code();
	
};


} // namespace automy
} // namespace basic

#endif // INCLUDE_automy_basic_ImageFrame32_HXX_
