
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_automy_basic_TransformPublisherBase_HXX_
#define INCLUDE_automy_basic_TransformPublisherBase_HXX_

#include <automy/basic/package.hxx>
#include <automy/basic/Transform3D.hxx>
#include <vnx/Module.h>
#include <vnx/Object.hpp>


namespace automy {
namespace basic {

class TransformPublisherBase : public ::vnx::Module {
public:
	
	std::string domain = "tf";
	int32_t interval_ms = 500;
	std::vector<::vnx::Object> config;
	std::vector<std::shared_ptr<const ::automy::basic::Transform3D>> transforms;
	
	typedef ::vnx::Module Super;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	TransformPublisherBase(const std::string& _vnx_name);
	
	vnx::Hash64 get_type_hash() const override;
	const char* get_type_name() const override;
	const vnx::TypeCode* get_type_code() const override;
	
	void read(std::istream& _in) override;
	void write(std::ostream& _out) const override;
	
	void accept(vnx::Visitor& _visitor) const override;
	
	vnx::Object to_object() const override;
	void from_object(const vnx::Object& object) override;
	
	vnx::Variant get_field(const std::string& name) const override;
	void set_field(const std::string& name, const vnx::Variant& value) override;
	
	friend std::ostream& operator<<(std::ostream& _out, const TransformPublisherBase& _value);
	friend std::istream& operator>>(std::istream& _in, TransformPublisherBase& _value);
	
	static const vnx::TypeCode* static_get_type_code();
	static std::shared_ptr<vnx::TypeCode> static_create_type_code();
	
protected:
	virtual void set_transform(std::shared_ptr<const ::automy::basic::Transform3D> new_transform) = 0;
	
	void vnx_handle_switch(std::shared_ptr<const vnx::Sample> _sample) override;
	std::shared_ptr<vnx::Value> vnx_call_switch(std::shared_ptr<const vnx::Value> _method, const vnx::request_id_t& _request_id) override;
	
};


} // namespace automy
} // namespace basic

#endif // INCLUDE_automy_basic_TransformPublisherBase_HXX_
