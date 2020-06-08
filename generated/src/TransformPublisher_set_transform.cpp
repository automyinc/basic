
// AUTO GENERATED by vnxcppcodegen

#include <vnx/vnx.h>
#include <automy/basic/package.hxx>
#include <automy/basic/TransformPublisher_set_transform.hxx>
#include <automy/basic/Transform3D.hxx>
#include <automy/basic/TransformPublisher_set_transform_return.hxx>
#include <vnx/Value.h>



namespace automy {
namespace basic {


const vnx::Hash64 TransformPublisher_set_transform::VNX_TYPE_HASH(0x4b8ec99ea30fd92cull);
const vnx::Hash64 TransformPublisher_set_transform::VNX_CODE_HASH(0x56494e70cb3526dbull);

vnx::Hash64 TransformPublisher_set_transform::get_type_hash() const {
	return VNX_TYPE_HASH;
}

const char* TransformPublisher_set_transform::get_type_name() const {
	return "automy.basic.TransformPublisher.set_transform";
}
const vnx::TypeCode* TransformPublisher_set_transform::get_type_code() const {
	return automy::basic::vnx_native_type_code_TransformPublisher_set_transform;
}

std::shared_ptr<TransformPublisher_set_transform> TransformPublisher_set_transform::create() {
	return std::make_shared<TransformPublisher_set_transform>();
}

std::shared_ptr<vnx::Value> TransformPublisher_set_transform::clone() const {
	return std::make_shared<TransformPublisher_set_transform>(*this);
}

void TransformPublisher_set_transform::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void TransformPublisher_set_transform::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void TransformPublisher_set_transform::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = automy::basic::vnx_native_type_code_TransformPublisher_set_transform;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, new_transform);
	_visitor.type_end(*_type_code);
}

void TransformPublisher_set_transform::write(std::ostream& _out) const {
	_out << "{\"__type\": \"automy.basic.TransformPublisher.set_transform\"";
	_out << ", \"new_transform\": "; vnx::write(_out, new_transform);
	_out << "}";
}

void TransformPublisher_set_transform::read(std::istream& _in) {
	std::map<std::string, std::string> _object;
	vnx::read_object(_in, _object);
	for(const auto& _entry : _object) {
		if(_entry.first == "new_transform") {
			vnx::from_string(_entry.second, new_transform);
		}
	}
}

vnx::Object TransformPublisher_set_transform::to_object() const {
	vnx::Object _object;
	_object["__type"] = "automy.basic.TransformPublisher.set_transform";
	_object["new_transform"] = new_transform;
	return _object;
}

void TransformPublisher_set_transform::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "new_transform") {
			_entry.second.to(new_transform);
		}
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const TransformPublisher_set_transform& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, TransformPublisher_set_transform& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* TransformPublisher_set_transform::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> TransformPublisher_set_transform::static_create_type_code() {
	std::shared_ptr<vnx::TypeCode> type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "automy.basic.TransformPublisher.set_transform";
	type_code->type_hash = vnx::Hash64(0x4b8ec99ea30fd92cull);
	type_code->code_hash = vnx::Hash64(0x56494e70cb3526dbull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->is_method = true;
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<TransformPublisher_set_transform>(); };
	type_code->return_type = ::automy::basic::TransformPublisher_set_transform_return::static_get_type_code();
	type_code->fields.resize(1);
	{
		vnx::TypeField& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "new_transform";
		field.code = {16};
	}
	type_code->build();
	return type_code;
}


} // namespace automy
} // namespace basic


namespace vnx {

void read(TypeInput& in, ::automy::basic::TransformPublisher_set_transform& value, const TypeCode* type_code, const uint16_t* code) {
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
	if(type_code->is_matched) {
	}
	for(const vnx::TypeField* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 0: vnx::read(in, value.new_transform, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::automy::basic::TransformPublisher_set_transform& value, const TypeCode* type_code, const uint16_t* code) {
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = automy::basic::vnx_native_type_code_TransformPublisher_set_transform;
		out.write_type_code(type_code);
		vnx::write_class_header<::automy::basic::TransformPublisher_set_transform>(out);
	}
	if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	vnx::write(out, value.new_transform, type_code, type_code->fields[0].code.data());
}

void read(std::istream& in, ::automy::basic::TransformPublisher_set_transform& value) {
	value.read(in);
}

void write(std::ostream& out, const ::automy::basic::TransformPublisher_set_transform& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::automy::basic::TransformPublisher_set_transform& value) {
	value.accept(visitor);
}

} // vnx