/*
 * Transform3D.cpp
 *
 *  Created on: May 20, 2020
 *      Author: mad
 */

#include <automy/basic/Transform3D.hxx>


namespace automy {
namespace basic {

std::shared_ptr<const Transform3D> Transform3D::get_inverse() const {
	auto result = vnx::clone(*this);
	result->parent = frame;
	result->frame = parent;
	result->matrix = matrix.inverse();
	return result;
}


} // basic
} // automy
