
#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

#include "log.hpp"
#include "main.hpp"
#include <iostream>
#include <string>

#define TITLE(x) PRINTLN(BOLD_BLUE, \
		"\n---------------------------------", \
		"\n------------ ", x, " ------------", \
		"\n---------------------------------", \
		RESET)

using std::string;

void	subject_test() {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
}

void	equip_limit() {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);

	me->unequip(0);
	me->unequip(1);
	me->unequip(2);
	me->unequip(3);
	me->unequip(4);

	delete src;
	delete me;
}

void	learn_limit() {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());

	src->createMateria("cure");

	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());

	src->createMateria("feur");
	delete src->createMateria("ice");

	delete src;
}

void	use_limit() {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	me->use(0, *me);

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);

	me->use(1, *me);
	me->use(4, *me);

	delete src;
	delete me;
}
int main( void ) {
	TITLE("LEGEND");
	PRINTLN(BG_C_GREY, "AMateria child", RESET);
	PRINTLN(BG_C_BLUE, "MateriaSource", RESET);
	PRINTLN(BG_C_GREEN, "Character", RESET);

	TITLE("Subject test");
	subject_test();

	TITLE("Equip Limit");
	equip_limit();

	TITLE("Learn Limit");
	learn_limit();
	
	TITLE("Use Limit");
	use_limit();
}
