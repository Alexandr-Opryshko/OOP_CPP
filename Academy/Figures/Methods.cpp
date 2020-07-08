#include"Header.h"

//#################################################################################################
void Square::print() {
	cout << endl;
	for (unsigned int i = 0; i < this->length; i++) {
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
	cout << "\tS = " << get_perimeter() << " px2." << endl;
	cout << "\tP = " << get_area() << " px." << endl;
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
const long Square::get_area() const {
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
long Square::set_area(long area) {
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
