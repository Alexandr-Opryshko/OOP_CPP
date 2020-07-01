#include"Header.h"

using namespace std;

double Point::get_x() const {
	return x;
}
double Point::get_y() const {
	return y;
}
void Point::set_x(double x) {
	this->x = x;
}
void Point::set_y(double y) {
	this->y = y;
}

// �����
double Point::distance(Point other) {
	double x_distance = this->x - other.x;
	double y_distance = this->y - other.y;
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}
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
Point::Point(double x, double y) {
	this->x = x;
	this->y = y;
	cout << "Too parametr ����������� :\t" << this << endl;
}
// ����������� �����������
Point::Point(const Point& other) {
	this->x = other.x;
	this->y = other.y;
	cout << "Copy ����������� :\t" << this << endl;
}
// ����������� ����������
void Point::operator = (const Point& other) {
	this->x = other.x;
	this->y = other.y;
	cout << "CopyAssigment ����������� :\t" << this << endl;
}
Point::~Point() {
	cout << "���������� :\t" << this << endl;
}
void Point::Print()const {
	std::cout << "X = " << x << ", Y = " << y << std::endl;
}