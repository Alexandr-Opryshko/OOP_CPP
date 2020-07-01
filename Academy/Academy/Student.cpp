#include"Header.h"

const string& Student::get_group() const {
	return this->group;
}
const double Student::get_rating() const {
	return this->rating;
}
const double Student::get_attendence() const {
	return this->attendence;
}
const string& Student::get_speccialty() const {
	return this->speccialty;
}
string& Student::set_group(string& group) {
	return this->group = group;
}
double Student::set_rating(double rating) {
	if (rating < 0) rating = 0;
	return this->rating = rating;
}
double Student::set_attendence(double attendence) {
	if (attendence < 0) attendence = 0;
	return this->attendence = attendence;
}
string& Student::set_speccialty(string& speccialty) {
	return this->speccialty = speccialty;
}
void Student::print() {
	cout << "\tName:\t\t" << get_name() << endl;
	cout << "\tSurName:\t" << get_surname() << endl;
	cout << "\tAge:\t\t" << get_age() << " ears" << endl;
	cout << "\tGender:\t\t" << ((get_gender() == true) ? "Male" : "Female") << endl;

	cout << "\tGroup:\t\t" << get_group() << endl;
	cout << "\tRating:\t\t" << get_rating() << endl;
	cout << "\tAttendence:\t" << get_attendence() << " %" << endl;
	cout << "\tSpeccialty:\t" << get_speccialty() << endl;
}
Student::Student
(
	string name, 
	string surname, 
	int age, 
	bool gender,
	string group,
	double rating,
	double attendence,
	string speccialty

):Human(name, surname, age, gender)
{
	this->group = set_group(group);
	this->rating = set_rating(rating);
	this->attendence = set_attendence(attendence);
	this->speccialty = set_speccialty(speccialty);
}

Student::~Student() {
}