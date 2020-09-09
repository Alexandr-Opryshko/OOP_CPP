#include"Header.h"

//################################################## ���������� LIST
const List::Iterator List::begin() const {
	return Head;
}
const List::Iterator List::end() const {
	return nullptr;
}
const List::ReversIterator List::rbegin() const {
	return Tail;
}
const List::ReversIterator List::rend() const {
	return nullptr;
}
// �����������
List::List() {
	Head = Tail = nullptr;
	size = 0;
	cout << "LConstructor:\t" << this << endl;
}
// ����������� �����������
List::List(const List& other) :List() {
	for (Element* Temp = other.Head;Temp;Temp = Temp->pNext)
		push_back(Temp->Data);
}
// ����������� � ���������� ������������ ����������
List::List(const std::initializer_list<int>& il) : List() {
	for (const int* it = il.begin(); it != il.end(); it++) {
		push_back(*it);
	}
	cout << "ConstructorVariableParameters:\t" << this << endl;
}
List::~List() {
	while (Head != nullptr) pop_front();
	size = 0;
	cout << "LDestructor:\t" << this << endl;
}
//---------------------------------------------------------------------
// Method
// �������� � ������ ������
void List::push_front(int Data) {
	if (Head == nullptr && Tail == nullptr)						// ���� ������ ������
		Head = Tail = new Element(Data);						// �� ��� ������ � ������ �������� ����� ��������
	else Head = Head->pPrev = new Element(Data, Head);			// ����� ��������� ������� ��������  � ������ �������� ����� ������ ��������
	size++;														// �������� ������ �� 1 �������
}
// �������� ������� ��������
void List::pop_front() {
	if (Head == nullptr && Tail == nullptr) return;				// �������� ������� ��������� � ������
	else if (size == 1) {										// ���� ������� ��������� �������
		delete Tail;											// ������ �������
		Head = Tail = nullptr;									// � ������� ���������
	}
	else {														// ����� ������ ��� ���� ������� � ������
		this->Head = Head->pNext;								// ��������� ������� �� ������
		delete Head->pPrev;										// ������� ������� �� ������
		Head->pPrev = nullptr;									// � ������� ��������� �� ��������� �������
	}
	size--;														// �������� ������ �� 1 �������
}
// �������� � ����� ������
void List::push_back(int Data) {
	if (Head == nullptr && Tail == nullptr)						// ���� ������ ������
		Head = Tail = new Element(Data);						// �� ��� ������ � ������ �������� ����� ��������
	else Tail = Tail->pNext = new Element(Data, nullptr, Tail);	// ����� ��������� ���������� ��������  � ������ �������� ����� ������ ��������
	size++;														// �������� ������ �� 1 �������
}
// �������� ���������� ��������
void List::pop_back() {
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
bool List::insert(int data, int index) {
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
bool List::erase(int index) {
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
List& List::operator =(const List& Head) {
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
List& List::operator =(List&& Head) {
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
List List::operator +(const List& Head) const {
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
void List::operator +=(const List& Head) {
	for (Element* temp = Head.Head; temp; temp = temp->pNext) {
		push_back(temp->Data);
	}
}
// ����� ��������� � ������� ������ ���
void List::print() {
	cout << endl;
	//for (Element* Temp = Head; Temp; Temp = Temp->pNext)
		//cout << Temp->pPrev << tab <<  Temp << tab << Temp->Data << tab << Temp->pNext << endl;
	for (Iterator it = Head; it; it++)
		cout << *it << endl;

	cout << endl << tab << "��������� � list: " << this->size << endl;
}
// ����� ��������� � ������� �������� ���
void List::printRevers() {
	cout << endl;
	/*for (Element* Temp = Tail; Temp; Temp = Temp->pPrev)
		cout << Temp->pNext << tab << Temp << tab << Temp->Data << tab << Temp->pPrev << endl;
	*/
	for (ReversIterator it = Tail; it; it++)
		cout << *it << endl;

	cout << endl << tab << "��������� � list: " << this->size << endl;
}
