#include"Header.h"


void Square::print() {

}
const int Square::get_length() const {
	return this->length;
}
const int Square::get_width() const {
	return this->width;
}
int Square::set_length(int length) {
	if (length < 0) length = -length;
	return this->length = length;
}
int Square::set_width(int width) {
	if (width < 0) width = -width;
	return this->width = width;
}

Square::Square(int lenght = 0, int width = 0) {
	set_length(lenght);
	set_width(width);
}
Square::Square() {
	this->length = 0;
	this->width = 0;
}
Square::~Square() {
}