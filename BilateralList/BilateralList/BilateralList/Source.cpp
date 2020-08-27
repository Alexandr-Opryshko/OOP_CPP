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
	//---------------------------------------------------------------------
	// Method
	void push_front(int Data) {
		/*Element* New = new Element(Data);
		New->pNext = Head;
		if (Head == nullptr) {
			Tail = New;
		}
		else Head->pPrev = New;
		Head = New;*/
		if (Head == nullptr && Tail == nullptr) {
		Head = Tail = new Element(Data, Head);
		return;
		}
		Head = Head->pPrev = new Element(Data, Head);
		size++;
	}
	//_____________________________________________________________________
private:
	class Element {

	public:
		Element(int Data, Element* pNext = nullptr, Element* pPrev = nullptr) :Data(Data), pNext(pNext), pPrev(pPrev) {
			cout << "EConstructor:\t" << this << endl;
		}
		~Element() {
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
	List list;
	list.push_front(5);
	list.push_front(3);
	list.push_front(4);

}