#pragma once
#include<iostream>

using namespace std;


class Animal {
public:
	virtual void sound() = 0;

private:
	int hunger;
};

class Cat :public Animal{
public:
	void sound() override{
		cout << "ּÿף...." << endl;
	}
private:

};
class Dog :public Animal{
public:
	void sound() override{
		cout << "ֳאג...." << endl;
	}
private:
	int evil;
};

class Golos {
public:
	void sound(Animal* animal) {
		animal->sound();
	}

private:

};
