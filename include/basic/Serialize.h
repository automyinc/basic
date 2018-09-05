
#ifndef BASIC_INCLUDE_BASIC_SERIALIZE_H_
#define BASIC_INCLUDE_BASIC_SERIALIZE_H_

#include <stdint.h>
#include <string.h>


namespace basic {

inline void read(const void* data, int* offset, bool& value) {
	value = *(((const char*)data) + (*offset));
	*offset += 1;
}

inline void read(const void* data, int* offset, int8_t& value) {
	value = *((const int8_t*)(((const char*)data) + (*offset)));
	*offset += 1;
}

inline void read(const void* data, int* offset, int16_t& value) {
	value = *((const int16_t*)(((const char*)data) + (*offset)));
	*offset += 2;
}

inline void read(const void* data, int* offset, int32_t& value) {
	value = *((const int32_t*)(((const char*)data) + (*offset)));
	*offset += 4;
}

inline void read(const void* data, int* offset, int64_t& value) {
	value = *((const int64_t*)(((const char*)data) + (*offset)));
	*offset += 8;
}

inline void read(const void* data, int* offset, uint8_t& value) {
	value = *((const uint8_t*)(((const char*)data) + (*offset)));
	*offset += 1;
}

inline void read(const void* data, int* offset, uint16_t& value) {
	value = *((const uint16_t*)(((const char*)data) + (*offset)));
	*offset += 2;
}

inline void read(const void* data, int* offset, uint32_t& value) {
	value = *((const uint32_t*)(((const char*)data) + (*offset)));
	*offset += 4;
}

inline void read(const void* data, int* offset, uint64_t& value) {
	value = *((const uint64_t*)(((const char*)data) + (*offset)));
	*offset += 8;
}

inline void read(const void* data, int* offset, float& value) {
	value = *((const float*)(((const char*)data) + (*offset)));
	*offset += 4;
}

inline void read(const void* data, int* offset, double& value) {
	value = *((const double*)(((const char*)data) + (*offset)));
	*offset += 8;
}

inline void read_string(const void* data, int* offset, char* string, const size_t dst_length) {
	uint16_t src_length;
	read(data, offset, src_length);
	if(string) {
		const int copy_length = src_length <= dst_length ? src_length : dst_length;
		memcpy(string, ((const char*)data) + (*offset), copy_length);
		string[dst_length - 1] = 0;
	}
	*offset += src_length;
}


inline void write(void* data, int* offset, const bool& value) {
	if(data) {
		*(((char*)data) + (*offset)) = value;
	}
	*offset += 1;
}

inline void write(void* data, int* offset, const int8_t& value) {
	if(data) {
		*((int8_t*)(((char*)data) + (*offset))) = value;
	}
	*offset += 1;
}

inline void write(void* data, int* offset, const int16_t& value) {
	if(data) {
		*((int16_t*)(((char*)data) + (*offset))) = value;
	}
	*offset += 2;
}

inline void write(void* data, int* offset, const int32_t& value) {
	if(data) {
		*((int32_t*)(((char*)data) + (*offset))) = value;
	}
	*offset += 4;
}

inline void write(void* data, int* offset, const int64_t& value) {
	if(data) {
		*((int64_t*)(((char*)data) + (*offset))) = value;
	}
	*offset += 8;
}

inline void write(void* data, int* offset, const uint8_t& value) {
	if(data) {
		*((uint8_t*)(((char*)data) + (*offset))) = value;
	}
	*offset += 1;
}

inline void write(void* data, int* offset, const uint16_t& value) {
	if(data) {
		*((uint16_t*)(((char*)data) + (*offset))) = value;
	}
	*offset += 2;
}

inline void write(void* data, int* offset, const uint32_t& value) {
	if(data) {
		*((uint32_t*)(((char*)data) + (*offset))) = value;
	}
	*offset += 4;
}

inline void write(void* data, int* offset, const uint64_t& value) {
	if(data) {
		*((uint64_t*)(((char*)data) + (*offset))) = value;
	}
	*offset += 8;
}

inline void write(void* data, int* offset, const float& value) {
	if(data) {
		*((float*)(((char*)data) + (*offset))) = value;
	}
	*offset += 4;
}

inline void write(void* data, int* offset, const double& value) {
	if(data) {
		*((double*)(((char*)data) + (*offset))) = value;
	}
	*offset += 8;
}

inline void write_string(void* data, int* offset, const char* string, const size_t src_length) {
	const uint16_t dst_length = src_length < 65536 ? src_length : 65535;
	write(data, offset, dst_length);
	if(data) {
		memcpy(((char*)data) + (*offset), string, dst_length);
	}
	*offset += dst_length;
}


} // basic

#endif /* BASIC_INCLUDE_BASIC_SERIALIZE_H_ */
