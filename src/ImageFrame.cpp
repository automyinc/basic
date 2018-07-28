 /*************************************************************************
 * 
 *  [2017] - [2018] Automy Inc. 
 *  All Rights Reserved.
 * 
 * NOTICE:  All information contained herein is, and remains
 * the property of Automy Incorporated and its suppliers,
 * if any.  The intellectual and technical concepts contained
 * herein are proprietary to Automy Incorporated
 * and its suppliers and may be covered by U.S. and Foreign Patents,
 * patents in process, and are protected by trade secret or copyright law.
 * Dissemination of this information or reproduction of this material
 * is strictly forbidden unless prior written permission is obtained
 * from Automy Incorporated.
 */

#include <basic/ImageFrame.hxx>


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
