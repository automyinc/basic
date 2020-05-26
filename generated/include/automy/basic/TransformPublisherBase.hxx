
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_automy_basic_TransformPublisherBase_HXX_
#define INCLUDE_automy_basic_TransformPublisherBase_HXX_

#include <automy/basic/package.hxx>
#include <automy/basic/Transform3D.hxx>
#include <vnx/Module.h>
#include <vnx/Object.h>


namespace automy {
namespace basic {

class TransformPublisherBase : public ::vnx::Module {
public:
	
	::std::string domain = "tf";
	::int32_t interval_ms = 500;
	::vnx::bool_t both_ways = true;
	::std::vector<::vnx::Object> config;
	::std::vector<::std::shared_ptr<const ::automy::basic::Transform3D>> transforms;
	
	typedef ::vnx::Module Super;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	TransformPublisherBase(const std::string& _vnx_name);
	
	vnx::Hash64 get_type_hash() const;
	const char* get_type_name() const;
	const vnx::TypeCode* get_type_code() const;
	
	void read(std::istream& _in);
	void write(std::ostream& _out) const;
	
	void accept(vnx::Visitor& _visitor) const;
	
	vnx::Object to_object() const;
	void from_object(const vnx::Object& object);
	
	friend std::ostream& operator<<(std::ostream& _out, const TransformPublisherBase& _value);
	friend std::istream& operator>>(std::istream& _in, TransformPublisherBase& _value);
	
	static const vnx::TypeCode* static_get_type_code();
	static std::shared_ptr<vnx::TypeCode> static_create_type_code();
	
protected:
	virtual void set_transform(const ::std::shared_ptr<const ::automy::basic::Transform3D>& new_transform) = 0;
	
	void vnx_handle_switch(std::shared_ptr<const ::vnx::Sample> _sample) override;
	std::shared_ptr<vnx::Value> vnx_call_switch(vnx::TypeInput& _in, const vnx::TypeCode* _call_type, const vnx::request_id_t& _request_id) override;
	
private:
	
};


} // namespace automy
} // namespace basic

#endif // INCLUDE_automy_basic_TransformPublisherBase_HXX_
