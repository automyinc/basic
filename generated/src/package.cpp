
// AUTO GENERATED by vnxcppcodegen

#include <vnx/Topic.h>

#include <basic/DataPacket.hxx>
#include <basic/ImageFrame.hxx>
#include <basic/ImageFrame16.hxx>
#include <basic/ImageFrame32.hxx>
#include <basic/ImageFrame8.hxx>
#include <basic/ImageFrameF32.hxx>
#include <basic/ImageFrameF64.hxx>
#include <basic/MultiImageFrame.hxx>
#include <basic/Scalar.hxx>
#include <basic/Transform3D.hxx>
#include <basic/Trigger.hxx>



namespace basic {


static void register_all_types() {
	vnx::register_type_code(basic::DataPacket::create_type_code());
	vnx::register_type_code(basic::ImageFrame::create_type_code());
	vnx::register_type_code(basic::ImageFrame16::create_type_code());
	vnx::register_type_code(basic::ImageFrame32::create_type_code());
	vnx::register_type_code(basic::ImageFrame8::create_type_code());
	vnx::register_type_code(basic::ImageFrameF32::create_type_code());
	vnx::register_type_code(basic::ImageFrameF64::create_type_code());
	vnx::register_type_code(basic::MultiImageFrame::create_type_code());
	vnx::register_type_code(basic::Scalar::create_type_code());
	vnx::register_type_code(basic::Transform3D::create_type_code());
	vnx::register_type_code(basic::Trigger::create_type_code());
}

static struct vnx_static_init {
	vnx_static_init() {
		register_all_types();
	}
} vnx_static_init_;

} // namespace basic
