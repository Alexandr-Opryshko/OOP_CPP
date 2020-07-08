#include"Header.h"

//#################################################################################################
void Square::print() {
	cout << endl;
	for (int i = 0; i < this->length; i++) {
		cout << "\t";
		if ((i == 0) || (i == this->length - 1)) 
		{
			for (int j = 0; j < width; j++) {
				cout << "* ";
			}
			cout << endl;
		}
		else {
			cout << "* ";
			for (int j = 2; j < width; j++) {
				cout << "  ";
			}
			cout << "*" << endl;
		}
	}
	cout << endl;
	cout << "\twidth = " << get_width() << " px.\t" << endl;
	cout << "\tlength = " << get_length() << " px.\t" << endl;
	cout << "\tS = " << get_area() << " px2." << endl;
	cout << "\tP = " << get_perimeter() << " px." << endl;
}
const int Square::get_length() const {
	return this->length;
}
const int Square::get_width() const {
	return this->width;
}
const long Square::get_perimeter() const {
	return this->perimeter;
}
const float Square::get_area() const {
	return this->area;
}
int Square::set_length(int length) {
	if (length < 0) length = -length;
	return this->length = length;
}
int Square::set_width(int width) {
	if (width < 0) width = -width;
	return this->width = width;
}
long Square::set_perimeter(long perimeter) {
	return this->perimeter = perimeter;
}
float Square::set_area(float area) {
	return this->area = area;
}
Square::Square(int lenght, int width) {
	set_length(lenght);
	set_width(width);
	set_perimeter(this->length * 2 + this->width * 2);
	set_area(this->length * this->width);
}
Square::~Square() {
}
//##########################################################################################
void Rhombus::print() {
	cout << endl;
	
	int h = length / ((int)90 / this->angle);		// вычислим высоту ромба
	double shag = h != 0 ? leftShift / h : leftShift;	// вычислим шаг смещения при переходах на новую строку
	double temp = h != 0 ? leftShift : 0;				// запишим стартовое смешение верхней части
	for (int i = 0; i <= h; i++) {						// пройдем по всей высоте ромба
		cout << "\t";
		for (int s = 0; s < (int)temp; s++) {			// выполняем смещение верхней части
			cout << "  ";
		}
		temp -= shag;									// изменим смещение для следующего раза
		if ((i == 0) || (i == h)) {						// если это верхний или нижний ряд
			if (i == 0) {								// если это верхний ряд
				for (int j = 0; j < width; j++) {		// проведем сплошную линию
					cout << "* ";			
				}
			}
			if (i == h) {								// если это нижний ряд
				for (int j = 0; j < width; j++) {		// пролинеем сплошную линию
					cout << "* ";
				}
			}
			cout << endl;
		}
		else {											// иначе это средняя часть ромба
			cout << "* ";								// вертикальная левая точка
			for (int j = 2; j < width; j++) {			// перейдем к крайней правой точке
				cout << "  ";
			}
			cout << "*" << endl;						// вертикальная правая точка
		}

	}

	cout << "\tside = " << get_width() << " x "<< get_width() << " px.\t" << endl;
	cout << "\tacute angle = " << get_angle() << " grad.\t" << endl;
	cout << "\tS = " << get_area() << " px2." << endl;
	cout << "\tP = " << get_perimeter() << " px." << endl;
}
const int Rhombus::get_length() const {
	return this->length;
}
const int Rhombus::get_width() const {
	return this->width;
}
const int Rhombus::get_angle() const {
	return this->angle;
}
const long Rhombus::get_perimeter() const {
	return this->perimeter;
}
const float Rhombus::get_area() const {
	return this->area;
}
int Rhombus::set_length(int length) {
	if (length < 0) length = -length;
	return this->length = length;
}
int Rhombus::set_width(int width) {
	if (width < 0) width = -width;
	return this->width = width;
}
int Rhombus::set_angle(int angle) {
	if (angle < 0) angle = -angle;
	if (angle > 180) {
		int y;
		y = (angle / 180) * 180;
		angle = angle - y;
	}
	if (angle > 90) angle = (360 - (angle * 2)) / 2;
	return this->angle = angle;
}
long Rhombus::set_perimeter(long perimeter) {
	return this->perimeter = perimeter;
}
float Rhombus::set_area(float area) {
	return this->area = area;
}
Rhombus::Rhombus(int side, int angle) {
	set_length(side);
	set_width(side);
	set_angle(angle);
	set_perimeter(side * 4);
	double Pi = 2 * acos(0.0);
	set_area((float)pow(side,2) * sin((float)get_angle() * Pi / 180));
	this->leftShift = side * cos((double)(get_angle()) * Pi / 180);
}
//####################################################################################
void Triangle::print() {
	cout << "\tside = " << get_width() << " x " << get_width() << " x " << get_hieght() << " px.\t" << endl;
	cout << "\tS = " << get_area() << " px2." << endl;
	cout << "\tP = " << get_perimeter() << " px." << endl;
}
const int Triangle::get_length() const {
	this->length;
}
const int Triangle::get_width() const {
	this->width;
}
const int Triangle::get_hieght() const {
	this->hieght;
}
const int Triangle::get_angle() const {
	this->angle;
}
const long Triangle::get_perimeter() const {
	this->perimeter;
}
const float Triangle::get_area() const {
	this->area;
}
int Triangle::set_length(int length) {
	if (length < 0) length = -length;
	return this->length = length;
}
int Triangle::set_width(int width) {
	if (width < 0) width = -width;
	return this->width = width;
}
int Triangle::set_hieght(int hieght) {
	if (hieght < 0) hieght = -hieght;
	return this->hieght = hieght;
}
int Triangle::set_angle(int angle) {
	if (angle < 0) angle = -angle;
	if (angle > 180) {
		int y;
		y = (angle / 180) * 180;
		angle = angle - y;
	}
	if (angle > 90) angle = (360 - (angle * 2)) / 2;
	return this->angle = angle;
}
long Triangle::set_perimeter(long perimeter) {
	return this->perimeter = perimeter;
}
float Triangle::set_area(float area) {
	return this->area = area;
}
// a-левый катет, b-правый катет, c-гипотенуза
Triangle::Triangle(int a, int b, int c) {
	set_length(a);
	set_width(b);
	set_hieght(c);
	int p = set_perimeter(a+b+c) / 2;
	
	set_area
	(
		(p * (p - a) * (p - b) * (p - c))
	);	//S = корень p*(p-a)*(p-b)*(p-c)     p = perimetr/2
}
