
// AUTO GENERATED by vnxcppcodegen

#include <automy/basic/package.hxx>
#include <automy/basic/Transform3D.hxx>
#include <automy/math/Matrix4d.hpp>
#include <vnx/Object.hpp>
#include <vnx/TopicPtr.hpp>
#include <vnx/Value.h>

#include <vnx/vnx.h>


namespace automy {
namespace basic {


const vnx::Hash64 Transform3D::VNX_TYPE_HASH(0xe762feb1b334b36dull);
const vnx::Hash64 Transform3D::VNX_CODE_HASH(0x60948882815f1dbeull);

vnx::Hash64 Transform3D::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string Transform3D::get_type_name() const {
	return "automy.basic.Transform3D";
}

const vnx::TypeCode* Transform3D::get_type_code() const {
	return automy::basic::vnx_native_type_code_Transform3D;
}

std::shared_ptr<Transform3D> Transform3D::create() {
	return std::make_shared<Transform3D>();
}

std::shared_ptr<vnx::Value> Transform3D::clone() const {
	return std::make_shared<Transform3D>(*this);
}

void Transform3D::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void Transform3D::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void Transform3D::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = automy::basic::vnx_native_type_code_Transform3D;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, time);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, time_offset);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, frame);
	_visitor.type_field(_type_code->fields[3], 3); vnx::accept(_visitor, parent);
	_visitor.type_field(_type_code->fields[4], 4); vnx::accept(_visitor, matrix);
	_visitor.type_end(*_type_code);
}

void Transform3D::write(std::ostream& _out) const {
	_out << "{\"__type\": \"automy.basic.Transform3D\"";
	_out << ", \"time\": "; vnx::write(_out, time);
	_out << ", \"time_offset\": "; vnx::write(_out, time_offset);
	_out << ", \"frame\": "; vnx::write(_out, frame);
	_out << ", \"parent\": "; vnx::write(_out, parent);
	_out << ", \"matrix\": "; vnx::write(_out, matrix);
	_out << "}";
}

void Transform3D::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object Transform3D::to_object() const {
	vnx::Object _object;
	_object["__type"] = "automy.basic.Transform3D";
	_object["time"] = time;
	_object["time_offset"] = time_offset;
	_object["frame"] = frame;
	_object["parent"] = parent;
	_object["matrix"] = matrix;
	return _object;
}

void Transform3D::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "frame") {
			_entry.second.to(frame);
		} else if(_entry.first == "matrix") {
			_entry.second.to(matrix);
		} else if(_entry.first == "parent") {
			_entry.second.to(parent);
		} else if(_entry.first == "time") {
			_entry.second.to(time);
		} else if(_entry.first == "time_offset") {
			_entry.second.to(time_offset);
		}
	}
}

vnx::Variant Transform3D::get_field(const std::string& _name) const {
	if(_name == "time") {
		return vnx::Variant(time);
	}
	if(_name == "time_offset") {
		return vnx::Variant(time_offset);
	}
	if(_name == "frame") {
		return vnx::Variant(frame);
	}
	if(_name == "parent") {
		return vnx::Variant(parent);
	}
	if(_name == "matrix") {
		return vnx::Variant(matrix);
	}
	return vnx::Variant();
}

void Transform3D::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "time") {
		_value.to(time);
	} else if(_name == "time_offset") {
		_value.to(time_offset);
	} else if(_name == "frame") {
		_value.to(frame);
	} else if(_name == "parent") {
		_value.to(parent);
	} else if(_name == "matrix") {
		_value.to(matrix);
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const Transform3D& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, Transform3D& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* Transform3D::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> Transform3D::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "automy.basic.Transform3D";
	type_code->type_hash = vnx::Hash64(0xe762feb1b334b36dull);
	type_code->code_hash = vnx::Hash64(0x60948882815f1dbeull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->native_size = sizeof(::automy::basic::Transform3D);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<Transform3D>(); };
	type_code->fields.resize(5);
	{
		auto& field = type_code->fields[0];
		field.data_size = 8;
		field.name = "time";
		field.code = {8};
	}
	{
		auto& field = type_code->fields[1];
		field.data_size = 4;
		field.name = "time_offset";
		field.code = {7};
	}
	{
		auto& field = type_code->fields[2];
		field.is_extended = true;
		field.name = "frame";
		field.code = {32};
	}
	{
		auto& field = type_code->fields[3];
		field.is_extended = true;
		field.name = "parent";
		field.code = {32};
	}
	{
		auto& field = type_code->fields[4];
		field.is_extended = true;
		field.name = "matrix";
		field.code = {21, 2, 4, 4, 10};
	}
	type_code->build();
	return type_code;
}

std::shared_ptr<vnx::Value> Transform3D::vnx_call_switch(std::shared_ptr<const vnx::Value> _method) {
	switch(_method->get_type_hash()) {
	}
	return nullptr;
}


} // namespace automy
} // namespace basic


namespace vnx {

void read(TypeInput& in, ::automy::basic::Transform3D& value, const TypeCode* type_code, const uint16_t* code) {
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
	const auto* const _buf = in.read(type_code->total_field_size);
	if(type_code->is_matched) {
		if(const auto* const _field = type_code->field_map[0]) {
			vnx::read_value(_buf + _field->offset, value.time, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[1]) {
			vnx::read_value(_buf + _field->offset, value.time_offset, _field->code.data());
		}
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 2: vnx::read(in, value.frame, type_code, _field->code.data()); break;
			case 3: vnx::read(in, value.parent, type_code, _field->code.data()); break;
			case 4: vnx::read(in, value.matrix, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::automy::basic::Transform3D& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = automy::basic::vnx_native_type_code_Transform3D;
		out.write_type_code(type_code);
		vnx::write_class_header<::automy::basic::Transform3D>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	auto* const _buf = out.write(12);
	vnx::write_value(_buf + 0, value.time);
	vnx::write_value(_buf + 8, value.time_offset);
	vnx::write(out, value.frame, type_code, type_code->fields[2].code.data());
	vnx::write(out, value.parent, type_code, type_code->fields[3].code.data());
	vnx::write(out, value.matrix, type_code, type_code->fields[4].code.data());
}

void read(std::istream& in, ::automy::basic::Transform3D& value) {
	value.read(in);
}

void write(std::ostream& out, const ::automy::basic::Transform3D& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::automy::basic::Transform3D& value) {
	value.accept(visitor);
}

} // vnx
