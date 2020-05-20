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
	set_transform(vnx::clone(transform));
}

void TransformPublisher::main()
{
	set_timer_millis(interval_ms, std::bind(&TransformPublisher::update, this));
	Super::main();
}

void TransformPublisher::set_transform(const std::shared_ptr<const Transform3D>& new_transform)
{
	m_current = new_transform;

	if(m_current) {
		output = domain + "." + m_current->parent + "." + m_current->frame;
		if(both_ways) {
			output_inverse = domain + "." + m_current->frame + "." + m_current->parent;
		}
	} else {
		output.reset();
		output_inverse.reset();
	}
	update();
}

void TransformPublisher::update()
{
	if(m_current) {
		publish(m_current, output);
		if(both_ways) {
			publish(m_current->get_inverse(), output_inverse);
		}
	}
}


} // basic
} // automy
