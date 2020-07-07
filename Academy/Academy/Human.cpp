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
string& Human::set_name(const string& name) {
	return this->name = name;
}
string& Human::set_surname(const string& surname) {
	return this->surname = surname;
}
int Human::set_age(int age) {
	if (age < 0) age = 0;					// если указан возраст со знаком минус то приведем к 0
	return this->age = age;					// запишим результат
}
bool Human::set_gender(bool gender) {
	return this->gender = gender;
}

Human::Human(const string& name, const string& surname, int age, bool gender) {
	set_name(name);
	set_surname(surname);
	set_age(age);
	set_gender(gender);
}

Human::~Human() {
	cout << "Destructor Human" << endl;
}
ostream& operator<<(ostream& out, const Human& other) 
{
	// Делегируем выполнение операции вывода методу print()
	return other.print(out);
}
ostream& Human::print(ostream& out) const {
	out << "Human" << endl;
	cout << "\tName:\t\t" << get_name() << endl;
	cout << "\tSurName:\t" << get_surname() << endl;
	cout << "\tAge:\t\t" << get_age() << " ears" << endl;
	cout << "\tGender:\t\t" << ((get_gender() == true) ? "Male" : "Female") << endl;
	return out;
}

void Human::print() const {
	cout << "\tName:\t\t" << Human::get_name()<< endl;
	cout << "\tSurName:\t" << Human::get_surname() << endl;
	cout << "\tAge:\t\t" << Human::get_age() << endl;
	cout << "\tGender:\t\t" << (Human::get_gender() == true ? "Male" : "Female") << endl;
}

