#include"Header.h"

void main() {

	setlocale(LC_ALL, "");
	Golos golos;

	Cat cat;
	cat.sound();
	Dog dog;
	dog.sound();

	golos.sound(&cat);
	golos.sound(&dog);
}