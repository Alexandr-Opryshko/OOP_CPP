#pragma once
#include<iostream>
#include<string>

using namespace std;

class Figures {
public:
	virtual void print() = 0;;

private:

};

class Square:Figures {
public:
	void print() override;
	const int get_length() const;
	const int get_width() const;
	int set_length(int length);
	int set_width(int width);
	Square(int lenght = 0, int width = 0);
	~Square();

private:
	int length;
	int width;
};






class Object {
public:
	void print(Figures* obj) {
		obj->print();
	}

private:

};