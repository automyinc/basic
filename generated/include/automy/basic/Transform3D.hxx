
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_automy_basic_Transform3D_HXX_
#define INCLUDE_automy_basic_Transform3D_HXX_

#include <automy/basic/package.hxx>
#include <automy/math/Matrix4d.hpp>
#include <vnx/Object.hpp>
#include <vnx/TopicPtr.hpp>
#include <vnx/Value.h>


namespace automy {
namespace basic {

class AUTOMY_BASIC_EXPORT Transform3D : public ::vnx::Value {
public:
	
	int64_t time = 0;
	int32_t time_offset = 0;
	std::string frame;
	std::string parent;
	::automy::math::Matrix4d matrix;
	
	typedef ::vnx::Value Super;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	static constexpr uint64_t VNX_TYPE_ID = 0xe762feb1b334b36dull;
	
	Transform3D() {}
	
	vnx::Hash64 get_type_hash() const override;
	std::string get_type_name() const override;
	const vnx::TypeCode* get_type_code() const override;
	
	virtual ::vnx::TopicPtr get_topic(const std::string& tf_domain = "") const;
	virtual void transform(std::shared_ptr<const ::automy::basic::Transform3D> sample = nullptr);
	virtual std::shared_ptr<const ::automy::basic::Transform3D> get_inverse() const;
	virtual ::automy::math::Matrix4d get_transform25() const;
	virtual std::shared_ptr<const ::automy::basic::Transform3D> get_interpolated(std::shared_ptr<const ::automy::basic::Transform3D> sample_1 = nullptr, const vnx::float64_t& t = 0) const;
	static std::shared_ptr<const ::automy::basic::Transform3D> from_config(const ::vnx::Object& config = ::vnx::Object());
	
	static std::shared_ptr<Transform3D> create();
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
	
	friend std::ostream& operator<<(std::ostream& _out, const Transform3D& _value);
	friend std::istream& operator>>(std::istream& _in, Transform3D& _value);
	
	static const vnx::TypeCode* static_get_type_code();
	static std::shared_ptr<vnx::TypeCode> static_create_type_code();
	
protected:
	std::shared_ptr<vnx::Value> vnx_call_switch(std::shared_ptr<const vnx::Value> _method) override;
	
};

template<typename T>
void Transform3D::accept_generic(T& _visitor) const {
	_visitor.template type_begin<Transform3D>(5);
	_visitor.type_field("time", 0); _visitor.accept(time);
	_visitor.type_field("time_offset", 1); _visitor.accept(time_offset);
	_visitor.type_field("frame", 2); _visitor.accept(frame);
	_visitor.type_field("parent", 3); _visitor.accept(parent);
	_visitor.type_field("matrix", 4); _visitor.accept(matrix);
	_visitor.template type_end<Transform3D>(5);
}


} // namespace automy
} // namespace basic


namespace vnx {

} // vnx

#endif // INCLUDE_automy_basic_Transform3D_HXX_
