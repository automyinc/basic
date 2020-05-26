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
}

void TransformPublisher::main()
{
	set_timer_millis(interval_ms, std::bind(&TransformPublisher::update, this));
	Super::main();
}

void TransformPublisher::set_transform(const std::shared_ptr<const Transform3D>& new_transform)
{
	for(auto& value : transforms) {
		if(value->frame == new_transform->frame && value->parent == new_transform->parent) {
			value = new_transform;
		}
	}
	transforms.push_back(new_transform);
}

void TransformPublisher::update()
{
	for(auto value : transforms) {
		publish(value, domain + "." + value->parent + "." + value->frame);
		if(both_ways) {
			auto inverse = value->get_inverse();
			publish(inverse, domain + "." + inverse->parent + "." + inverse->frame);
		}
	}
}


} // basic
} // automy
