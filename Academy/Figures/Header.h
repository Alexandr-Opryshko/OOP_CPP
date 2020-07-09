#pragma once
#include<iostream>
#include<string>
#include<math.h>

using namespace std;


//################################ Некая виртуальная фигура с общими свойствами ################
class Figures {
public:
	virtual void print() = 0;
	
protected:
	int length = 0;			// длина
	int width = 0;			// ширина
	int hieght = 0;			// высота
	int angle = 0;			// угол
	float area = 0;			// площадь
	long perimeter = 0;		// периметр
};

//################################ Фигура "Квадрат" ################
class Square: public Figures {
public:
	void print() override;
	const int get_length() const;
	const int get_width() const;
	const long get_perimeter() const;
	const float get_area() const;
	int set_length(int length);
	int set_width(int width);
	
	Square(int lenght = 0, int width = 0);
	~Square();

private:
	long set_perimeter(long perimeter);
	float set_area(float area);
};

//################################ Фигура "Ромб" ################
class Rhombus : public Figures{
public:
	void print() override;
	const int get_length() const;
	const int get_width() const;
	const int get_angle() const;
	const long get_perimeter() const;
	const float get_area() const;
	int set_length(int length);
	int set_width(int width);
	int set_angle(int angle);
	Rhombus(int side = 0, int angle = 90);
	~Rhombus();

private:
	long set_perimeter(long perimeter);
	float set_area(float area);
	double leftShift;
};

//################################ Фигура "Треугольник" ################
class Triangle : public Figures{
public:
	void print() override;
	const int get_length() const;
	const int get_width() const;
	const int get_hieght() const;
	const int get_angle() const;
	const long get_perimeter() const;
	const float get_area() const;
	int set_length(int length);
	int set_width(int width);
	int set_hieght(int hieght);
	int set_angle(int angle);
	Triangle(int a = 0, int b = 0, int c = 0);
	~Triangle();

private:
	long set_perimeter(long perimeter);
	float set_area(float area);
	
	double leftShift;
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