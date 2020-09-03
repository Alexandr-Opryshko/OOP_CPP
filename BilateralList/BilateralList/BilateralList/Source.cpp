#include<iostream>
using namespace std;
#define tab	"\t"

class List {
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
		// замена Temp != nulptr на Temp
		operator bool()const {
			return Temp;
		}
		friend class Element;
		friend class List;
	private:
		Element* Temp;
	};

	Element* Head;
	Element* Tail;
	int size;
public:
	Iterator begin() {
		return Head;
	}
	Iterator end() {
		return nullptr;
	}

	List() {
		Head = Tail = nullptr;
		size = 0;
		cout << "LConstructor:\t" << this << endl;
	}
	// конструктор копирования
	List(const List& other) :List() {
		for (Element* Temp = other.Head;Temp;Temp = Temp->pNext)
			push_back(Temp->Data);
	}
	// конструктор с переменным колличеством параметров
	List(const std::initializer_list<int>& il) {
		for (const int* it = il.begin(); it != il.end(); it++) {
			push_back(*it);
		}
		cout << "ConstructorVariableParameters:\t" << this << endl;
	}
	~List() {
		while (Head != nullptr) pop_front();
		size = 0;
		cout << "LDestructor:\t" << this << endl;
	}
	//---------------------------------------------------------------------
	// Method
	// добавить в начало списка
	void push_front(int Data) {
		if (Head == nullptr && Tail == nullptr)						// если список пустой
			Head = Tail = new Element(Data);						// то для начала и хвоста присвоим адрес элемента
		else Head = Head->pPrev = new Element(Data, Head);			// иначе указателю первого элемента  и голове присвоим адрес нового элемента
		size++;														// увеличим список на 1 элемент
	}
	// удаление первого элемента
	void pop_front() {
		if (Head == nullptr && Tail == nullptr) return;				// проверка наличия элементов в списке
		else if (size == 1) {										// если остался последний элемент
			delete Tail;											// удалим элемент
			Head = Tail = nullptr;									// и очистим указатели
		}
		else {														// иначе больше чем один элемент в списке
			Head = Head->pNext;										// исключаем элемент из списка
			delete Head->pPrev;										// удаляем элемент из памяти
			Head->pPrev = nullptr;									// и очищаем указатель на удаленный элемент
		}
		size--;														// уменьшим список на 1 элемент
	}
	// добавить в конец списка
	void push_back(int Data) {
		if (Head == nullptr && Tail == nullptr)						// если список пустой
			Head = Tail = new Element(Data);						// то для начала и хвоста присвоим адрес элемента
		else Tail = Tail->pNext = new Element(Data, nullptr, Tail);	// иначе указателю последнего элемента  и хвосту присвоим адрес нового элемента
		size++;														// увеличим список на 1 элемент
	}
	// удаление последнего элемента
	void pop_back() {
		if (Head == nullptr && Tail == nullptr) return;				// если список пустой
		else if (size == 1) {										// если остался последний элемент
			delete Tail;											// удалим элемент
			Head = Tail = nullptr;									// и очистим указатели
		}
		else {														// иначе в списке более одного элемента
			Tail = Tail->pPrev;										// запишим в хвост адрес предпоследнего элемента
			delete Tail->pNext;										// удалим последний элемент
			Tail->pNext = nullptr;									// и очистим указатель на удаленный элемент
		}
		size--;														// уменьшим колличество элементов в списке на один
	}
	// вставить значение по индексу
	bool insert(int data, int index) {
		if (index > (size) || index < 0) return false;
		else if (index == 0) {										// если вставка на место первого элемента
			push_front(data); return true;							// то вызовем метод
		}
		else if (index == size) {									// если вставка на место последнего элемента
			push_back(data); return true;							// то вызовем метод
		}
		else if ((size / 2) >= index) {								// если вставка до середины списка
			Element* Temp = Head;									// возьмем адрес головы листа
			while (index--) {										// дойдем до указанного места
				Temp = Temp->pNext;									// по списку
			}
			Temp->pPrev->pPrev->pNext = Temp->pPrev = new Element(data, Temp, Temp->pPrev);
		}
		else {														// иначе индекс ближе к хвосту
			Element* Temp = Tail;									// возьмем адрес хвоста
			index = size - index - 1;								// установим значение счетчика с хвоста
			while (index--) {										// дойдем до указанного места
				Temp = Temp->pPrev;									// по списку
			}
			Temp->pPrev->pPrev->pNext = Temp->pPrev = new Element(data, Temp, Temp->pPrev);
		}
		size++;														// увеличим список на 1 элемент
		return true;
	}
	// удаление элемента по индексу
	bool erase(int index) {
		if (index > (size - 1) || index < 0) return false;			// индекс за пределами списка
		else if (index == 0) {										// если удаление первого элемента
			pop_front(); return true;								// то вызовем метод
		}
		else if (index == size - 1) {								// если удаление последнего элемента
			pop_back(); return true;								// то вызовем метод
		}
		else if ((size / 2) >= index) {								// если удаление до середины списка
			Element* Temp = Head;									// возьмем адрес головы листа
			while (index--) {										// дойдем до указанного места
				Temp = Temp->pNext;									// по списку
			}
			Temp->pPrev->pNext = Temp->pNext;						// 
			Temp->pNext->pPrev = Temp->pPrev;						// 
			delete Temp;
		}
		else {														// иначе индекс ближе к хвосту
			Element* Temp = Tail;									// возьмем адрес хвоста
			index = size - index - 1;								// установим значение счетчика с хвоста
			while (index--) {										// дойдем до указанного места
				Temp = Temp->pPrev;									// по списку
			}
			Temp->pPrev->pNext = Temp->pNext;
			Temp->pNext->pPrev = Temp->pPrev;
			delete Temp;
		}
		size--;														// уменьшим список на 1 элемент
		return true;
	}
	//CopyMethods;
	List& operator =(const List& Head) {
		if (this->Head == Head.Head)return *this;
		if (this->Head == nullptr && this->Tail == nullptr) {					// если список пуст
			this->Head = this->Tail = new Element(Head.Head->Data);				// запишим первый элемент
			this->size = 1;														// отметим колличество элементов
			for (Element* temp = Head.Head->pNext; temp;temp = temp->pNext) {	// запишим остальные данные списка
				Tail = Tail->pNext = new Element(temp->Data, nullptr, Tail);
				size++;
			}
		}
		else if (this->size >= Head.size) {										// если переданные список меньше или равен приемному
			int sizeTemp = 0;
			Element* TempThis = this->Head;										// возьмем адрес приемного списка
			Element* Temp = Head.Head;											// возьмем адрес передаваемогосписка
			for (int i = 0; i < Head.size; i++) {								// выполняем пока не перезапишим приемный список
				TempThis->Data = Temp->Data;									// данными переданного списка
				TempThis = TempThis->pNext;										// переход к следующему элементу приемного списка
				Temp = Temp->pNext;												// переход к следующему элементу передающего списка
				sizeTemp++;
			}
			while (sizeTemp != this->size) {									// удаляем лишние элементы
				pop_back();														// через метод
			}
		}
		else {																	// иначе приемный список меньше
			Element* TempThis = this->Head;										// возьмем адрес приемного списка
			Element* Temp = Head.Head;											// возьмем адрес передаваемогосписка
			for (int i = 0; i < size; i++) {									// выполняем пока не перезапишим приемный список
				TempThis->Data = Temp->Data;									// данными переданного списка
				TempThis = TempThis->pNext;										// переход к следующему элементу приемного списка
				Temp = Temp->pNext;												// переход к следующему элементу передающего списка
			}
			for (; Temp; Temp = Temp->pNext) {									// добавление элементов
				push_back(Temp->Data);											// через метод
			}
		}
		cout << "AssignConstructor:\t" << this << endl;
		return *this;
	}
	//MoveMethods;
	List& operator =(List&& Head) {
		if (this->Head == Head.Head)return *this;
		if (this->Head == nullptr && this->Tail == nullptr) {					// если список пуст
			this->Head = this->Tail = new Element(Head.Head->Data);				// запишим первый элемент
			this->size = 1;														// отметим колличество элементов
			for (Element* temp = Head.Head->pNext; temp;temp = temp->pNext) {	// запишим остальные данные списка
				Tail = Tail->pNext = new Element(temp->Data, nullptr, Tail);
				size++;
			}
		}
		else if (this->size >= Head.size) {										// если переданные список меньше или равен приемному
			int sizeTemp = 0;
			Element* TempThis = this->Head;										// возьмем адрес приемного списка
			Element* Temp = Head.Head;											// возьмем адрес передаваемогосписка
			for (int i = 0; i < Head.size; i++) {								// выполняем пока не перезапишим приемный список
				TempThis->Data = Temp->Data;									// данными переданного списка
				TempThis = TempThis->pNext;										// переход к следующему элементу приемного списка
				Temp = Temp->pNext;												// переход к следующему элементу передающего списка
				sizeTemp++;
			}
			while (sizeTemp != this->size) {									// удаляем лишние элементы
				pop_back();														// через метод
			}
		} 
		else {																	// иначе приемный список меньше
			Element* TempThis = this->Head;										// возьмем адрес приемного списка
			Element* Temp = Head.Head;											// возьмем адрес передаваемогосписка
			for (int i = 0; i < size; i++) {									// выполняем пока не перезапишим приемный список
				TempThis->Data = Temp->Data;									// данными переданного списка
				TempThis = TempThis->pNext;										// переход к следующему элементу приемного списка
				Temp = Temp->pNext;												// переход к следующему элементу передающего списка
			}
			for (; Temp; Temp = Temp->pNext) {									// добавление элементов
				push_back(Temp->Data);											// через метод
			}
		}
		cout << "MoveAssignment\t\t" << this << endl;
		return *this;
	}
	//operator+;
	List operator +(const List& Head) const{
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
	void operator +=(const List& Head) {
		for (Element* temp = Head.Head; temp; temp = temp->pNext) {
			push_back(temp->Data);
		}
	}
	// вывод элементов в консоль прямой ход
	void print() {
		cout << endl;
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
			cout << Temp->pPrev << tab <<  Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			
		cout << endl << tab << "Элементов в list: " << this->size << endl;
	}
	// вывод элементов в консоль обратный ход
	void printRevers() {
		cout << endl;
		for (Element* Temp = Tail; Temp; Temp = Temp->pPrev)
			cout << Temp->pNext << tab << Temp << tab << Temp->Data << tab << Temp->pPrev << endl;
		
		cout << endl << tab << "Элементов в list: " << this->size << endl;
	}
	//_____________________________________________________________________

};


void main() {
	setlocale(LC_ALL, "");
	int n;
	int i;
	/*cout << "Input list size: "; cin >> n;
	cout << "Вставить по индексу: "; cin >> i;*/
	List list = { 5,2,3,4,6 };
	list = list + list;
	list.print();
	list.printRevers();

	for (int i : list) {
		cout << i << "\t";
	}

	//List list1;
	//for (; n > 0; n--) {
	//	list.push_front(n);
	//	list1.push_back(n);
	//}
	/*list.push_back(32);
	list.push_back(54);
	list.push_back(43);*/
	//list.print();
	//list1.print();
	//list = list;
//	list1 = list1 + list1;
//	list.print();
//	list1 += list;
//	list1= std::move (list);
//	list1.print();
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
//	list.printRevers();

}