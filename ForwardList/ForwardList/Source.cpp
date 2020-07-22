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
		cout << "LConstructor:\t" << this << endl;
	}
	~ForwardList() {
		cout << "LDestructor:\t" << this << endl;
	}
	// Method
	void push_front(int Data) {
		Element* New = new Element(Data);		// создаем новый элемент, и сохраняем в него добавляемое значение
		New->pNext = Head;
		Head = New;
	}
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
	}
	// удаление первого элемента
	void pop_front() {
		Element* Temp = Head;
		if (Temp->pNext) {
			Temp = Temp->pNext;
			Head = Temp;
		}
		else {
			Head = nullptr;
		}
	}
	// удаление последнего элемента
	void pop_back() {
		Element* Temp = Head;
		Element* TempStep = Temp->pNext;
		while (TempStep->pNext) {
			TempStep = TempStep->pNext;
			Temp = Temp->pNext;
		}
		Temp->pNext = nullptr;
	}
	// вставить значение по индексу
	bool insert(int Data, int index) {
		Element* New = new Element(Data);				// создадим элемент
		Element* Temp = Head;							// запишим начальный адрес lista
		Element* TempStep = Temp->pNext;				// запишим адрес следующего элемента lista
		for (int i = 0; i < index - 1; i++) {			// перейдем к указанному индексу
			if (TempStep == nullptr) return false;		// 
			Temp = Temp->pNext;
			TempStep = TempStep->pNext;
		}
		New->pNext = TempStep;
		Temp->pNext = New;

		return true;
	}
	// удаление элемента по индексу
	bool erase(int index) {
		Element* Temp = Head;
		Element* TempStep = Temp->pNext;
		if (index == 0) {
			Head = TempStep;
		}
		else {
			for (int i = 0; i < index - 1; i++) {			// перейдем к указанному индексу
				if (TempStep == nullptr) return false;		// 
				Temp = Temp->pNext;
				TempStep = TempStep->pNext;
			}
			if (TempStep != nullptr) {
				Temp->pNext = TempStep->pNext;
				Temp = TempStep;
			}
			else {
				Temp->pNext = nullptr; 
				return false;
			}
		}
		return true;
	}

	void print() {
		Element* Temp = Head;					// Temp - это итератор (указатель при помощи которого можно
												// получить доступ доступ к элементам структуры данных)
		while (Temp != nullptr) {
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;					// переход на следующий элемент
		}
	}
private:
	Element* Head;
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
		cout << tab << "ОШИБКА ВСТАВКИ ЭЛЕМЕНТА. НАХОДИТСЯ ЗА ПРЕДЕЛАМИ lista" << endl;
	}
	list.print();
	cout << endl;

	if (list.erase(0) == false) {
		cout << tab << "ОШИБКА УДАЛЕНИЯ ЭЛЕМЕНТА. НАХОДИТСЯ ЗА ПРЕДЕЛАМИ lista" << endl;
	}
	list.print();
}