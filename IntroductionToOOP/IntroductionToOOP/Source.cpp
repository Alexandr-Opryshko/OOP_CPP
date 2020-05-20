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
};
class Point3D :public Point {
	double z;
public:
	double get_z() const {
		return z;
	}
	void set_z(double z) {
		this->z = z;
	}
};

void main() {
		
	Point A;
	Point3D B;

	A.set_x(2);
	A.set_y(3);
	B.set_z(20);
	
	cout << A.get_x() << "\t" << A.get_y() << endl;
	Point* pA = &A;
	cout << pA->get_x() << "\t" << pA->get_y() << endl;
	cout << A.get_x() << "\t" << A.get_y() << "\t" << B.get_z() << endl;
}