#include "include/MateriaSource.hpp"
#include "include/Ice.hpp"
#include "include/Cure.hpp"
#include "include/Character.hpp"
#include <iostream>

int	main()
{
	{
		//subject
		IMateriaSource*	src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter*		me = new Character("me");
		AMateria*		tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter*		bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}
	// {
	// 	AMateria		*m;
	// 	IMateriaSource*	src = new MateriaSource();
	// 	src->learnMateria(new Ice());
	// 	src->learnMateria(new Cure());
	// 	src->learnMateria(new Ice());

	// 	//ICharacter does not have showPockets function -> use Character
	// 	ICharacter		*link = new Character("Link");
	// 	ICharacter		*ganon = new Character("Ganon");

	// 	link->use(0, *ganon);//---use unset Materia
	// 	m = src->createMateria("unknown");//---unknown Materia
	// 	link->equip(m);
	// 	for (int i = 0; i < 5; i++)
	// 		link->equip(src->createMateria("cure"));//---too many
	// 	// link->showPockets();
	// 	link->use(0, *ganon);
	// 	link->use(1, *link);

	// 	link->unequip(4);//---out of range index
	// 	link->unequip(1);
	// 	link->unequip(1);
	// 	// link->showPockets();
	// 	m = src->createMateria("ice");
	// 	link->equip(m);
	// 	link->equip(m);//---already set
	// 	// link->showPockets();

	// 	delete ganon;
	// 	delete link;
	// 	delete src;
	// }
	return 0;
}
