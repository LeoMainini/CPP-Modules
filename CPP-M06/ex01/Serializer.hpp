#ifndef SERIALIZER_H
#define SERIALIZER_H
#include <stdint.h>

struct Data;

class Serializer{

	public:
		Serializer();
		~Serializer();
		Serializer( const Serializer &s);
		Serializer &operator = (const Serializer &s);
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif