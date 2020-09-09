#include"Header.h"

//################################################## реализация Iterator
List::Iterator::Iterator(Element* Temp) : Temp(Temp) {
	this->Temp = Temp;
	cout << "ItConstructor:\t" << this << endl;
}
List::Iterator::~Iterator() {
	cout << "ItDestructor:\t" << this << endl;
}
List::Iterator& List::Iterator::operator++() {
	Temp = Temp->pNext;
	return *this;
}
List::Iterator& List::Iterator::operator--() {
	Temp = Temp->pPrev;
	return *this;
}
List::Iterator& List::Iterator::operator++(int) {
	Temp = Temp->pNext;
	return *this;
}
List::Iterator& List::Iterator::operator--(int) {
	Temp = Temp->pPrev;
	return *this;
}
bool List::Iterator::operator!=(const Iterator& other) const {
	return this->Temp != other.Temp;
}
bool List::Iterator::operator!=(Element* other_el) const {
	return this->Temp != other_el;
}
const int& List::Iterator::operator*() const {
	return Temp->Data;
}
int& List::Iterator::operator*() {
	return Temp->Data;
}
// замена Temp != nulptr на Temp
List::Iterator::operator bool()const {
	return Temp;
}
