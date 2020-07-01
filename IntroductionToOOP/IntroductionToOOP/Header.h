#pragma once

#include<iostream>
using namespace std;

class Point {
	double x;
	double y;
public:
	double get_x() const;
	double get_y() const;
	void set_x(double x);
	void set_y(double y);

	// метод
	double distance(Point other);
	/*
	Point() {
		x = y = double();
		cout << "default  онструктор :\t" << this << endl;
	}
	Point(double x) {
		this-> x = x;
		this->y = double();
		cout << "One parametr  онструктор :\t" << this << endl;
	}
	*/
	Point(double x = 0, double y = 0);
	// конструктор копировани€
	Point(const Point& other);
	// конструктор присвоени€
	void operator = (const Point& other);
	~Point();
	void Print()const;
};