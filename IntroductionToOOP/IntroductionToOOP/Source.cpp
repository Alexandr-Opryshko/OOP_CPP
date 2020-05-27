#include<iostream>
using namespace std;


class Point {
	double x;
	double y;
public:
	double get_x() const {
		return x;
	}
	double get_y() const {
		return y;
	}
	void set_x(double x) {
		this->x = x;
	}
	void set_y(double y) {
		this->y = y;
	}

	// �����
	double distance(Point other) {
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
	Point(double x = 0, double y = 0) {
		this->x = x;
		this->y = y;
		cout << "Too parametr ����������� :\t" << this << endl;
	}
	// ����������� �����������
	Point(const Point& other) {
		this->x = other.x;
		this->y = other.y;
		cout << "Copy ����������� :\t" << this << endl;
	}
	// ����������� ����������
	void operator = (const Point& other) {
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssigment ����������� :\t" << this << endl;
	}
	~Point() {
		cout << "���������� :\t" << this << endl;
	}
	void Print()const {
		std::cout << "X = " << x << ", Y = " << y << std::endl;
	}
};


void main() {
	setlocale(LC_ALL, "");
	/*
	Point A;

	A.set_x(2);
	A.set_y(3);

	cout << A.get_x() << "\t" << A.get_y() << endl;
	Point* pA = &A;
	cout << pA->get_x() << "\t" << pA->get_y() << endl;

	Point B;
	B.set_x(4);
	B.set_y(5);
	cout << "���������� �� ����� � �� ����� � " << A.distance(B) << endl;
	cout << "���������� �� ����� B �� ����� � " << B.distance(A) << endl;
	*/

	Point A;
	A.Print();

	Point B = 2;
	B.Print();

	Point C(3);
	C.Print();

	Point D(2, 3);
	D.Print();

	Point E = C;
	E.Print();

	Point F;
	F = D;
	F.Print();


}