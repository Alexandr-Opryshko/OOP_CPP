#pragma once
#include<iostream>

using namespace std;

class Human {
public:
	Human(string& name, string& surname, int age, int gender);
	~Human();

private:
	string name;		// ���
	string surname;		// �������
	int age;			// �������
	int gender;			// ���
};

class Student {
public:
	Student();
	~Student();

private:
	string group;		// ������
	double rating;		// �������
	double attendence;	// ������������
	string speccialty;	// �������������
};

class Teacher {
public:
	Teacher();
	~Teacher();

private:
	string subject;		// ����
	double experience;	// ����
	string specialty;	// �������������
	bool evil;			// �������� ����?
};





