#include "include/Animal.hpp"
#include "include/Cat.hpp"
#include "include/Dog.hpp"

#include <string>

int main()
{
	{
		// subject
		const Animal* j = new Dog();
		std::cout << std::endl;
		const Animal* i = new Cat();
		std::cout << std::endl;

		delete j;//should not create a leak
		std::cout << std::endl;
		delete i;
	}
	// std::cout << "more tests..." << std::endl;
	// {
	// 	Animal	*pets[4];
	// 	// create pets
	// 	for (int i = 0; i < 4; i++) {
	// 		if (i % 2)
	// 			pets[i] = new Dog();
	// 		else
	// 			pets[i] = new Cat();
	// 		std::cout << std::endl;
	// 	}

	// 	pets[3]->makeSound();
	// 	pets[2]->makeSound();
	// 	std::cout << std::endl;

	// 	// delete pets
	// 	for (int i = 0; i < 4; i++) {
	// 		delete pets[i];
	// 		std::cout << std::endl;
	// 	}
	// }
	// std::cout << "deep copies..." << std::endl;
	// {
	// 	Cat *luna = new Cat();
	// 	std::cout << std::endl;

	// 	luna->think("that glass on the table looks fragile...");
	// 	luna->remember();
	// 	Cat *rosie = new Cat(*luna);
	// 	std::cout << std::endl;
	// 	delete luna;
	// 	std::cout << std::endl;
	// 	rosie->remember();// not just copying the pointer
	// 	delete rosie;
	// }
	return (0);
}
