
#include <automy/basic/ImageFrame.hxx>


namespace automy {
namespace basic {

::vnx::Variant ImageFrame::get_property(const ::std::string& key) {
	auto iter = properties.find(key);
	if(iter == properties.end()) {
		throw std::invalid_argument("unknown property '" + key + "'");
	}
	return iter->second;
}

::vnx::Variant ImageFrame::get_property_default(const ::std::string& key, const ::vnx::Variant& def_value) {
	auto iter = properties.find(key);
	if(iter == properties.end()) {
		return def_value;
	}
	return iter->second;
}


} // basic
} // automy
