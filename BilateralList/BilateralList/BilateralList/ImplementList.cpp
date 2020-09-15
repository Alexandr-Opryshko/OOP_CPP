#include"Header.h"

///////////////////////////////////////////////////////////////////////////////
////////////////////////////// CLASS DEFINITION ///////////////////////////////
///////////////////////////////////////////////////////////////////////////////
template<typename T>
List<T>::Element::Element(T Data, Element* pNext, Element* pPrev) :Data(Data), pNext(pNext), pPrev(pPrev) {
	cout << "EConstructor:\t" << this << endl;
}
template<typename T>
List<T>::Element::~Element() {
	cout << "EDestructor:\t" << this << endl;
}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////    ITERATOR    ////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

template<typename T>
List<T>::Iterator::Iterator(Element* Temp) {
	this->Temp = Temp;
	cout << "ItConstructor:\t" << this << endl;
}
template<typename T>
List<T>::Iterator::~Iterator() {
	cout << "ItDestructor:\t" << this << endl;
}
template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator++() {
	Temp = Temp->pNext;
	return *this;
}
template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator--() {
	Temp = Temp->pPrev;
	return *this;
}
template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator++(int) {
	Temp = Temp->pNext;
	return *this;
}
template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator--(int) {
	Temp = Temp->pPrev;
	return *this;
}
template<typename T>
bool List<T>::Iterator::operator!=(const Iterator& other) const {
	return this->Temp != other.Temp;
}
template<typename T>
bool List<T>::Iterator::operator!=(Element* other_el) const {
	return this->Temp != other_el;
}
template<typename T>
const T& List<T>::Iterator::operator*() const {
	return Temp->Data;
}
template<typename T>
T& List<T>::Iterator::operator*() {
	return Temp->Data;
}
// ������ Temp != nulptr �� Temp
template<typename T>
List<T>::Iterator::operator bool()const {
	return Temp;
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////    REVERSITERATOR    //////////////////////////////
///////////////////////////////////////////////////////////////////////////////
template<typename T>
List<T>::ReversIterator::ReversIterator(Element* Temp) {
	this->Temp = Temp;
	cout << "ReversItConstructor:\t" << this << endl;
}
template<typename T>
List<T>::ReversIterator::~ReversIterator() {
	cout << "ReversItDestructor:\t" << this << endl;
}
template<typename T>
typename List<T>::ReversIterator& List<T>::ReversIterator::operator++() {
	Temp = Temp->pPrev;
	return *this;
}
template<typename T>
typename List<T>::ReversIterator& List<T>::ReversIterator::operator--() {
	Temp = Temp->pNext;
	return *this;
}
template<typename T>
typename List<T>::ReversIterator& List<T>::ReversIterator::operator++(int) {
	Temp = Temp->pPrev;
	return *this;
}
template<typename T>
typename List<T>::ReversIterator& List<T>::ReversIterator::operator--(int) {
	Temp = Temp->pNext;
	return *this;
}
template<typename T>
bool List<T>::ReversIterator::operator!=(const ReversIterator& other) const {
	return this->Temp != other.Temp;
}
template<typename T>
bool List<T>::ReversIterator::operator!=(Element* other_el) const {
	return this->Temp != other_el;
}
template<typename T>
const T& List<T>::ReversIterator::operator*() const {
	return Temp->Data;
}
template<typename T>
T& List<T>::ReversIterator::operator*() {
	return Temp->Data;
}
template<typename T>
List<T>::ReversIterator::operator bool()const {
	return Temp;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////    LIST    ////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
template<typename T>
typename const List<T>::Iterator List<T>::begin() const {
	return Head;
}
template<typename T>
typename const List<T>::Iterator List<T>::end() const {
	return nullptr;
}
template<typename T>
typename const List<T>::ReversIterator List<T>::rbegin() const {
	return Tail;
}
template<typename T>
typename const List<T>::ReversIterator List<T>::rend() const {
	return nullptr;
}
// �����������
template<typename T>
List<T>::List() {
	Head = Tail = nullptr;
	size = 0;
	cout << "LConstructor:\t" << this << endl;
}
// ����������� �����������
template<typename T>
List<T>::List(const List& other) :List() {
	for (Element* Temp = other.Head;Temp;Temp = Temp->pNext)
		push_back(Temp->Data);
}
// ����������� � ���������� ������������ ����������
template<typename T>
List<T>::List(const std::initializer_list<T>& il) : List() {
	for (const T* it = il.begin(); it != il.end(); it++) {
		push_back(*it);
	}
	cout << "ConstructorVariableParameters:\t" << this << endl;
}
template<typename T>
List<T>::~List() {
	while (Head != nullptr) pop_front();
	size = 0;
	cout << "LDestructor:\t" << this << endl;
}
//---------------------------------------------------------------------
// Method
// �������� � ������ ������
template<typename T>
void List<T>::push_front(T Data) {
	if (Head == nullptr && Tail == nullptr)						// ���� ������ ������
		Head = Tail = new Element(Data);						// �� ��� ������ � ������ �������� ����� ��������
	else Head = Head->pPrev = new Element(Data, Head);			// ����� ��������� ������� ��������  � ������ �������� ����� ������ ��������
	size++;														// �������� ������ �� 1 �������
}
// �������� ������� ��������
template<typename T>
void List<T>::pop_front() {
	if (Head == nullptr && Tail == nullptr) return;				// �������� ������� ��������� � ������
	else if (size == 1) {										// ���� ������� ��������� �������
		delete Tail;											// ������ �������
		Head = Tail = nullptr;									// � ������� ���������
	}
	else {														// ����� ������ ��� ���� ������� � ������
		Head = Head->pNext;										// ��������� ������� �� ������
		delete Head->pPrev;										// ������� ������� �� ������
		Head->pPrev = nullptr;									// � ������� ��������� �� ��������� �������
	}
	size--;														// �������� ������ �� 1 �������
}
// �������� � ����� ������
template<typename T>
void List<T>::push_back(T Data) {
	if (Head == nullptr && Tail == nullptr)						// ���� ������ ������
		Head = Tail = new Element(Data);						// �� ��� ������ � ������ �������� ����� ��������
	else Tail = Tail->pNext = new Element(Data, nullptr, Tail);	// ����� ��������� ���������� ��������  � ������ �������� ����� ������ ��������
	size++;														// �������� ������ �� 1 �������
}
// �������� ���������� ��������
template<typename T>
void List<T>::pop_back() {
	if (Head == nullptr && Tail == nullptr) return;				// ���� ������ ������
	else if (size == 1) {										// ���� ������� ��������� �������
		delete Tail;											// ������ �������
		Head = Tail = nullptr;									// � ������� ���������
	}
	else {														// ����� � ������ ����� ������ ��������
		Tail = Tail->pPrev;										// ������� � ����� ����� �������������� ��������
		delete Tail->pNext;										// ������ ��������� �������
		Tail->pNext = nullptr;									// � ������� ��������� �� ��������� �������
	}
	size--;														// �������� ����������� ��������� � ������ �� ����
}
// �������� �������� �� �������
template<typename T>
bool List<T>::insert(T data, int index) {
	if (index > (size) || index < 0) return false;
	else if (index == 0) {										// ���� ������� �� ����� ������� ��������
		push_front(data); return true;							// �� ������� �����
	}
	else if (index == size) {									// ���� ������� �� ����� ���������� ��������
		push_back(data); return true;							// �� ������� �����
	}
	else if ((size / 2) >= index) {								// ���� ������� �� �������� ������
		Element* Temp = Head;									// ������� ����� ������ �����
		while (index--) {										// ������ �� ���������� �����
			Temp = Temp->pNext;									// �� ������
		}
		Temp->pPrev->pPrev->pNext = Temp->pPrev = new Element(data, Temp, Temp->pPrev);
	}
	else {														// ����� ������ ����� � ������
		Element* Temp = Tail;									// ������� ����� ������
		index = size - index - 1;								// ��������� �������� �������� � ������
		while (index--) {										// ������ �� ���������� �����
			Temp = Temp->pPrev;									// �� ������
		}
		Temp->pPrev->pPrev->pNext = Temp->pPrev = new Element(data, Temp, Temp->pPrev);
	}
	size++;														// �������� ������ �� 1 �������
	return true;
}
// �������� �������� �� �������
template<typename T>
bool List<T>::erase(int index) {
	if (index > (size - 1) || index < 0) return false;			// ������ �� ��������� ������
	else if (index == 0) {										// ���� �������� ������� ��������
		pop_front(); return true;								// �� ������� �����
	}
	else if (index == size - 1) {								// ���� �������� ���������� ��������
		pop_back(); return true;								// �� ������� �����
	}
	else if ((size / 2) >= index) {								// ���� �������� �� �������� ������
		Element* Temp = Head;									// ������� ����� ������ �����
		while (index--) {										// ������ �� ���������� �����
			Temp = Temp->pNext;									// �� ������
		}
		Temp->pPrev->pNext = Temp->pNext;						// 
		Temp->pNext->pPrev = Temp->pPrev;						// 
		delete Temp;
	}
	else {														// ����� ������ ����� � ������
		Element* Temp = Tail;									// ������� ����� ������
		index = size - index - 1;								// ��������� �������� �������� � ������
		while (index--) {										// ������ �� ���������� �����
			Temp = Temp->pPrev;									// �� ������
		}
		Temp->pPrev->pNext = Temp->pNext;
		Temp->pNext->pPrev = Temp->pPrev;
		delete Temp;
	}
	size--;														// �������� ������ �� 1 �������
	return true;
}
//CopyMethods;
template<typename T>
List<T>& List<T>::operator =(const List& Head) {
	if (this->Head == Head.Head)return *this;
	if (this->Head == nullptr && this->Tail == nullptr) {					// ���� ������ ����
		this->Head = this->Tail = new Element(Head.Head->Data);				// ������� ������ �������
		this->size = 1;														// ������� ����������� ���������
		for (Element* temp = Head.Head->pNext; temp;temp = temp->pNext) {	// ������� ��������� ������ ������
			Tail = Tail->pNext = new Element(temp->Data, nullptr, Tail);
			size++;
		}
	}
	else if (this->size >= Head.size) {										// ���� ���������� ������ ������ ��� ����� ���������
		int sizeTemp = 0;
		Element* TempThis = this->Head;										// ������� ����� ��������� ������
		Element* Temp = Head.Head;											// ������� ����� �������������������
		for (int i = 0; i < Head.size; i++) {								// ��������� ���� �� ����������� �������� ������
			TempThis->Data = Temp->Data;									// ������� ����������� ������
			TempThis = TempThis->pNext;										// ������� � ���������� �������� ��������� ������
			Temp = Temp->pNext;												// ������� � ���������� �������� ����������� ������
			sizeTemp++;
		}
		while (sizeTemp != this->size) {									// ������� ������ ��������
			pop_back();														// ����� �����
		}
	}
	else {																	// ����� �������� ������ ������
		Element* TempThis = this->Head;										// ������� ����� ��������� ������
		Element* Temp = Head.Head;											// ������� ����� �������������������
		for (int i = 0; i < size; i++) {									// ��������� ���� �� ����������� �������� ������
			TempThis->Data = Temp->Data;									// ������� ����������� ������
			TempThis = TempThis->pNext;										// ������� � ���������� �������� ��������� ������
			Temp = Temp->pNext;												// ������� � ���������� �������� ����������� ������
		}
		for (; Temp; Temp = Temp->pNext) {									// ���������� ���������
			push_back(Temp->Data);											// ����� �����
		}
	}
	cout << "AssignConstructor:\t" << this << endl;
	return *this;
}
//MoveMethods;
template<typename T>
List<T>& List<T>::operator =(List&& Head) {
	if (this->Head == Head.Head)return *this;
	if (this->Head == nullptr && this->Tail == nullptr) {					// ���� ������ ����
		this->Head = this->Tail = new Element(Head.Head->Data);				// ������� ������ �������
		this->size = 1;														// ������� ����������� ���������
		for (Element* temp = Head.Head->pNext; temp;temp = temp->pNext) {	// ������� ��������� ������ ������
			Tail = Tail->pNext = new Element(temp->Data, nullptr, Tail);
			size++;
		}
	}
	else if (this->size >= Head.size) {										// ���� ���������� ������ ������ ��� ����� ���������
		int sizeTemp = 0;
		Element* TempThis = this->Head;										// ������� ����� ��������� ������
		Element* Temp = Head.Head;											// ������� ����� �������������������
		for (int i = 0; i < Head.size; i++) {								// ��������� ���� �� ����������� �������� ������
			TempThis->Data = Temp->Data;									// ������� ����������� ������
			TempThis = TempThis->pNext;										// ������� � ���������� �������� ��������� ������
			Temp = Temp->pNext;												// ������� � ���������� �������� ����������� ������
			sizeTemp++;
		}
		while (sizeTemp != this->size) {									// ������� ������ ��������
			pop_back();														// ����� �����
		}
	}
	else {																	// ����� �������� ������ ������
		Element* TempThis = this->Head;										// ������� ����� ��������� ������
		Element* Temp = Head.Head;											// ������� ����� �������������������
		for (int i = 0; i < size; i++) {									// ��������� ���� �� ����������� �������� ������
			TempThis->Data = Temp->Data;									// ������� ����������� ������
			TempThis = TempThis->pNext;										// ������� � ���������� �������� ��������� ������
			Temp = Temp->pNext;												// ������� � ���������� �������� ����������� ������
		}
		for (; Temp; Temp = Temp->pNext) {									// ���������� ���������
			push_back(Temp->Data);											// ����� �����
		}
	}
	cout << "MoveAssignment\t\t" << this << endl;
	return *this;
}
//operator+;
template<typename T>
List<T> List<T>::operator +(const List& Head) const {
	List list;
	Element* TempThis = this->Head;
	Element* Temp = Head.Head;
	for (int i = 0; i < this->size; i++) {
		list.push_back(TempThis->Data);
		TempThis = TempThis->pNext;
	}
	for (int i = 0; i < this->size; i++) {
		list.push_back(Temp->Data);
		Temp = Temp->pNext;
	}
	return list;
}
//operator+=;
template<typename T>
void List<T>::operator +=(const List& Head) {
	for (Element* temp = Head.Head; temp; temp = temp->pNext) {
		push_back(temp->Data);
	}
}
// ����� ��������� � ������� ������ ���
template<typename T>
void List<T>::print() {
	cout << endl;
	//for (Element* Temp = Head; Temp; Temp = Temp->pNext)
		//cout << Temp->pPrev << tab <<  Temp << tab << Temp->Data << tab << Temp->pNext << endl;
	for (Iterator it = Head; it; it++)
		cout << *it << endl;

	cout << endl << tab << "��������� � list: " << this->size << endl;
}
// ����� ��������� � ������� �������� ���
template<typename T>
void List<T>::printRevers() {
	cout << endl;
	/*for (Element* Temp = Tail; Temp; Temp = Temp->pPrev)
		cout << Temp->pNext << tab << Temp << tab << Temp->Data << tab << Temp->pPrev << endl;
	*/
	for (ReversIterator it = Tail; it; it++)
		cout << *it << endl;

	cout << endl << tab << "��������� � list: " << this->size << endl;
}