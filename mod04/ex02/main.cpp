#include "include/Animal.hpp"
#include "include/Cat.hpp"
#include "include/Dog.hpp"

#include <string>

int main()
{
	{
		// Animal	test;// compiler error
		Animal	*pets[4];
		// create pets
		pets[0] = new Dog();
		std::cout << std::endl;
		pets[1] = new Dog();
		std::cout << std::endl;
		pets[2] = new Cat();
		std::cout << std::endl;
		pets[3] = new Cat();
		std::cout << std::endl;

		pets[2]->makeSound();
		pets[0]->makeSound();
		std::cout << std::endl;

		// delete pets
		for (int i = 0; i < 4; i++) {
			delete pets[i];
			std::cout << std::endl;
		}
	}
	// std::cout << "deep copies..." << std::endl;
	// {
	// 	Cat	*luna = new Cat();
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
