#include "Data.hpp"
#include "Serializer.hpp"

using namespace std;

int main( void )
{
	Data	d;
	uintptr_t	test;
	Data		*testD;

	d.name = "testi";
	d.number = 5;
	test = Serializer::serialize(&d);
	testD = Serializer::deserialize(test);

	cout << "address of d = " << &d << ", serialized test = " << test << ", address of deserialized testD = " << testD << endl;
	testD->yell();
}