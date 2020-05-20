/*
 * TransformPublisher.cpp
 *
 *  Created on: May 18, 2020
 *      Author: mad
 */

#include <automy/basic/TransformPublisher.h>


namespace automy {
namespace basic {

TransformPublisher::TransformPublisher(const std::string& _vnx_name)
	:	TransformPublisherBase(_vnx_name)
{
	m_transform = vnx::clone(transform);
}

void TransformPublisher::main() {
	set_timer_millis(interval_ms, std::bind(&TransformPublisher::update, this));
	Super::main();
}

void TransformPublisher::set_transform(const std::shared_ptr<const Transform3D>& new_transform) {
	m_transform = new_transform;
	update();
}

void TransformPublisher::update() {
	if(m_transform) {
		publish(m_transform, domain + "." + m_transform->parent + "." + m_transform->frame);
		if(both_ways) {
			auto inverse = m_transform->get_inverse();
			publish(inverse, domain + "." + inverse->parent + "." + inverse->frame);
		}
	}
}


} // basic
} // automy
