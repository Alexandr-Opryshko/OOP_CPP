#include<iostream>
using namespace std;

class Element {
public:
	Element(int Data, Element* pPrev = nullptr, Element* pNext = nullptr) :Data(Data), pPrev(pPrev), pNext(pNext) {

		cout << "EConstructor:\t" << this << endl;
	}

	~Element() {
		Data = 0;
		pNext = nullptr;
		pPrev = nullptr;
		cout << "EDestructor:\t" << this << endl;
	}

	friend class ForwardList;
	friend class Iterator;

private:
	int Data;
	Element* pNext;
	Element* pPrev;
};

class Iterator {
public:
	Iterator();
	~Iterator();

private:
	Element* Temp;
};
class ForwardList {
public:
	ForwardList() {
		this->Head = nullptr;
		this->IndexList = 0;
		cout << "LConstructor:\t" << this << endl;
	}
	~ForwardList() {
		cout << "Destructor:\t" << this << endl;
	}
	// конструктор с переменным колличеством параметров
	ForwardList(const std::initializer_list<int>& il) {
		cout << "ConstructorVariableParameters:\t" << this << endl;
		for (const int* it = il.begin(); it != il.end(); it++) {
//			push_back(*it);
		}
	}
	// конструктор копирования
	ForwardList(const ForwardList& Head) {
		cout << "CopyConstructor:\t" << this << endl;
		this->Head = nullptr;
		this->IndexList = 0;
//		push_back_list(Head.Head);
	}
	// Конструктор на заданное колличество элементов
	ForwardList(int size) {
		cout << "ConstructorGivenQuantityParameters:\t" << this << endl;
		while (size--) {
			push_front(0);
		}
	}

	// Method
	// добавить в начало списка
	void push_front(int Data) {
		Head = new Element(Data, Head);
		IndexList++;
	}

private:
	Element* Head;
	Element* Tail;
	int IndexList;
};

void main() {
	setlocale(LC_ALL, "");
	ForwardList list;

}