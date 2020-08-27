#include<iostream>
using namespace std;


class List {
public:
	List() {
		Head = Tail = nullptr;
		size = 0;
		cout << "LConstructor:\t" << this << endl;
	}
	~List() {
		cout << "LDestructor:\t" << this << endl;
	}

private:
	class Element {

	public:
		Element(int Data, Element* pNext = nullptr, Element* pPrev = nullptr) :Data(Data), pNext(pNext), pPrev(pPrev) {
			cout << "EConstructor:\t" << this << endl;
		}
		~Element() {
			cout << "EDestructor:\t" << this << endl;
		}
	private:
		int Data;
		Element* pNext;
		Element* pPrev;
	};
	Element* Head;
	Element* Tail;
	int size;
};

List::List() {
}

List::~List() {
}

void main() {
	setlocale(LC_ALL, "");
	List list;

}