
#include"Header.h"



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
	cout << "Расстояние от точки А до точки В " << A.distance(B) << endl;
	cout << "Расстояние от точки B до точки В " << B.distance(A) << endl;
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