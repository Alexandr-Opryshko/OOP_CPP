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

	// �����
	double distance(Point other);
	/*
	Point() {
		x = y = double();
		cout << "default ����������� :\t" << this << endl;
	}
	Point(double x) {
		this-> x = x;
		this->y = double();
		cout << "One parametr ����������� :\t" << this << endl;
	}
	*/
	Point(double x = 0, double y = 0);
	// ����������� �����������
	Point(const Point& other);
	// ����������� ����������
	void operator = (const Point& other);
	~Point();
	void Print()const;
};