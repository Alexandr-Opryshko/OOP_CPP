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

string& Teacher::set_subject(const string& subject) {
	return this->subject = subject;
}
double Teacher::set_experience(double experience) {
	return this->experience = experience;
}
string& Teacher::set_specialty(const string& specialty) {
	return this->specialty = specialty;
}
bool Teacher::set_evil(bool evil) {
	return this->evil = evil;
}
ostream& Teacher::print(ostream& out) const {
	Human::print(out);
	cout << "\tSubject:\t" << get_subject() << endl;
	cout << "\tExperience:\t" << get_experience() << " ears" << endl;
	cout << "\tSpecialty:\t" << get_specialty() << endl;
	cout << "\tEvil:\t\t" << ((get_evil() == true) ? "Evil" : "Not angry") << endl;
	return out;
}
void Teacher::print() const {
	Human::print();

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
	const string& name,
	const string& surname,
	int age,
	bool gender,
	const string& subject,
	double experience,
	const string& specialty,
	bool evil
) :Human(name, surname, age, gender) {
	set_subject(subject);
	set_experience(experience);
	set_specialty(specialty);

}

Teacher::~Teacher() {
	cout << "Destructor Teacher" << endl;
}