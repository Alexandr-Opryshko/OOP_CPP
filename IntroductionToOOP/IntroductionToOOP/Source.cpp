#include<iostream>
using namespace std;
/*
struct Point {

	double x;
	double y;
};
*/
class Point{
public:
   double x;
   double y;
};

void main() {
	Point A;
	
	A.x = 2;
	A.y = 3;
	Point* pa = &A;
	cout << pa->x << "\t" << pa->y << endl;
	cout << A.x << "\t" << A.y << endl;

}