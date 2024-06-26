
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_automy_basic_TransformPublisher_CLIENT_HXX_
#define INCLUDE_automy_basic_TransformPublisher_CLIENT_HXX_

#include <vnx/Client.h>
#include <automy/basic/Transform3D.hxx>
#include <vnx/Module.h>
#include <vnx/Object.hpp>


namespace automy {
namespace basic {

class TransformPublisherClient : public vnx::Client {
public:
	TransformPublisherClient(const std::string& service_name);
	
	TransformPublisherClient(vnx::Hash64 service_addr);
	
	void set_transform(std::shared_ptr<const ::automy::basic::Transform3D> new_transform = nullptr);
	
	void set_transform_async(std::shared_ptr<const ::automy::basic::Transform3D> new_transform = nullptr);
	
	::vnx::Object vnx_get_config_object();
	
	::vnx::Variant vnx_get_config(const std::string& name = "");
	
	void vnx_set_config_object(const ::vnx::Object& config = ::vnx::Object());
	
	void vnx_set_config_object_async(const ::vnx::Object& config = ::vnx::Object());
	
	void vnx_set_config(const std::string& name = "", const ::vnx::Variant& value = ::vnx::Variant());
	
	void vnx_set_config_async(const std::string& name = "", const ::vnx::Variant& value = ::vnx::Variant());
	
	::vnx::TypeCode vnx_get_type_code();
	
	std::shared_ptr<const ::vnx::ModuleInfo> vnx_get_module_info();
	
	void vnx_restart();
	
	void vnx_restart_async();
	
	void vnx_stop();
	
	void vnx_stop_async();
	
	vnx::bool_t vnx_self_test();
	
};


} // namespace automy
} // namespace basic

#endif // INCLUDE_automy_basic_TransformPublisher_CLIENT_HXX_
