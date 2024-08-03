#include "include/Serializer.hpp"

int	main(void) {
	Data		*data = new Data();
	Data		*copy;
	uintptr_t	raw;

	data->str = "Hello world!";
	raw = Serializer::serialize(data);
	copy = Serializer::deserialize(raw);

	// std::cout << "uintptr_t:\t" << raw << "\n";
	std::cout << "original data:\t" << data->str << " (" << data << ")\n";
	std::cout << "data in copy:\t" << copy->str << " (" << copy << ")\n";
	return (0);
}
