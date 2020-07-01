#include"Header.h"

Human::Human(string& name, string& surname, int age, int gender) {
	this->name = name;
	this->surname = surname;
	this->age = age;
	this->gender = gender;
}

Human::~Human() {
}