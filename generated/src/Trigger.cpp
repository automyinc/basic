
// AUTO GENERATED by vnxcppcodegen

#include <basic/package.hxx>
#include <basic/Trigger.hxx>
#include <vnx/Input.h>
#include <vnx/Output.h>
#include <vnx/Visitor.h>
#include <vnx/Object.h>
#include <vnx/Struct.h>


namespace basic {


const vnx::Hash64 Trigger::VNX_TYPE_HASH(0xb67bc7d4674a1217ull);
const vnx::Hash64 Trigger::VNX_CODE_HASH(0xc9d9608a0eced687ull);

vnx::Hash64 Trigger::get_type_hash() const {
	return VNX_TYPE_HASH;
}

const char* Trigger::get_type_name() const {
	return "basic.Trigger";
}

std::shared_ptr<Trigger> Trigger::create() {
	return std::make_shared<Trigger>();
}

std::shared_ptr<vnx::Value> Trigger::clone() const {
	return std::make_shared<Trigger>(*this);
}

void Trigger::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void Trigger::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void Trigger::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = get_type_code();
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, time);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, seq_num);
	_visitor.type_end(*_type_code);
}

void Trigger::write(std::ostream& _out) const {
	_out << "{";
	_out << "\"time\": "; vnx::write(_out, time);
	_out << ", \"seq_num\": "; vnx::write(_out, seq_num);
	_out << "}";
}

void Trigger::read(std::istream& _in) {
	std::map<std::string, std::string> _object;
	vnx::read_object(_in, _object);
	for(const auto& _entry : _object) {
		if(_entry.first == "seq_num") {
			vnx::from_string(_entry.second, seq_num);
		} else if(_entry.first == "time") {
			vnx::from_string(_entry.second, time);
		}
	}
}

vnx::Object Trigger::to_object() const {
	vnx::Object _object;
	_object["time"] = time;
	_object["seq_num"] = seq_num;
	return _object;
}

void Trigger::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "seq_num") {
			_entry.second.to(seq_num);
		} else if(_entry.first == "time") {
			_entry.second.to(time);
		}
	}
}

std::ostream& operator<<(std::ostream& _out, const Trigger& _value) {
	_value.write(_out);
	return _out;
}

std::istream& operator>>(std::istream& _in, Trigger& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* Trigger::get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(vnx::Hash64(0xb67bc7d4674a1217ull));
	if(!type_code) {
		type_code = vnx::register_type_code(create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> Trigger::create_type_code() {
	std::shared_ptr<vnx::TypeCode> type_code = std::make_shared<vnx::TypeCode>(true);
	type_code->name = "basic.Trigger";
	type_code->type_hash = vnx::Hash64(0xb67bc7d4674a1217ull);
	type_code->code_hash = vnx::Hash64(0xc9d9608a0eced687ull);
	type_code->is_class = true;
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<Trigger>(); };
	type_code->fields.resize(2);
	{
		vnx::TypeField& field = type_code->fields[0];
		field.name = "time";
		field.code = {8};
	}
	{
		vnx::TypeField& field = type_code->fields[1];
		field.name = "seq_num";
		field.code = {8};
	}
	type_code->build();
	return type_code;
}


} // namespace basic


namespace vnx {

void read(TypeInput& in, ::basic::Trigger& value, const TypeCode* type_code, const uint16_t* code) {
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
	{
		const vnx::TypeField* const _field = type_code->field_map[1];
		if(_field) {
			vnx::read_value(_buf + _field->offset, value.seq_num, _field->code.data());
		}
	}
	for(const vnx::TypeField* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::basic::Trigger& value, const TypeCode* type_code, const uint16_t* code) {
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = vnx::write_type_code<::basic::Trigger>(out);
		vnx::write_class_header<::basic::Trigger>(out);
	}
	if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(16);
	vnx::write_value(_buf + 0, value.time);
	vnx::write_value(_buf + 8, value.seq_num);
}

void read(std::istream& in, ::basic::Trigger& value) {
	value.read(in);
}

void write(std::ostream& out, const ::basic::Trigger& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::basic::Trigger& value) {
	value.accept(visitor);
}

} // vnx
