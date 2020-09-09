#include"Header.h"

//################################################## реализация LIST
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
// конструктор
List::List() {
	Head = Tail = nullptr;
	size = 0;
	cout << "LConstructor:\t" << this << endl;
}
// конструктор копирования
List::List(const List& other) :List() {
	for (Element* Temp = other.Head;Temp;Temp = Temp->pNext)
		push_back(Temp->Data);
}
// конструктор с переменным колличеством параметров
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
// добавить в начало списка
void List::push_front(int Data) {
	if (Head == nullptr && Tail == nullptr)						// если список пустой
		Head = Tail = new Element(Data);						// то для начала и хвоста присвоим адрес элемента
	else Head = Head->pPrev = new Element(Data, Head);			// иначе указателю первого элемента  и голове присвоим адрес нового элемента
	size++;														// увеличим список на 1 элемент
}
// удаление первого элемента
void List::pop_front() {
	if (Head == nullptr && Tail == nullptr) return;				// проверка наличия элементов в списке
	else if (size == 1) {										// если остался последний элемент
		delete Tail;											// удалим элемент
		Head = Tail = nullptr;									// и очистим указатели
	}
	else {														// иначе больше чем один элемент в списке
		this->Head = Head->pNext;								// исключаем элемент из списка
		delete Head->pPrev;										// удаляем элемент из памяти
		Head->pPrev = nullptr;									// и очищаем указатель на удаленный элемент
	}
	size--;														// уменьшим список на 1 элемент
}
// добавить в конец списка
void List::push_back(int Data) {
	if (Head == nullptr && Tail == nullptr)						// если список пустой
		Head = Tail = new Element(Data);						// то для начала и хвоста присвоим адрес элемента
	else Tail = Tail->pNext = new Element(Data, nullptr, Tail);	// иначе указателю последнего элемента  и хвосту присвоим адрес нового элемента
	size++;														// увеличим список на 1 элемент
}
// удаление последнего элемента
void List::pop_back() {
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
bool List::insert(int data, int index) {
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
bool List::erase(int index) {
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
List& List::operator =(const List& Head) {
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
List& List::operator =(List&& Head) {
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
// вывод элементов в консоль прямой ход
void List::print() {
	cout << endl;
	//for (Element* Temp = Head; Temp; Temp = Temp->pNext)
		//cout << Temp->pPrev << tab <<  Temp << tab << Temp->Data << tab << Temp->pNext << endl;
	for (Iterator it = Head; it; it++)
		cout << *it << endl;

	cout << endl << tab << "Элементов в list: " << this->size << endl;
}
// вывод элементов в консоль обратный ход
void List::printRevers() {
	cout << endl;
	/*for (Element* Temp = Tail; Temp; Temp = Temp->pPrev)
		cout << Temp->pNext << tab << Temp << tab << Temp->Data << tab << Temp->pPrev << endl;
	*/
	for (ReversIterator it = Tail; it; it++)
		cout << *it << endl;

	cout << endl << tab << "Элементов в list: " << this->size << endl;
}
