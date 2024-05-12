
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_automy_basic_ImageFrame32_HXX_
#define INCLUDE_automy_basic_ImageFrame32_HXX_

#include <automy/basic/package.hxx>
#include <automy/basic/Image32.hpp>
#include <automy/basic/ImageFrame.hxx>


namespace automy {
namespace basic {

class AUTOMY_BASIC_EXPORT ImageFrame32 : public ::automy::basic::ImageFrame {
public:
	
	::automy::basic::Image32 image;
	
	typedef ::automy::basic::ImageFrame Super;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	static constexpr uint64_t VNX_TYPE_ID = 0xbd06ec311906bd99ull;
	
	ImageFrame32() {}
	
	vnx::Hash64 get_type_hash() const override;
	std::string get_type_name() const override;
	const vnx::TypeCode* get_type_code() const override;
	
	static std::shared_ptr<ImageFrame32> create();
	std::shared_ptr<vnx::Value> clone() const override;
	
	void read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) override;
	void write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const override;
	
	void read(std::istream& _in) override;
	void write(std::ostream& _out) const override;
	
	template<typename T>
	void accept_generic(T& _visitor) const;
	void accept(vnx::Visitor& _visitor) const override;
	
	vnx::Object to_object() const override;
	void from_object(const vnx::Object& object) override;
	
	vnx::Variant get_field(const std::string& name) const override;
	void set_field(const std::string& name, const vnx::Variant& value) override;
	
	friend std::ostream& operator<<(std::ostream& _out, const ImageFrame32& _value);
	friend std::istream& operator>>(std::istream& _in, ImageFrame32& _value);
	
	static const vnx::TypeCode* static_get_type_code();
	static std::shared_ptr<vnx::TypeCode> static_create_type_code();
	
protected:
	std::shared_ptr<vnx::Value> vnx_call_switch(std::shared_ptr<const vnx::Value> _method) override;
	
};

template<typename T>
void ImageFrame32::accept_generic(T& _visitor) const {
	_visitor.template type_begin<ImageFrame32>(5);
	_visitor.type_field("time", 0); _visitor.accept(time);
	_visitor.type_field("frame", 1); _visitor.accept(frame);
	_visitor.type_field("format", 2); _visitor.accept(format);
	_visitor.type_field("properties", 3); _visitor.accept(properties);
	_visitor.type_field("image", 4); _visitor.accept(image);
	_visitor.template type_end<ImageFrame32>(5);
}


} // namespace automy
} // namespace basic


namespace vnx {

} // vnx

#endif // INCLUDE_automy_basic_ImageFrame32_HXX_
