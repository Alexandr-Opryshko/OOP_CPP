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
	string& set_name(const string& name);
	string& set_surname(const string& surname);
	int set_age(int age);
	bool set_gender(bool gender);
	void print() const;
	Human(const string& name, const string& surname, int age, bool gender);
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
	string& set_group(const string& group);
	double set_rating(double rating);
	double set_attendence(double attendence);
	string& set_speccialty(const string& speccialty);
	void print() const;
	Student
	(
		const string& name,
		const string& surname,
		int age,
		bool gender,
		const string& group,
		double rating,
		double attendence,
		const string& speccialty

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

	string& set_subject(const string& subject);
	double set_experience(double experience);
	string& set_specialty(const string& specialty);
	bool set_evil(bool evil);
	void print() const;
	Teacher
	(
		const string& name,
		const string& surname,
		int age,
		bool gender,
		const string& subject,
		double experience,
		const string& specialty,
		bool evil
	);
	~Teacher();

private:
	string subject;		// тема
	double experience;	// опыт
	string specialty;	// специальность
	bool evil;			// характер «лой?
};

class Graduate : public Student	{
public:
	const string& get_diploma_thema()const;
	string& set_diploma_thema(const string& diploma_thema);
	void print() const;
	Graduate(
		const string& name, const string& surname, int age, bool gender,
		const string& group, double rating, double attendence, const string& speccialty,
		const string& diploma_thema
	);
	Graduate(const Student& stud, const string& diploma_thema);
	~Graduate();

private:
	string diploma_thema;
};







