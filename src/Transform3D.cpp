/*
 * Transform3D.cpp
 *
 *  Created on: May 20, 2020
 *      Author: mad
 */

#include <automy/basic/Transform3D.hxx>
#include <automy/math/Math3D.h>


namespace automy {
namespace basic {

std::shared_ptr<const Transform3D> Transform3D::get_inverse() const {
	auto result = vnx::clone(*this);
	result->parent = frame;
	result->frame = parent;
	result->matrix = matrix.inverse();
	return result;
}

std::shared_ptr<const Transform3D> Transform3D::from_config(const vnx::Object& config) {
	auto result = Transform3D::create();
	result->frame = config["frame"].to_string_value();
	result->parent = config["parent"].to_string_value();
	if(config.field.count("offset_xyz") || config.field.count("rotation_rpy") || config.field.count("rotation_rpy_deg")) {
		const auto offset = config["offset_xyz"].to<math::Vector3d>();
		math::Vector3d rotation;
		if(config.field.count("rotation_rpy_deg")) {
			const auto tmp = config["rotation_rpy_deg"].to<math::Vector3d>();
			rotation = tmp * M_PI / 180;
		} else {
			rotation = config["rotation_rpy"].to<math::Vector3d>();
		}
		result->matrix = math::translate3(offset) * math::rotate3_xyz_intrinsic(rotation);
	} else {
		result->matrix = config["matrix"].to<math::Matrix4d>();
	}
	return result;
}


} // basic
} // automy
