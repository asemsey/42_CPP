#include "include/Animal.hpp"
#include "include/Cat.hpp"
#include "include/Dog.hpp"

int main()
{
	{
		// subject
		const Animal*	meta = new Animal();
		const Animal*	j = new Dog();
		const Animal*	i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}
	// std::cout << "----Wrong Classes:\n";
	// {
	// 	const WrongAnimal*	meta = new WrongAnimal();
	// 	const WrongAnimal*	i = new WrongCat();
	// 	// const WrongCat*		i = new WrongCat();

	// 	std::cout << meta->getType() << " " << std::endl;
	// 	std::cout << i->getType() << " " << std::endl;
	// 	i->makeSound(); //will output the animal sound!
	// 	meta->makeSound();

	// 	delete meta;
	// 	delete i;
	// }
}
