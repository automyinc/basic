
// AUTO GENERATED by vnxcppcodegen

#include <basic/package.hxx>
#include <basic/Transform3D.hxx>
#include <vnx/Input.h>
#include <vnx/Output.h>
#include <vnx/Visitor.h>
#include <vnx/Object.h>
#include <vnx/Struct.h>


namespace basic {


const vnx::Hash64 Transform3D::VNX_TYPE_HASH(0x40e06885f6613c32ull);
const vnx::Hash64 Transform3D::VNX_CODE_HASH(0x53cf2a72de6cd50eull);

vnx::Hash64 Transform3D::get_type_hash() const {
	return VNX_TYPE_HASH;
}

const char* Transform3D::get_type_name() const {
	return "basic.Transform3D";
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
	const vnx::TypeCode* _type_code = get_type_code();
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, time);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, matrix);
	_visitor.type_end(*_type_code);
}

void Transform3D::write(std::ostream& _out) const {
	_out << "{";
	_out << "\"time\": "; vnx::write(_out, time);
	_out << ", \"matrix\": "; vnx::write(_out, matrix);
	_out << "}";
}

void Transform3D::read(std::istream& _in) {
	std::map<std::string, std::string> _object;
	vnx::read_object(_in, _object);
	for(const auto& _entry : _object) {
		if(_entry.first == "matrix") {
			vnx::from_string(_entry.second, matrix);
		} else if(_entry.first == "time") {
			vnx::from_string(_entry.second, time);
		}
	}
}

vnx::Object Transform3D::to_object() const {
	vnx::Object _object;
	_object["time"] = time;
	_object["matrix"] = matrix;
	return _object;
}

void Transform3D::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "matrix") {
			_entry.second.to(matrix);
		} else if(_entry.first == "time") {
			_entry.second.to(time);
		}
	}
}

std::ostream& operator<<(std::ostream& _out, const Transform3D& _value) {
	_value.write(_out);
	return _out;
}

std::istream& operator>>(std::istream& _in, Transform3D& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* Transform3D::get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(vnx::Hash64(0x40e06885f6613c32ull));
	if(!type_code) {
		type_code = vnx::register_type_code(create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> Transform3D::create_type_code() {
	std::shared_ptr<vnx::TypeCode> type_code = std::make_shared<vnx::TypeCode>(true);
	type_code->name = "basic.Transform3D";
	type_code->type_hash = vnx::Hash64(0x40e06885f6613c32ull);
	type_code->code_hash = vnx::Hash64(0x53cf2a72de6cd50eull);
	type_code->is_class = true;
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<Transform3D>(); };
	type_code->fields.resize(2);
	{
		vnx::TypeField& field = type_code->fields[0];
		field.name = "time";
		field.code = {8};
	}
	{
		vnx::TypeField& field = type_code->fields[1];
		field.is_extended = true;
		field.name = "matrix";
		field.code = {21, 2, 4, 4, 10};
	}
	type_code->build();
	return type_code;
}


} // namespace basic


namespace vnx {

void read(TypeInput& in, ::basic::Transform3D& value, const TypeCode* type_code, const uint16_t* code) {
	if(!type_code) {
		throw std::logic_error("read(): type_code == 0");
	}
	if(code) {
		switch(code[0]) {
			case CODE_STRUCT: type_code = type_code->depends[code[1]]; break;
			case CODE_ALT_STRUCT: type_code = type_code->depends[vnx::flip_bytes(code[1])]; break;
			default: vnx::skip(in, type_code, code); return;
		}
	}
	const char* const _buf = in.read(type_code->total_field_size);
	{
		const vnx::TypeField* const _field = type_code->field_map[0];
		if(_field) {
			vnx::read_value(_buf + _field->offset, value.time, _field->code.data());
		}
	}
	for(const vnx::TypeField* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 1: vnx::read(in, value.matrix, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::basic::Transform3D& value, const TypeCode* type_code, const uint16_t* code) {
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = vnx::write_type_code<::basic::Transform3D>(out);
		vnx::write_class_header<::basic::Transform3D>(out);
	}
	if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(8);
	vnx::write_value(_buf + 0, value.time);
	vnx::write(out, value.matrix, type_code, type_code->fields[1].code.data());
}

void read(std::istream& in, ::basic::Transform3D& value) {
	value.read(in);
}

void write(std::ostream& out, const ::basic::Transform3D& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::basic::Transform3D& value) {
	value.accept(visitor);
}

} // vnx
