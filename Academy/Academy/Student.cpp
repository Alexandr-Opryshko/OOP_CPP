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
string& Student::set_group(const string& group) {
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
string& Student::set_speccialty(const string& speccialty) {
	return this->speccialty = speccialty;
}
void Student::print() const{
	Human::print();

	cout << "\tGroup:\t\t" << get_group() << endl;
	cout << "\tRating:\t\t" << get_rating() << endl;
	cout << "\tAttendence:\t" << get_attendence() << " %" << endl;
	cout << "\tSpeccialty:\t" << get_speccialty() << endl;
}
Student::Student
(
	const string& name, 
	const string& surname,
	int age, 
	bool gender,
	const string& group,
	double rating,
	double attendence,
	const string& speccialty

):Human(name, surname, age, gender)
{
	set_group(group);
	set_rating(rating);
	set_attendence(attendence);
	set_speccialty(speccialty);
}

Student::~Student() {
}