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

// метод
double Point::distance(Point other) {
	double x_distance = this->x - other.x;
	double y_distance = this->y - other.y;
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}
/*
Point() {
	x = y = double();
	cout << "default Конструктор :\t" << this << endl;
}
Point(double x) {
	this-> x = x;
	this->y = double();
	cout << "One parametr Конструктор :\t" << this << endl;
}
*/
Point::Point(double x, double y) {
	this->x = x;
	this->y = y;
	cout << "Too parametr Конструктор :\t" << this << endl;
}
// конструктор копирования
Point::Point(const Point& other) {
	this->x = other.x;
	this->y = other.y;
	cout << "Copy Конструктор :\t" << this << endl;
}
// конструктор присвоения
void Point::operator = (const Point& other) {
	this->x = other.x;
	this->y = other.y;
	cout << "CopyAssigment Конструктор :\t" << this << endl;
}
Point::~Point() {
	cout << "Деструктор :\t" << this << endl;
}
void Point::Print()const {
	std::cout << "X = " << x << ", Y = " << y << std::endl;
}