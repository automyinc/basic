
// AUTO GENERATED by vnxcppcodegen

#include <automy/basic/DataPacket.hxx>
#include <automy/basic/ImageFrame.hxx>
#include <automy/basic/ImageFrame16.hxx>
#include <automy/basic/ImageFrame32.hxx>
#include <automy/basic/ImageFrame8.hxx>
#include <automy/basic/ImageFrameF16.hxx>
#include <automy/basic/ImageFrameF32.hxx>
#include <automy/basic/ImageFrameF64.hxx>
#include <automy/basic/MultiImageFrame.hxx>
#include <automy/basic/Scalar.hxx>
#include <automy/basic/Transform3D.hxx>
#include <automy/basic/TransformPublisherBase.hxx>
#include <automy/basic/TransformPublisher_set_transform.hxx>
#include <automy/basic/TransformPublisher_set_transform_return.hxx>
#include <automy/basic/Trigger.hxx>
#include <automy/basic/Image16.hpp>
#include <automy/basic/Image32.hpp>
#include <automy/basic/Image8.hpp>
#include <automy/basic/ImageF32.hpp>
#include <automy/basic/ImageF64.hpp>

#include <automy/basic/package.hxx>
#include <vnx/vnx.h>



namespace vnx {

const TypeCode* type<::automy::basic::DataPacket>::get_type_code() {
	return automy::basic::vnx_native_type_code_DataPacket;
}

void type<::automy::basic::DataPacket>::create_dynamic_code(std::vector<uint16_t>& code) {
	create_dynamic_code(code, ::automy::basic::DataPacket());
}

void type<::automy::basic::DataPacket>::create_dynamic_code(std::vector<uint16_t>& code, const ::automy::basic::DataPacket& value, bool special) {
	code.push_back(CODE_OBJECT);
}

const TypeCode* type<::automy::basic::Image16>::get_type_code() {
	return nullptr;
}

void type<::automy::basic::Image16>::create_dynamic_code(std::vector<uint16_t>& code) {
	create_dynamic_code(code, ::automy::basic::Image16());
}

void type<::automy::basic::Image16>::create_dynamic_code(std::vector<uint16_t>& code, const ::automy::basic::Image16& value, bool special) {
	const std::vector<int> tmp = {22, 3, 2};
	code.insert(code.end(), tmp.begin(), tmp.end());}

const TypeCode* type<::automy::basic::Image32>::get_type_code() {
	return nullptr;
}

void type<::automy::basic::Image32>::create_dynamic_code(std::vector<uint16_t>& code) {
	create_dynamic_code(code, ::automy::basic::Image32());
}

void type<::automy::basic::Image32>::create_dynamic_code(std::vector<uint16_t>& code, const ::automy::basic::Image32& value, bool special) {
	const std::vector<int> tmp = {22, 3, 3};
	code.insert(code.end(), tmp.begin(), tmp.end());}

const TypeCode* type<::automy::basic::Image8>::get_type_code() {
	return nullptr;
}

void type<::automy::basic::Image8>::create_dynamic_code(std::vector<uint16_t>& code) {
	create_dynamic_code(code, ::automy::basic::Image8());
}

void type<::automy::basic::Image8>::create_dynamic_code(std::vector<uint16_t>& code, const ::automy::basic::Image8& value, bool special) {
	const std::vector<int> tmp = {22, 3, 1};
	code.insert(code.end(), tmp.begin(), tmp.end());}

const TypeCode* type<::automy::basic::ImageF32>::get_type_code() {
	return nullptr;
}

void type<::automy::basic::ImageF32>::create_dynamic_code(std::vector<uint16_t>& code) {
	create_dynamic_code(code, ::automy::basic::ImageF32());
}

void type<::automy::basic::ImageF32>::create_dynamic_code(std::vector<uint16_t>& code, const ::automy::basic::ImageF32& value, bool special) {
	const std::vector<int> tmp = {22, 3, 9};
	code.insert(code.end(), tmp.begin(), tmp.end());}

const TypeCode* type<::automy::basic::ImageF64>::get_type_code() {
	return nullptr;
}

void type<::automy::basic::ImageF64>::create_dynamic_code(std::vector<uint16_t>& code) {
	create_dynamic_code(code, ::automy::basic::ImageF64());
}

void type<::automy::basic::ImageF64>::create_dynamic_code(std::vector<uint16_t>& code, const ::automy::basic::ImageF64& value, bool special) {
	const std::vector<int> tmp = {22, 3, 10};
	code.insert(code.end(), tmp.begin(), tmp.end());}

const TypeCode* type<::automy::basic::ImageFrame>::get_type_code() {
	return automy::basic::vnx_native_type_code_ImageFrame;
}

void type<::automy::basic::ImageFrame>::create_dynamic_code(std::vector<uint16_t>& code) {
	create_dynamic_code(code, ::automy::basic::ImageFrame());
}

void type<::automy::basic::ImageFrame>::create_dynamic_code(std::vector<uint16_t>& code, const ::automy::basic::ImageFrame& value, bool special) {
	code.push_back(CODE_OBJECT);
}

const TypeCode* type<::automy::basic::ImageFrame16>::get_type_code() {
	return automy::basic::vnx_native_type_code_ImageFrame16;
}

void type<::automy::basic::ImageFrame16>::create_dynamic_code(std::vector<uint16_t>& code) {
	create_dynamic_code(code, ::automy::basic::ImageFrame16());
}

void type<::automy::basic::ImageFrame16>::create_dynamic_code(std::vector<uint16_t>& code, const ::automy::basic::ImageFrame16& value, bool special) {
	code.push_back(CODE_OBJECT);
}

const TypeCode* type<::automy::basic::ImageFrame32>::get_type_code() {
	return automy::basic::vnx_native_type_code_ImageFrame32;
}

void type<::automy::basic::ImageFrame32>::create_dynamic_code(std::vector<uint16_t>& code) {
	create_dynamic_code(code, ::automy::basic::ImageFrame32());
}

void type<::automy::basic::ImageFrame32>::create_dynamic_code(std::vector<uint16_t>& code, const ::automy::basic::ImageFrame32& value, bool special) {
	code.push_back(CODE_OBJECT);
}

const TypeCode* type<::automy::basic::ImageFrame8>::get_type_code() {
	return automy::basic::vnx_native_type_code_ImageFrame8;
}

void type<::automy::basic::ImageFrame8>::create_dynamic_code(std::vector<uint16_t>& code) {
	create_dynamic_code(code, ::automy::basic::ImageFrame8());
}

void type<::automy::basic::ImageFrame8>::create_dynamic_code(std::vector<uint16_t>& code, const ::automy::basic::ImageFrame8& value, bool special) {
	code.push_back(CODE_OBJECT);
}

const TypeCode* type<::automy::basic::ImageFrameF16>::get_type_code() {
	return automy::basic::vnx_native_type_code_ImageFrameF16;
}

void type<::automy::basic::ImageFrameF16>::create_dynamic_code(std::vector<uint16_t>& code) {
	create_dynamic_code(code, ::automy::basic::ImageFrameF16());
}

void type<::automy::basic::ImageFrameF16>::create_dynamic_code(std::vector<uint16_t>& code, const ::automy::basic::ImageFrameF16& value, bool special) {
	code.push_back(CODE_OBJECT);
}

const TypeCode* type<::automy::basic::ImageFrameF32>::get_type_code() {
	return automy::basic::vnx_native_type_code_ImageFrameF32;
}

void type<::automy::basic::ImageFrameF32>::create_dynamic_code(std::vector<uint16_t>& code) {
	create_dynamic_code(code, ::automy::basic::ImageFrameF32());
}

void type<::automy::basic::ImageFrameF32>::create_dynamic_code(std::vector<uint16_t>& code, const ::automy::basic::ImageFrameF32& value, bool special) {
	code.push_back(CODE_OBJECT);
}

const TypeCode* type<::automy::basic::ImageFrameF64>::get_type_code() {
	return automy::basic::vnx_native_type_code_ImageFrameF64;
}

void type<::automy::basic::ImageFrameF64>::create_dynamic_code(std::vector<uint16_t>& code) {
	create_dynamic_code(code, ::automy::basic::ImageFrameF64());
}

void type<::automy::basic::ImageFrameF64>::create_dynamic_code(std::vector<uint16_t>& code, const ::automy::basic::ImageFrameF64& value, bool special) {
	code.push_back(CODE_OBJECT);
}

const TypeCode* type<::automy::basic::MultiImageFrame>::get_type_code() {
	return automy::basic::vnx_native_type_code_MultiImageFrame;
}

void type<::automy::basic::MultiImageFrame>::create_dynamic_code(std::vector<uint16_t>& code) {
	create_dynamic_code(code, ::automy::basic::MultiImageFrame());
}

void type<::automy::basic::MultiImageFrame>::create_dynamic_code(std::vector<uint16_t>& code, const ::automy::basic::MultiImageFrame& value, bool special) {
	code.push_back(CODE_OBJECT);
}

const TypeCode* type<::automy::basic::Scalar>::get_type_code() {
	return automy::basic::vnx_native_type_code_Scalar;
}

void type<::automy::basic::Scalar>::create_dynamic_code(std::vector<uint16_t>& code) {
	create_dynamic_code(code, ::automy::basic::Scalar());
}

void type<::automy::basic::Scalar>::create_dynamic_code(std::vector<uint16_t>& code, const ::automy::basic::Scalar& value, bool special) {
	code.push_back(CODE_OBJECT);
}

const TypeCode* type<::automy::basic::Transform3D>::get_type_code() {
	return automy::basic::vnx_native_type_code_Transform3D;
}

void type<::automy::basic::Transform3D>::create_dynamic_code(std::vector<uint16_t>& code) {
	create_dynamic_code(code, ::automy::basic::Transform3D());
}

void type<::automy::basic::Transform3D>::create_dynamic_code(std::vector<uint16_t>& code, const ::automy::basic::Transform3D& value, bool special) {
	code.push_back(CODE_OBJECT);
}

const TypeCode* type<::automy::basic::TransformPublisher_set_transform>::get_type_code() {
	return automy::basic::vnx_native_type_code_TransformPublisher_set_transform;
}

void type<::automy::basic::TransformPublisher_set_transform>::create_dynamic_code(std::vector<uint16_t>& code) {
	create_dynamic_code(code, ::automy::basic::TransformPublisher_set_transform());
}

void type<::automy::basic::TransformPublisher_set_transform>::create_dynamic_code(std::vector<uint16_t>& code, const ::automy::basic::TransformPublisher_set_transform& value, bool special) {
	code.push_back(CODE_OBJECT);
}

const TypeCode* type<::automy::basic::TransformPublisher_set_transform_return>::get_type_code() {
	return automy::basic::vnx_native_type_code_TransformPublisher_set_transform_return;
}

void type<::automy::basic::TransformPublisher_set_transform_return>::create_dynamic_code(std::vector<uint16_t>& code) {
	create_dynamic_code(code, ::automy::basic::TransformPublisher_set_transform_return());
}

void type<::automy::basic::TransformPublisher_set_transform_return>::create_dynamic_code(std::vector<uint16_t>& code, const ::automy::basic::TransformPublisher_set_transform_return& value, bool special) {
	code.push_back(CODE_OBJECT);
}

const TypeCode* type<::automy::basic::Trigger>::get_type_code() {
	return automy::basic::vnx_native_type_code_Trigger;
}

void type<::automy::basic::Trigger>::create_dynamic_code(std::vector<uint16_t>& code) {
	create_dynamic_code(code, ::automy::basic::Trigger());
}

void type<::automy::basic::Trigger>::create_dynamic_code(std::vector<uint16_t>& code, const ::automy::basic::Trigger& value, bool special) {
	code.push_back(CODE_OBJECT);
}


} // namespace vnx


namespace automy {
namespace basic {


void register_all_types() {
	vnx::register_type_code(::automy::basic::DataPacket::static_create_type_code());
	vnx::register_type_code(::automy::basic::ImageFrame::static_create_type_code());
	vnx::register_type_code(::automy::basic::ImageFrame16::static_create_type_code());
	vnx::register_type_code(::automy::basic::ImageFrame32::static_create_type_code());
	vnx::register_type_code(::automy::basic::ImageFrame8::static_create_type_code());
	vnx::register_type_code(::automy::basic::ImageFrameF16::static_create_type_code());
	vnx::register_type_code(::automy::basic::ImageFrameF32::static_create_type_code());
	vnx::register_type_code(::automy::basic::ImageFrameF64::static_create_type_code());
	vnx::register_type_code(::automy::basic::MultiImageFrame::static_create_type_code());
	vnx::register_type_code(::automy::basic::Scalar::static_create_type_code());
	vnx::register_type_code(::automy::basic::Transform3D::static_create_type_code());
	vnx::register_type_code(::automy::basic::TransformPublisherBase::static_create_type_code());
	vnx::register_type_code(::automy::basic::TransformPublisher_set_transform::static_create_type_code());
	vnx::register_type_code(::automy::basic::TransformPublisher_set_transform_return::static_create_type_code());
	vnx::register_type_code(::automy::basic::Trigger::static_create_type_code());
}

static struct vnx_static_init {
	vnx_static_init() {
		register_all_types();
	}
} vnx_static_init_;

const vnx::TypeCode* const vnx_native_type_code_DataPacket = vnx::get_type_code(vnx::Hash64(0x2d5e2711cbd04ea0ull));
const vnx::TypeCode* const vnx_native_type_code_ImageFrame = vnx::get_type_code(vnx::Hash64(0xad5b897ca145c94eull));
const vnx::TypeCode* const vnx_native_type_code_ImageFrame16 = vnx::get_type_code(vnx::Hash64(0x6f04dc915f2801b0ull));
const vnx::TypeCode* const vnx_native_type_code_ImageFrame32 = vnx::get_type_code(vnx::Hash64(0xbd06ec311906bd99ull));
const vnx::TypeCode* const vnx_native_type_code_ImageFrame8 = vnx::get_type_code(vnx::Hash64(0x724ec7ab579fa982ull));
const vnx::TypeCode* const vnx_native_type_code_ImageFrameF16 = vnx::get_type_code(vnx::Hash64(0x44ca674fb06da90cull));
const vnx::TypeCode* const vnx_native_type_code_ImageFrameF32 = vnx::get_type_code(vnx::Hash64(0x96c857eff6431525ull));
const vnx::TypeCode* const vnx_native_type_code_ImageFrameF64 = vnx::get_type_code(vnx::Hash64(0x8c0892cc2111c0f1ull));
const vnx::TypeCode* const vnx_native_type_code_MultiImageFrame = vnx::get_type_code(vnx::Hash64(0x5ee9279d2299dc0dull));
const vnx::TypeCode* const vnx_native_type_code_Scalar = vnx::get_type_code(vnx::Hash64(0xc0b8bdb61e0ca70eull));
const vnx::TypeCode* const vnx_native_type_code_Transform3D = vnx::get_type_code(vnx::Hash64(0xe762feb1b334b36dull));
const vnx::TypeCode* const vnx_native_type_code_TransformPublisherBase = vnx::get_type_code(vnx::Hash64(0x88d77b971994875dull));
const vnx::TypeCode* const vnx_native_type_code_TransformPublisher_set_transform = vnx::get_type_code(vnx::Hash64(0x4b8ec99ea30fd92cull));
const vnx::TypeCode* const vnx_native_type_code_TransformPublisher_set_transform_return = vnx::get_type_code(vnx::Hash64(0x2798b4f2ee70b0a4ull));
const vnx::TypeCode* const vnx_native_type_code_Trigger = vnx::get_type_code(vnx::Hash64(0xae5ff291c2d59cceull));

} // namespace automy
} // namespace basic
