#include "Serializer.hpp"

int	main( void ) {
	Data *ptr = new Data;
	ptr->name = "Bob";
	ptr->age = 42;

	uintptr_t raw = Serializer::serialize(ptr);
	Data *serialized = Serializer::deserialize(raw);

	std::cout << serialized->name << std::endl;
	std::cout << serialized->age << std::endl;

	delete ptr;

	return (0);
}