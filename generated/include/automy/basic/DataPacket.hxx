
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_automy_basic_DataPacket_HXX_
#define INCLUDE_automy_basic_DataPacket_HXX_

#include <automy/basic/package.hxx>
#include <vnx/Value.h>


namespace automy {
namespace basic {

class AUTOMY_BASIC_EXPORT DataPacket : public ::vnx::Value {
public:
	
	int64_t time = 0;
	std::vector<uint8_t> payload;
	
	typedef ::vnx::Value Super;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	static constexpr uint64_t VNX_TYPE_ID = 0x2d5e2711cbd04ea0ull;
	
	DataPacket() {}
	
	vnx::Hash64 get_type_hash() const override;
	std::string get_type_name() const override;
	const vnx::TypeCode* get_type_code() const override;
	
	static std::shared_ptr<DataPacket> create();
	std::shared_ptr<vnx::Value> clone() const override;
	
	void read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) override;
	void write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const override;
	
	void read(std::istream& _in) override;
	void write(std::ostream& _out) const override;
	
	template<typename T>
	void accept_generic(T& _visitor) const;
	void accept(vnx::Visitor& _visitor) const override;
	
	vnx::Object to_object() const override;
	void from_object(const vnx::Object& object) override;
	
	vnx::Variant get_field(const std::string& name) const override;
	void set_field(const std::string& name, const vnx::Variant& value) override;
	
	friend std::ostream& operator<<(std::ostream& _out, const DataPacket& _value);
	friend std::istream& operator>>(std::istream& _in, DataPacket& _value);
	
	static const vnx::TypeCode* static_get_type_code();
	static std::shared_ptr<vnx::TypeCode> static_create_type_code();
	
protected:
	std::shared_ptr<vnx::Value> vnx_call_switch(std::shared_ptr<const vnx::Value> _method) override;
	
};

template<typename T>
void DataPacket::accept_generic(T& _visitor) const {
	_visitor.template type_begin<DataPacket>(2);
	_visitor.type_field("time", 0); _visitor.accept(time);
	_visitor.type_field("payload", 1); _visitor.accept(payload);
	_visitor.template type_end<DataPacket>(2);
}


} // namespace automy
} // namespace basic


namespace vnx {

} // vnx

#endif // INCLUDE_automy_basic_DataPacket_HXX_
