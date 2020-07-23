#include<iostream>
using namespace std;

#define tab	"\t"

class Element {
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext) {

		cout << "EConstructor:\t" << this << endl;
	}
	~Element() {
		cout << "EDestructor:\t" << this << endl;
	}
	friend class ForwardList;

private:
	int Data;
	Element* pNext;
};

class ForwardList {
public:
	ForwardList() {
		this->Head = nullptr;
		this->IndexList = 0;
		cout << "LConstructor:\t" << this << endl;
	}
	~ForwardList() {
		cout << "LDestructor:\t" << this << endl;
	}
	// Method
	// �������� � ������ ������
	void push_front(int Data) {
		Element* New = new Element(Data);		// ������� ����� �������, � ��������� � ���� ����������� ��������
		New->pNext = Head;
		Head = New;
		this->IndexList++;
	}
	// �������� � ����� ������
	void push_back(int Data) {
		if (Head == nullptr) {
			push_front(Data);
			return;
		}
		Element* New = new Element(Data);
		Element* Temp = Head;
		while (Temp->pNext) {
			Temp = Temp->pNext;
		}
		Temp->pNext = New;
		this->IndexList++;
	}
	// �������� ������� ��������
	void pop_front() {
		Element* Temp = Head;
		if (Temp->pNext) {
			Temp = Temp->pNext;
			Head = Temp;
			this->IndexList--;
		}
		else {
			Head = nullptr;
			this->IndexList = 0;
		}
	}
	// �������� ���������� ��������
	void pop_back() {
		if(this->IndexList <= 1){						// ���� ��������� 0 ��� 1
			Head = nullptr;								// ������ ������� ���������
			this->IndexList = 0;						// � ����������� ���������
			return;
		}
		Element* Temp = Head;							// ��������� ��������� ����� �����
		Element* TempStep = Temp->pNext;				// ��������� ����������� ����� �������� �����
		while (TempStep->pNext) {						// ������ �� ���������� �������� �����
			TempStep = TempStep->pNext;					// ����� ����� ������������ ��������
			Temp = Temp->pNext;							// ����� ����� ��������� ��������
		}
		Temp->pNext = nullptr;							// ������� ����� ������������ �������� � �������
		this->IndexList--;								// � �������� ������ ����������� ���������
		return;
	}
	// �������� �������� �� �������
	bool insert(int Data, int index) {
		if (this->IndexList < index) return false;		// ������ � ��������������� � ���������� ������� �� ��������� ������
		Element* New = new Element(Data);				// �������� �������
		Element* Temp = Head;							// ������� ��������� ����� lista
		Element* TempStep = Temp->pNext;				// ������� ����� ���������� �������� lista
		for (int i = 0; i < index - 1; i++) {			// �������� � ���������� �������
			Temp = Temp->pNext;							// �������� � ���������� ��������
			TempStep = TempStep->pNext;					// �������� � ������������ ��������
		}
		New->pNext = TempStep;							// ���������� ������ � ������� ������������ ��������
		Temp->pNext = New;								// � � ���������� ����� ������ ��������
		this->IndexList++;

		return true;
	}
	// �������� �������� �� �������
	bool erase(int index) {
		if (this->IndexList <= index) return false;		// ������ � ��������������� � ���������� ������� �� ��������� ������
		Element* Temp = Head;							// ������� ��������� ����� �����
		Element* TempStep = Temp->pNext;				// � ������������ ��������
		if (index == 0) {								// ���� ��������� 0-� �������
			Head = TempStep;
		}
		else {
			for (int i = 0; i < index - 1; i++) {		// �������� � ���������� �������� �� �������
				if (TempStep == nullptr) return false;	// ���� ����� ����� - ������ � ���������������
				Temp = Temp->pNext;						// ������� � ���������� ��������
				TempStep = TempStep->pNext;				// ������� � ������������ ��������
			}
			if (TempStep != nullptr) {					// ���� ��� �� ��������� �������
				Temp->pNext = TempStep->pNext;			// ������� ����� �������� ����������� � �����������
				Temp = TempStep;						// � ������ ������� ����������� ����� ������������
			}
			else {										// �����
				Temp->pNext = nullptr;					// ������� �������� ����� �����
				return false;							// � ������ � ��������������� ��� ��� ����� ������
			}
		}
		if (this->IndexList != 0)
			this->IndexList--;
		return true;										// ������ � ������� ��������� ��������
	}

	void print() {
		Element* Temp = Head;					// Temp - ��� �������� (��������� ��� ������ �������� �����
												// �������� ������ ������ � ��������� ��������� ������)
		while (Temp != nullptr) {
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;					// ������� �� ��������� �������
		}

		cout << endl << tab << "��������� � list: "<<this->IndexList << endl;
	}
private:
	Element* Head;
	int IndexList;
};


void main() {
	setlocale(LC_ALL, "");
	int n;
	cout << "Input list size: "; cin >> n;

	ForwardList list;
	for (int i = 0; i < n; i++) {
		list.push_back(rand() % 100);
		//list.push_front(rand() % 100);
	}	
	list.print();
	cout << endl;

	list.push_back(123);
	list.print();
	cout << endl;

	list.pop_front();
	list.print();
	cout << endl;

	list.pop_back();
	list.print();
	cout << endl;

	if (list.insert(28, 4) == false) {
		cout << tab << "������ ������� ��������. ��������� �� ��������� lista" << endl;
	}
	list.print();
	cout << endl;

	if (list.erase(4) == false) {
		cout << tab << "������ �������� ��������. ��������� �� ��������� lista" << endl;
	}
	list.print();

	cout << "�� ������� ��������� �������� ����: "; cin >> n;
	for (int i = 0; i < n; i++) {
		list.pop_back();
		list.print();
	}
}