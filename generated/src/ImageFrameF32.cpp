
// AUTO GENERATED by vnxcppcodegen

#include <automy/basic/package.hxx>
#include <automy/basic/ImageFrameF32.hxx>
#include <automy/basic/ImageF32.hpp>
#include <automy/basic/ImageFrame.hxx>

#include <vnx/vnx.h>


namespace automy {
namespace basic {


const vnx::Hash64 ImageFrameF32::VNX_TYPE_HASH(0x96c857eff6431525ull);
const vnx::Hash64 ImageFrameF32::VNX_CODE_HASH(0x1a8efb77299ca18bull);

vnx::Hash64 ImageFrameF32::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string ImageFrameF32::get_type_name() const {
	return "automy.basic.ImageFrameF32";
}

const vnx::TypeCode* ImageFrameF32::get_type_code() const {
	return automy::basic::vnx_native_type_code_ImageFrameF32;
}

std::shared_ptr<ImageFrameF32> ImageFrameF32::create() {
	return std::make_shared<ImageFrameF32>();
}

std::shared_ptr<vnx::Value> ImageFrameF32::clone() const {
	return std::make_shared<ImageFrameF32>(*this);
}

void ImageFrameF32::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void ImageFrameF32::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void ImageFrameF32::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = automy::basic::vnx_native_type_code_ImageFrameF32;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, time);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, frame);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, format);
	_visitor.type_field(_type_code->fields[3], 3); vnx::accept(_visitor, properties);
	_visitor.type_field(_type_code->fields[4], 4); vnx::accept(_visitor, image);
	_visitor.type_end(*_type_code);
}

void ImageFrameF32::write(std::ostream& _out) const {
	_out << "{\"__type\": \"automy.basic.ImageFrameF32\"";
	_out << ", \"time\": "; vnx::write(_out, time);
	_out << ", \"frame\": "; vnx::write(_out, frame);
	_out << ", \"format\": "; vnx::write(_out, format);
	_out << ", \"properties\": "; vnx::write(_out, properties);
	_out << ", \"image\": "; vnx::write(_out, image);
	_out << "}";
}

void ImageFrameF32::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object ImageFrameF32::to_object() const {
	vnx::Object _object;
	_object["__type"] = "automy.basic.ImageFrameF32";
	_object["time"] = time;
	_object["frame"] = frame;
	_object["format"] = format;
	_object["properties"] = properties;
	_object["image"] = image;
	return _object;
}

void ImageFrameF32::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "format") {
			_entry.second.to(format);
		} else if(_entry.first == "frame") {
			_entry.second.to(frame);
		} else if(_entry.first == "image") {
			_entry.second.to(image);
		} else if(_entry.first == "properties") {
			_entry.second.to(properties);
		} else if(_entry.first == "time") {
			_entry.second.to(time);
		}
	}
}

vnx::Variant ImageFrameF32::get_field(const std::string& _name) const {
	if(_name == "time") {
		return vnx::Variant(time);
	}
	if(_name == "frame") {
		return vnx::Variant(frame);
	}
	if(_name == "format") {
		return vnx::Variant(format);
	}
	if(_name == "properties") {
		return vnx::Variant(properties);
	}
	if(_name == "image") {
		return vnx::Variant(image);
	}
	return vnx::Variant();
}

void ImageFrameF32::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "time") {
		_value.to(time);
	} else if(_name == "frame") {
		_value.to(frame);
	} else if(_name == "format") {
		_value.to(format);
	} else if(_name == "properties") {
		_value.to(properties);
	} else if(_name == "image") {
		_value.to(image);
	} else {
		throw std::logic_error("no such field: '" + _name + "'");
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const ImageFrameF32& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, ImageFrameF32& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* ImageFrameF32::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> ImageFrameF32::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "automy.basic.ImageFrameF32";
	type_code->type_hash = vnx::Hash64(0x96c857eff6431525ull);
	type_code->code_hash = vnx::Hash64(0x1a8efb77299ca18bull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->native_size = sizeof(::automy::basic::ImageFrameF32);
	type_code->parents.resize(1);
	type_code->parents[0] = ::automy::basic::ImageFrame::static_get_type_code();
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<ImageFrameF32>(); };
	type_code->fields.resize(5);
	{
		auto& field = type_code->fields[0];
		field.data_size = 8;
		field.name = "time";
		field.code = {8};
	}
	{
		auto& field = type_code->fields[1];
		field.is_extended = true;
		field.name = "frame";
		field.code = {32};
	}
	{
		auto& field = type_code->fields[2];
		field.is_extended = true;
		field.name = "format";
		field.code = {32};
	}
	{
		auto& field = type_code->fields[3];
		field.is_extended = true;
		field.name = "properties";
		field.code = {13, 3, 32, 17};
	}
	{
		auto& field = type_code->fields[4];
		field.is_extended = true;
		field.name = "image";
		field.code = {22, 3, 9};
	}
	type_code->build();
	return type_code;
}


} // namespace automy
} // namespace basic


namespace vnx {

void read(TypeInput& in, ::automy::basic::ImageFrameF32& value, const TypeCode* type_code, const uint16_t* code) {
	if(code) {
		switch(code[0]) {
			case CODE_OBJECT:
			case CODE_ALT_OBJECT: {
				Object tmp;
				vnx::read(in, tmp, type_code, code);
				value.from_object(tmp);
				return;
			}
			case CODE_DYNAMIC:
			case CODE_ALT_DYNAMIC:
				vnx::read_dynamic(in, value);
				return;
		}
	}
	if(!type_code) {
		vnx::skip(in, type_code, code);
		return;
	}
	if(code) {
		switch(code[0]) {
			case CODE_STRUCT: type_code = type_code->depends[code[1]]; break;
			case CODE_ALT_STRUCT: type_code = type_code->depends[vnx::flip_bytes(code[1])]; break;
			default: {
				vnx::skip(in, type_code, code);
				return;
			}
		}
	}
	const char* const _buf = in.read(type_code->total_field_size);
	if(type_code->is_matched) {
		if(const auto* const _field = type_code->field_map[0]) {
			vnx::read_value(_buf + _field->offset, value.time, _field->code.data());
		}
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 1: vnx::read(in, value.frame, type_code, _field->code.data()); break;
			case 2: vnx::read(in, value.format, type_code, _field->code.data()); break;
			case 3: vnx::read(in, value.properties, type_code, _field->code.data()); break;
			case 4: vnx::read(in, value.image, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::automy::basic::ImageFrameF32& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = automy::basic::vnx_native_type_code_ImageFrameF32;
		out.write_type_code(type_code);
		vnx::write_class_header<::automy::basic::ImageFrameF32>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(8);
	vnx::write_value(_buf + 0, value.time);
	vnx::write(out, value.frame, type_code, type_code->fields[1].code.data());
	vnx::write(out, value.format, type_code, type_code->fields[2].code.data());
	vnx::write(out, value.properties, type_code, type_code->fields[3].code.data());
	vnx::write(out, value.image, type_code, type_code->fields[4].code.data());
}

void read(std::istream& in, ::automy::basic::ImageFrameF32& value) {
	value.read(in);
}

void write(std::ostream& out, const ::automy::basic::ImageFrameF32& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::automy::basic::ImageFrameF32& value) {
	value.accept(visitor);
}

} // vnx
