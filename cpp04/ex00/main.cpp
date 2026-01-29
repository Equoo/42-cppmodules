
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
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


void	test_assignements() {
	test_one_assignement(new Animal());
	PRINTLN();
	test_one_assignement(new Dog());
	PRINTLN();
	test_one_assignement(new Cat());
}

void	test_copies() {
	test_one_copy(new Animal());
	PRINTLN();
	test_one_copy(new Dog());
	PRINTLN();
	test_one_copy(new Cat());
}

void	test_animal_makesound() {	
		const Animal	*list[] = {
			new Animal(),
			new Dog(),
			new Cat()
		};

		for (int i = 0; i < 3; i++) {
			PRINTLN(BOLD_WHITE, "MakeSound: ", list[i]->getType(), RESET);
			list[i]->makeSound();
			delete list[i];
		}
}

void	test_wronganimal_makesound() {
	const WrongAnimal	*list[] = {
		new WrongAnimal(),
		new WrongCat()
	};

	for (int i = 0; i < 2; i++) {
		PRINTLN(BOLD_WHITE, "MakeSound: ", list[i]->getType(), RESET);
		list[i]->makeSound();
		delete list[i];
	}
}

int main( void ) {
	TITLE("Assignements");
	test_assignements();

	TITLE("Animal MakeSound");
	test_animal_makesound();

	TITLE("WrongAnimal MakeSound");
	test_wronganimal_makesound();
}
