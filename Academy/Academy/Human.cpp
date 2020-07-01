#include"Header.h"

const string& Human::get_name() const {
	return this->name;
}
const string& Human::get_surname() const {
	return this->surname;
}
const int Human::get_age() const {
	return this->age;
}
const int Human::get_gender() const {
	return this->gender;
}
string& Human::set_name(string& name) {
	return this->name = name;
}
string& Human::set_surname(string& surname) {
	return this->surname = surname;
}
int Human::set_age(int age) {
	if (age < 0) age = 0;					// если указан возраст со знаком минус то приведем к 0
	return this->age = age;					// запишим результат
}
bool Human::set_gender(bool gender) {
	return this->gender = gender;
}

Human::Human(string name, string surname, int age, bool gender) {
	this->name = set_name(name);
	this->surname = set_surname(surname);
	this->age = set_age(age);
	this->gender = set_gender(gender);
}

Human::~Human() {
}

void Human::print() {
	cout << "\tName:\t\t" << Human::get_name()<< endl;
	cout << "\tSurName:\t" << Human::get_surname() << endl;
	cout << "\tAge:\t\t" << Human::get_age() << endl;
	cout << "\tGender:\t\t" << (Human::get_gender() == true ? "Male" : "Female") << endl;
}

