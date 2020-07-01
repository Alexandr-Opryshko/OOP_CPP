#include"Header.h"

const string& Teacher::get_subject() const {
	return this->subject;
}
const double Teacher::get_experience() const {
	return this->experience;
}
const string& Teacher::get_specialty() const {
	return this->specialty;
}
const bool Teacher::get_evil() const {
	return this->evil;
}

string& Teacher::set_subject(string& subject) {
	return this->subject = subject;
}
double Teacher::set_experience(double experience) {
	return this->experience = experience;
}
string& Teacher::set_specialty(string& specialty) {
	return this->specialty = specialty;
}
bool Teacher::set_evil(bool evil) {
	return this->evil = evil;
}
void Teacher::print() {
	cout << "\tName:\t\t" << get_name() << endl;
	cout << "\tSurName:\t" << get_surname() << endl;
	cout << "\tAge:\t\t" << get_age() << " ears" << endl;
	cout << "\tGender:\t\t" << ((get_gender() == true) ? "Male" : "Female") << endl;

	cout << "\tSubject:\t" << get_subject() << endl;
	cout << "\tExperience:\t" << get_experience() << " ears" << endl;
	cout << "\tSpecialty:\t" << get_specialty() << endl;
	cout << "\tEvil:\t\t" << (get_evil() ? "Evil" : "Not angry") << endl;

	string subject;		// тема
	double experience;	// опыт
	string specialty;	// специальность
	bool evil;			// характер «лой?
}
Teacher::Teacher
(
	string name,
	string surname,
	int age,
	bool gender,
	string subject,
	double experience,
	string specialty,
	bool evil
) :Human(name, surname, age, gender) {
	this->subject = set_subject(subject);
	this->experience = set_experience(experience);
	this->specialty = set_specialty(specialty);

}

Teacher::~Teacher() {
}