#include<iostream>
using namespace std;

class Point{
   double x;
   double y;
public:
	double get_x() const{
		return x;
	}
	double get_y() const{
		return y;
	}
	void set_x(double x) {
		this->x = x;
	}
	void set_y(double y) {
		this->y = y;
	}

	// метод
	double distance(Point other) {
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
};


void main() {
	setlocale(LC_ALL, "");
	Point A;

	A.set_x(2);
	A.set_y(3);
	
	cout << A.get_x() << "\t" << A.get_y() << endl;
	Point* pA = &A;
	cout << pA->get_x() << "\t" << pA->get_y() << endl;

	Point B;
	B.set_x(4);
	B.set_y(5);
	cout << "Расстояние от точки А до точки В "<<A.distance(B) << endl;
	cout << "Расстояние от точки B до точки В " << B.distance(A) << endl;
}