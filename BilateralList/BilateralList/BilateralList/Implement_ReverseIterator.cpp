#include"Header.h"

//################################################## реализация ReversIterator
List::ReversIterator::ReversIterator(Element* Temp) :Temp(Temp) {
	this->Temp = Temp;
	cout << "ReversItConstructor:\t" << this << endl;
}
List::ReversIterator ::~ReversIterator() {
	cout << "ReversItDestructor:\t" << this << endl;
}
List::ReversIterator& List::ReversIterator::operator++() {
	Temp = Temp->pPrev;
	return *this;
}
List::ReversIterator& List::ReversIterator::operator--() {
	Temp = Temp->pNext;
	return *this;
}
List::ReversIterator& List::ReversIterator::operator++(int) {
	Temp = Temp->pPrev;
	return *this;
}
List::ReversIterator& List::ReversIterator::operator--(int) {
	Temp = Temp->pNext;
	return *this;
}
bool List::ReversIterator::operator!=(const ReversIterator& other) const {
	return this->Temp != other.Temp;
}
bool List::ReversIterator::operator!=(Element* other_el) const {
	return this->Temp != other_el;
}
const int& List::ReversIterator::operator*() const {
	return Temp->Data;
}
int& List::ReversIterator::operator*() {
	return Temp->Data;
}
List::ReversIterator::operator bool()const {
	return Temp;
}
