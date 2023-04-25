#include "Data.hpp"
#include "Serializer.hpp"



int main( void )
{
	Data	d;
	uintptr_t	test;
	Data		*testD;

	d.name = "testi";
	d.number = 5;
	test = Serializer::serialize(&d);
	testD = Serializer::deserialize(test);

	std::cout << "address of d = " << &d << ", serialized test = " << test << ", address of deserialized testD = " << testD << std::endl;
	testD->yell();
}