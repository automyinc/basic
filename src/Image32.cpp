
#include <automy/basic/Image32.hpp>


namespace vnx {

void read(TypeInput& in, ::automy::basic::Image32& value, const TypeCode* type_code, const uint16_t* code) {
	value.read(in, type_code, code);
}

void write(TypeOutput& out, const ::automy::basic::Image32& value, const TypeCode* type_code, const uint16_t* code) {
	value.write(out, type_code, code);
}

void read(std::istream& in, ::automy::basic::Image32& value) {
	value.read(in);
}

void write(std::ostream& out, const ::automy::basic::Image32& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::automy::basic::Image32& value) {
	value.accept(visitor);
}


} // vnx
