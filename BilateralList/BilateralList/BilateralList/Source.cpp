#include<iostream>
using namespace std;
#define tab	"\t"

class List {
public:
	List() {
		Head = Tail = nullptr;
		size = 0;
		cout << "LConstructor:\t" << this << endl;
	}
	~List() {
		while (Head != nullptr) pop_front();
		size = 0;
		cout << "LDestructor:\t" << this << endl;
	}
	//---------------------------------------------------------------------
	// Method
	// �������� � ������ ������
	void push_front(int Data) {
		if (Head == nullptr && Tail == nullptr)						// ���� ������ ������
			Head = Tail = new Element(Data);						// �� ��� ������ � ������ �������� ����� ��������
		else Head = Head->pPrev = new Element(Data, Head);			// ����� ��������� ������� ��������  � ������ �������� ����� ������ ��������
		size++;														// �������� ������ �� 1 �������
	}
	// �������� ������� ��������
	void pop_front() {
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
	void push_back(int Data) {
		if (Head == nullptr && Tail == nullptr)						// ���� ������ ������
			Head = Tail = new Element(Data);						// �� ��� ������ � ������ �������� ����� ��������
		else Tail = Tail->pNext = new Element(Data, nullptr, Tail);	// ����� ��������� ���������� ��������  � ������ �������� ����� ������ ��������
		size++;														// �������� ������ �� 1 �������
	}
	// �������� ���������� ��������
	void pop_back() {
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
	bool insert(int data, int index) {
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
	bool erase(int index) {
		if (index > (size - 1) || index < 0) return false;
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
	//MoveMethods;
	List& operator= (List&& Head) {
		for (Element* temp = this->Head;temp;) {						// �������� �� ������������� ������� �����
			Element* to_del = temp;										// ������ �������
			temp = temp->pNext;											// �������� � ����������
			delete to_del;
		}
		// �� ������� ��������� �������
		//for (Element* temp = this->Head->pNext;temp;temp = temp->pNext) {						// �������� �� ������������� ������� �����
		//	
		//	delete temp->pPrev;
		//}
		this->Head = this->Tail = nullptr;	
		this->Head = this->Tail = new Element(Head.Head->Data);
		this->size = 1;
		for (Element* temp = Head.Head->pNext; temp;temp = temp->pNext) {
			Tail = Tail->pNext = new Element(temp->Data, nullptr, Tail);
			size++;
		}
		cout << "MoveAssignment\t\t" << this << endl;
		return *this;
	}
	//operator+;
	//operator+=;

	// ����� ��������� � ������� ������ ���
	void print() {
		cout << endl;
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
			cout << Temp->pPrev << tab <<  Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			
		cout << endl << tab << "��������� � list: " << this->size << endl;
	}
	// ����� ��������� � ������� �������� ���
	void printRevers() {
		cout << endl;
		for (Element* Temp = Tail; Temp; 
			Temp = Temp->pPrev)
			cout << Temp->pNext << tab << Temp << tab << Temp->Data << tab << Temp->pPrev << endl;
		
		cout << endl << tab << "��������� � list: " << this->size << endl;
	}
	//_____________________________________________________________________
private:
	class Element {

	public:
		Element(int Data, Element* pNext = nullptr, Element* pPrev = nullptr) :Data(Data), pNext(pNext), pPrev(pPrev) {
			cout << "EConstructor:\t" << this << endl;
		}
		~Element() {
			Data = 0;
			pNext = nullptr;
			pPrev = nullptr;
			cout << "EDestructor:\t" << this << endl;
		}
		friend class List;
	private:
		int Data;
		Element* pNext;
		Element* pPrev;
	};
	Element* Head;
	Element* Tail;
	int size;
};


void main() {
	setlocale(LC_ALL, "");
	int n;
	int i;
	cout << "Input list size: "; cin >> n;
	cout << "�������� �� �������: "; cin >> i;
	List list;
	List list1;
	for (; n > 0; n--) {
		list.push_front(n);
		list1.push_back(n);
	}
	list1= std::move (list);
	list1.print();
//	list.print();
//	list.erase(i);
//	list.insert(58, i);
//	list.print();
	/*list.push_back(5);
	list.print();
	list.pop_back();
	list.print();
	list.pop_front();
	list.print();*/
	list.printRevers();

}