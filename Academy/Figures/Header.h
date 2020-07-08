#pragma once
#include<iostream>
#include<string>

using namespace std;


//################################ Некая виртуальная фигура с общими свойствами ################
class Figures {
public:
	virtual void print() = 0;
	
protected:
	long area;
	long perimeter;
};

//################################ Фигура "Квадрат" ################
class Square: public Figures {
public:
	void print() override;
	const int get_length() const;
	const int get_width() const;
	const long get_perimeter() const;
	const long get_area() const;
	int set_length(int length);
	int set_width(int width);
	
	Square(int lenght = 0, int width = 0);
	~Square();

private:
	long set_perimeter(long perimeter);
	long set_area(long area);
	int length;
	int width;
};

//################################


//################################ Объект получающий в виде параметров конкретную  фигуру ################
class Object {
public:

	void print(Figures* obj) {
		obj->print();
	}

private:

};