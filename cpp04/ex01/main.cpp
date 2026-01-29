
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

void	test_shallow() {
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;
}

void	test_array_delete() {
	const Animal	*list[] = {
		new Dog(),
		new Dog(),
		new Dog(),
		new Dog(),
		new Cat(),
		new Cat(),
		new Cat(),
		new Cat(),
	};

	for (int i = 0; i < 8; i++) {
		delete list[i];
	}
}

void	test_assignements() {
	test_one_assignement(new Animal());
	PRINTLN();
	test_one_assignement(new Dog());
	PRINTLN();
	test_one_assignement(new Cat());
	PRINTLN();
	test_one_assignement(new Brain());
}

void	test_copies() {
	test_one_copy(new Animal());
	PRINTLN();
	test_one_copy(new Dog());
	PRINTLN();
	test_one_copy(new Cat());
	PRINTLN();
	test_one_copy(new Brain());
}

int main( void ) {
	TITLE("Assignements");
	test_assignements();
	
	TITLE("Copies");
	test_copies();

	TITLE("Shallow");
	test_shallow();

	TITLE("Array delete");
	test_array_delete();
}
