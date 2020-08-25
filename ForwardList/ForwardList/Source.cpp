#include<iostream>
using namespace std;

#define tab	"\t"
#define DEBUG

class Element {
public:

	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext) {

#ifdef DEBUG
		cout << "EConstructor:\t" << this << endl;
#endif // DEBUG

	}
	
	~Element() {
		Data = 0;
		pNext = nullptr;
#ifdef DEBUG
		cout << "EDestructor:\t" << this << endl;
#endif // DEBUG

	}
	
	friend class ForwardList;
	friend class Iterator;
private:
	int Data;
	Element* pNext;
};
class Iterator {
public:
	Iterator(Element* Temp = nullptr) {
		this->Temp = Temp;
		cout << "ItConstructor:\t" << this << endl;
	}
	~Iterator() {
		cout << "ItDestructor:\t" << this << endl;
	}
	Iterator& operator++() {
		Temp = Temp->pNext;
		return *this;
	}
	Iterator& operator++(int) {
		Temp = Temp->pNext;
		return *this;
	}
	bool operator!=(const Iterator& other) const {
		return this->Temp != other.Temp;
	}
	bool operator!=(Element* other_el) const {
		return this->Temp != other_el;
	}
	int& operator*() {
		return Temp->Data;
	}
	// ������ Temp != nulptr �� Temp
	operator bool()const {
		return Temp;
	}
private:
	Element* Temp;
};

class ForwardList{
public:
	Iterator begin() {
		return Head;
	}
	Iterator end() {
		return nullptr;
	}
	// ����������� �� ��������� 
	ForwardList() {
		this->Head = nullptr;
		this->IndexList = 0;
#ifdef DEBUG
		cout << "LConstructor:\t" << this << endl;
#endif // DEBUG

	}
	// ����������
	~ForwardList() {
		while (Head != nullptr) pop_front();
#ifdef DEBUG
		cout << "LDestructor:\t" << this << endl;
#endif // DEBUG

	}
	// ����������� � ���������� ������������ ����������
	ForwardList(const std::initializer_list<int> & il) {
		cout << "ConstructorVariableParameters:\t" << this << endl;
		for (const int* it = il.begin(); it != il.end(); it++) {
			push_back(*it);
		}
	}
	// ����������� �����������
	ForwardList(const ForwardList &Head) {
		cout << "CopyConstructor:\t" << this << endl;
		this->Head = nullptr;
		this->IndexList = 0;
		push_back_list(Head.Head);
	}
	// ����������� �� �������� ����������� ���������
	ForwardList(int size) {
		cout << "ConstructorGivenQuantityParameters:\t" << this << endl;
		while (size--) {
			push_front(0);
		}
	}
	// Method
	int Get_IndexList() const{
		return this->IndexList;
	}
	void Set_Head(Element *Head) {
		this->Head = Head;
	}
	Element* Get_Head() const {
		return this->Head;
	}
	bool ErrDelElementList() {
		if (Head == nullptr) {
			this->IndexList = 0;				// ����������� ���������
			return false;						// ���������� ������ ���������
		}
		return true;
	}
	// �������� � ������ ������
	void push_front(int Data) {
		Head = new Element(Data, Head);
		this->IndexList++;						// �������� ������� ��������� �� ����
	}
	// �������� � ����� ������
	void push_back(int Data) {
		if (Head == nullptr) {						// ���� ����������� ��������� 0
			push_front(Data);						// �������� ������ �������
			return;									// � ������
		}
		Element* Temp = Head;						// �������� ����� ������ ������ ���������
		while (Temp->pNext) {						// �������� �� ������� �������� � ����� ������
			Temp = Temp->pNext;
		}
		Temp->pNext = new Element(Data);			// �������� � ������� ����� ������ ��������
		this->IndexList++;							// �������� ������� ��������� �� 1
	}
	// ��������� � ����� ���� ����
	void push_back_list(Element* Head) {
		if (Head == Head) return;
		for (Element* Temp1 = Head; Temp1;Temp1 = Temp1->pNext) {
			this->push_back(Temp1->Data);
		}
	}
	// �������� ������� ��������
	void pop_front() {
		if(ErrDelElementList() == false) return;	// �������� ������� ������ ��� ������ �������� � ������
		Element* to_del = Head;						// ���������� ����� ���������� ��������
		Head = Head->pNext;							// ��������� ������� �� ������
		delete to_del;								// ������� ������� �� ������
		this->IndexList--;							// �������� ������ �� 1 �������
	}
	// �������� ���������� ��������
	void pop_back() {
		if (ErrDelElementList() == false) return;	// �������� ������� ������ ��� ������ �������� � ������
		Element* Temp = Head;						// ��������� ��������� ����� �����
		while (Temp->pNext->pNext) {				// ������ �� ���������� �������� �����
			Temp = Temp->pNext;						// ����� ����� ��������� ��������
		}
		delete Temp->pNext;							// ������ ��������� �������
		Temp->pNext = nullptr;						// ������� ����� ������������ �������� � �������
		this->IndexList--;							// � �������� ������ ����������� ���������
		return;
	}
	// �������� �������� �� �������
	void insert(int Data, int index) {
		while (this->IndexList < index) {				// ���� ����� ��������� �� ��������� �����
			push_back(0);								// ��������� � ����� ����� ������ �������� ���� �� ������ �� ������� �������
		}
		if (index == 0) {
			push_front(Data);
			return;
		}
		Element* Temp = Head;							// ������� ��������� ����� lista
		for (int i = 0; i < index - 1; i++) {			// �������� � ���������� �������
			Temp = Temp->pNext;							// �������� � ���������� ��������
		}

		Temp->pNext = new Element(Data, Temp->pNext);	// ������� ����� ��������� �������
		this->IndexList++;								// ��������� ����� ���������

		return;
	}
	// �������� �������� �� �������
	bool erase(int index) {
		if (this->IndexList <= index) return false;		// ������ � ��������������� � ���������� ������� �� ��������� ������
		Element* Temp = Head;							// ������� ��������� ����� �����

		for (int i = 0; i < index - 1; i++) {			// �������� � �������� �� �������
			Temp = Temp->pNext;
		}
		Element* to_del = Temp->pNext;					// ������� ��������� �������
		Temp->pNext = Temp->pNext->pNext;				// ������� ����� ���������� �� ��������� ���������
		delete to_del;									// ������ �������

		if (this->IndexList != 0)						// ���� ���������� ������ 0
			this->IndexList--;							// ���������� ��������� ����� ���������
		return true;									// ������ � ������� ��������� ��������
	}
	// ����� ��������� � �������
	void print() {
		/*for (Element* Temp = Head; Temp; Temp = Temp->pNext)
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;*/
		/*for (Iterator Temp = begin(); Temp != end(); Temp++)
			cout << *Temp << endl;*/
		for (int i : *this) {
			cout << i << endl;
		}
		cout << endl << tab << "��������� � list: "<<this->IndexList << endl;
	}
	// �������� ���������
	void operator = (const ForwardList& Head) {
		cout << "AssignConstructor:\t" << this << endl;
		for (Element* temp = this->Head;temp;) {
			Element* to_del = temp;
			temp = temp->pNext;
			delete to_del;
		}
		this->Head = nullptr;
		this->IndexList = 0;
		push_back_list(Head.Head);
		return;
	}
	// move assignment
	ForwardList& operator= (ForwardList&& Head) {
		for (Element* temp = this->Head;temp;) {
			Element* to_del = temp;
			temp = temp->pNext;
			delete to_del;
		}
		this->Head = nullptr;
		this->IndexList = 0;
		push_back_list(Head.Head);
		cout << "MoveAssignment\t\t" << this << endl;
		return *this;
	}
	// �������� ��������
	ForwardList operator +(const ForwardList& Head) const {
		ForwardList temp;
		temp.push_back_list(this->Head);
		temp.push_back_list(Head.Head);
		return temp;
	}
	// �������� �������� �� �������
	int& operator[](int index) {
		if (index >= this->IndexList)throw std::exception("\t\tError: out of range");
		for (Element* Temp = Head; Temp; Temp = Temp->pNext) {
			if (index-- == 0)
				return Temp->Data;
		}
	}
	
	

private:
	Element* Head;
	int IndexList;
};


//� ����� ForwardList �������� :
//							1. ����������;
//							2. ����������� �����������;
//							3. �������� ������������;
//							4. �������� + , ������� ����� ��������������� ������;
//							5. MoveMethods;
//							6. ����������� �� �������� ����� ��������� ForwardList list(5), �������� ������ ���� ��������� ������;
//							7. ��������[];
//							8. ForwardList list{ 3, 5, 8, 13, 21 }; for (int i = 0; i < list.size; i++)cout << list[i] << tab;cout << endl;


void main() {
	setlocale(LC_ALL, "");


	ForwardList list{ 1,2,3,4,5,6 };
	for (int i : list) {
		cout << i << endl;
	}
	list.print();
	//for (Iterator Temp = list.Get_Head(); Temp/* != nullptr*/; 
	//	Temp++) {
	//	cout << *Temp << endl;
	//}

	/*ForwardList list{ 3, 5, 8, 13, 21, -1 };
	list.print();*/
	//ForwardList list14( 100000 );
	//list14.print();
	/*ForwardList list1;
	list1.push_back(3);
	list1.push_back(7);
	list1.push_back(15);
	list1.push_back(30);
	list1.print();

	list14 = list1;
	try {
		list14[10] = 5;
	}
	catch (const std::exception& e) {
		cerr << e.what() << endl;
	}
	list14.print();*/
	//ForwardList list2 = {5,1,2,3,4,5 };	// 0-� ����������� ���������, � ������
	//list2.print();
	
	//ForwardList list3;
	//list3 = list1 + list2;
	//list3.print();

	//cout  << endl;
	//cout << list2[3] << endl;
	//list2[30] = 5;
	//list2.print();
	//ForwardList list21(list1);
	//list21.print();
	/*
	ForwardList list2{1,2,3,4,5,-1};
	list2.print();
	int Data = list2[3];
	cout << Data << endl;*/


	/*list1.insert(111, 1);
	list1.erase(4);
	list1.print();*/


	//int n;
	//cout << "Input list size: "; cin >> n;

	//ForwardList list;
	//for (int i = 0; i < n; i++) {
	//	list.push_back(rand() % 100);
	//	//list.push_front(rand() % 100);
	//}	
	//list.print();
	//cout << endl;

	////list.push_back(123);
	////list.print();
	////cout << endl;

	////list.pop_front();
	////list.print();
	////cout << endl;

	//list.pop_back();
	//list.print();
	//cout << endl;

	//if (list.insert(28, 0) == false) {
	//	cout << tab << "������ ������� ��������. ��������� �� ��������� lista" << endl;
	//}
	//list.print();
	//cout << endl;

	////if (list.erase(4) == false) {
	////	cout << tab << "������ �������� ��������. ��������� �� ��������� lista" << endl;
	////}
	////list.print();


	//cout << "�� ������� ��������� �������� ����: "; cin >> n;
	//for (int i = 0; i < n; i++) {
	//	list.pop_back();
	//	list.print();
	//}
}