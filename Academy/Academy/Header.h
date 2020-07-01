#pragma once
#include<iostream>
#include<string>
using namespace std;

class Human {
public:
	const string& get_name() const;
	const string& get_surname() const;
	const int get_age() const;
	const int get_gender() const;
	string& set_name(string& name);
	string& set_surname(string& surname);
	int set_age(int age);
	bool set_gender(bool gender);
	void print();
	Human(string name = "-", string surname = "", int age = 0, bool gender = true);
	~Human();

private:
	string name;		// им€
	string surname;		// фамили€
	int age;			// возраст
	bool gender;		// пол try - мужской false - женский
};

class Student : public Human {
public:
	const string& get_group() const;
	const double get_rating() const;
	const double get_attendence() const;
	const string& get_speccialty() const;
	string& set_group(string& group);
	double set_rating(double rating);
	double set_attendence(double attendence);
	string& set_speccialty(string& speccialty);
	void print();
	Student
	(
		string name,
		string surname,
		int age,
		bool gender,
		string group,
		double rating,
		double attendence,
		string speccialty

	);

	~Student();

private:
	string group;		// группа
	double rating;		// рейтинг
	double attendence;	// посещаемость
	string speccialty;	// специальность
};

class Teacher :public Human {
public:
	const string& get_subject() const;
	const double get_experience() const;
	const string& get_specialty() const;
	const bool get_evil() const;

	string& set_subject(string& subject);
	double set_experience(double experience);
	string& set_specialty(string& specialty);
	bool set_evil(bool evil);
	void print();
	Teacher
	(
		string name,
		string surname,
		int age,
		bool gender,
		string subject,
		double experience,
		string specialty,
		bool evil
	);
	~Teacher();

private:
	string subject;		// тема
	double experience;	// опыт
	string specialty;	// специальность
	bool evil;			// характер «лой?
};





