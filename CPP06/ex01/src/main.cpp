#include "Serializer.hpp"
#include "libftpp.hpp"
#include <iostream>

int main()
{
	std::cout << pad_line("TESTING SERIALIZER") << std::endl;

	Data myData;
	myData.name = "Super Data";
	myData.value = 42;
	myData.price = 19.99;

	std::cout << "Original Data Address: " << &myData << std::endl;
	std::cout << "Name: " << myData.name << std::endl;
	std::cout << "Value: " << myData.value << std::endl;
	std::cout << "Price: " << myData.price << std::endl;

	std::cout << std::endl << pad_line("SERIALIZATION") << std::endl;
	uintptr_t raw = Serializer::serialize(&myData);
	std::cout << "Serialized value (uintptr_t): " << raw << std::endl;

	std::cout << std::endl << pad_line("DESERIALIZATION") << std::endl;
	Data* deserializedData = Serializer::deserialize(raw);
	std::cout << "Deserialized Data Address: " << deserializedData << std::endl;

	std::cout << std::endl << pad_line("VERIFICATION") << std::endl;
	if (deserializedData == &myData)
	{
		std::cout << "SUCCESS: Pointers match!" << std::endl;
		std::cout << "Name: " << deserializedData->name << std::endl;
		std::cout << "Value: " << deserializedData->value << std::endl;
		std::cout << "Price: " << deserializedData->price << std::endl;
	}
	else
	{
		std::cout << "FAILURE: Pointers do not match!" << std::endl;
	}

	return 0;
}
