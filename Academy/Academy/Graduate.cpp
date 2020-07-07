#include"Header.h"

const string& Graduate::get_diploma_thema()const {
	return this->diploma_thema;
}
string& Graduate::set_diploma_thema(const string& diploma_thema) {
	return this->diploma_thema = diploma_thema;
}
Graduate::Graduate(
	const string& name, const string& surname, int age, bool gender,
	const string& group, double rating, double attendence, const string& speccialty,
	const string& diploma_thema
) :Student(name, surname, age, gender, group, rating, attendence, speccialty) {
	set_diploma_thema(diploma_thema);
};
ostream& Graduate::print(ostream& out) const {
	cout << "Diploma_thema:\t" << get_diploma_thema() << endl;
	return out;
}
void Graduate::print() const {
	Student::print();
	
	cout << "\tdiploma_thema:\t" << Graduate::get_diploma_thema() << endl;
}
Graduate::Graduate(const Student& stud, const string& diploma_thema) : Student(stud) {
	set_diploma_thema(diploma_thema);
}

Graduate::~Graduate() {
	cout << "Destructor Graduate" << endl;
}