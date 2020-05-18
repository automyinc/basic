/*
 * TransformPublisher.h
 *
 *  Created on: May 18, 2020
 *      Author: mad
 */

#ifndef AUTOMY_BASIC_TRANSFORMPUBLISHER_H_
#define AUTOMY_BASIC_TRANSFORMPUBLISHER_H_

#include <automy/basic/TransformPublisherBase.hxx>
#include <automy/basic/Transform3D.hxx>


namespace automy {
namespace basic {

class TransformPublisher : public TransformPublisherBase {
public:
	TransformPublisher(const std::string& _vnx_name);

protected:
	void main() override;

	void set_transform(const std::shared_ptr<const Transform3D>& new_transform) override;

private:
	void update();

private:
	std::shared_ptr<const Transform3D> m_transform;

};


} // basic
} // automy

#endif /* AUTOMY_BASIC_TRANSFORMPUBLISHER_H_ */
