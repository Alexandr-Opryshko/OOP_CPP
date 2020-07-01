#pragma once
#include<iostream>

using namespace std;

class Human {
public:
	Human(string& name, string& surname, int age, int gender);
	~Human();

private:
	string name;		// имя
	string surname;		// фамилия
	int age;			// возраст
	int gender;			// пол
};

class Student {
public:
	Student();
	~Student();

private:
	string group;		// группа
	double rating;		// рейтинг
	double attendence;	// посещаемость
	string speccialty;	// специальность
};

class Teacher {
public:
	Teacher();
	~Teacher();

private:
	string subject;		// тема
	double experience;	// опыт
	string specialty;	// специальность
	bool evil;			// характер Злой?
};





