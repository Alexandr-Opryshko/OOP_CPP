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
	// замена Temp != nulptr на Temp
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
	// конструктор по умолчанию 
	ForwardList() {
		this->Head = nullptr;
		this->IndexList = 0;
#ifdef DEBUG
		cout << "LConstructor:\t" << this << endl;
#endif // DEBUG

	}
	// деструктор
	~ForwardList() {
		while (Head != nullptr) pop_front();
#ifdef DEBUG
		cout << "LDestructor:\t" << this << endl;
#endif // DEBUG

	}
	// конструктор с переменным колличеством параметров
	ForwardList(const std::initializer_list<int> & il) {
		cout << "ConstructorVariableParameters:\t" << this << endl;
		for (const int* it = il.begin(); it != il.end(); it++) {
			push_back(*it);
		}
	}
	// конструктор копирования
	ForwardList(const ForwardList &Head) {
		cout << "CopyConstructor:\t" << this << endl;
		this->Head = nullptr;
		this->IndexList = 0;
		push_back_list(Head.Head);
	}
	// Конструктор на заданное колличество элементов
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
			this->IndexList = 0;				// колличество элементов
			return false;						// дальнейшая работа запрещена
		}
		return true;
	}
	// добавить в начало списка
	void push_front(int Data) {
		Head = new Element(Data, Head);
		this->IndexList++;						// увеличим счетчик элементов на один
	}
	// добавить в конец списка
	void push_back(int Data) {
		if (Head == nullptr) {						// если колличество элементов 0
			push_front(Data);						// создадим первый элемент
			return;									// и выйдем
		}
		Element* Temp = Head;						// копируем адрес начала списка элементов
		while (Temp->pNext) {						// проходим по каждому элементу в конец списка
			Temp = Temp->pNext;
		}
		Temp->pNext = new Element(Data);			// создадим и запишим адрес нового элемента
		this->IndexList++;							// увеличим счетчик элементов на 1
	}
	// добавляет в конец весь лист
	void push_back_list(Element* Head) {
		if (Head == Head) return;
		for (Element* Temp1 = Head; Temp1;Temp1 = Temp1->pNext) {
			this->push_back(Temp1->Data);
		}
	}
	// удаление первого элемента
	void pop_front() {
		if(ErrDelElementList() == false) return;	// проверка наличия больше чем одного элемента в списке
		Element* to_del = Head;						// запоминаем адрес удаляемого элемента
		Head = Head->pNext;							// исключаем элемент из списка
		delete to_del;								// удаляем элемент из памяти
		this->IndexList--;							// уменьшим список на 1 элемент
	}
	// удаление последнего элемента
	void pop_back() {
		if (ErrDelElementList() == false) return;	// проверка наличия больше чем одного элемента в списке
		Element* Temp = Head;						// скопируем начальный адрес листа
		while (Temp->pNext->pNext) {				// дойдем до последнего элемента листа
			Temp = Temp->pNext;						// меняя адрес текующего элемента
		}
		delete Temp->pNext;							// удалим последний элемент
		Temp->pNext = nullptr;						// очистим адрес последующего элемента в текущем
		this->IndexList--;							// и уменьшим индекс колличества элементов
		return;
	}
	// вставить значение по индексу
	void insert(int Data, int index) {
		while (this->IndexList < index) {				// если индек находится за пределами листа
			push_back(0);								// добавляем в конец листа пустые элементы пока не дойдем до индекса вставки
		}
		if (index == 0) {
			push_front(Data);
			return;
		}
		Element* Temp = Head;							// запишим начальный адрес lista
		for (int i = 0; i < index - 1; i++) {			// перейдем к указанному индексу
			Temp = Temp->pNext;							// перейдем к следующему элементу
		}

		Temp->pNext = new Element(Data, Temp->pNext);	// вставим вновь созданный элемент
		this->IndexList++;								// инкремент числа элементов

		return;
	}
	// удаление элемента по индексу
	bool erase(int index) {
		if (this->IndexList <= index) return false;		// выйдем с предупреждением о нахождении индекса за пределами списка
		Element* Temp = Head;							// запишим начальный адрес листа

		for (int i = 0; i < index - 1; i++) {			// перейдем к элементу по индексу
			Temp = Temp->pNext;
		}
		Element* to_del = Temp->pNext;					// запишим удаляемый элемент
		Temp->pNext = Temp->pNext->pNext;				// запишим адрес следующего за удаляемым элементом
		delete to_del;									// удалим элемент

		if (this->IndexList != 0)						// если количество больше 0
			this->IndexList--;							// произведем декримент числа элементов
		return true;									// выйдем с удачным удалением элемента
	}
	// вывод элементов в консоль
	void print() {
		/*for (Element* Temp = Head; Temp; Temp = Temp->pNext)
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;*/
		/*for (Iterator Temp = begin(); Temp != end(); Temp++)
			cout << *Temp << endl;*/
		for (int i : *this) {
			cout << i << endl;
		}
		cout << endl << tab << "Элементов в list: "<<this->IndexList << endl;
	}
	// оператор присвоить
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
	// оператор сложения
	ForwardList operator +(const ForwardList& Head) const {
		ForwardList temp;
		temp.push_back_list(this->Head);
		temp.push_back_list(Head.Head);
		return temp;
	}
	// оператор перехода по индексу
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


//В класс ForwardList добавить :
//							1. Деструктор;
//							2. Конструктор копирования;
//							3. Оператор присваивания;
//							4. Оператор + , который будет конкатенировать списки;
//							5. MoveMethods;
//							6. Конструктор на заданное число элементов ForwardList list(5), элементы должны быть заполнены нулями;
//							7. Оператор[];
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
	//ForwardList list2 = {5,1,2,3,4,5 };	// 0-й колличество элементов, и данные
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
	//	cout << tab << "ОШИБКА ВСТАВКИ ЭЛЕМЕНТА. НАХОДИТСЯ ЗА ПРЕДЕЛАМИ lista" << endl;
	//}
	//list.print();
	//cout << endl;

	////if (list.erase(4) == false) {
	////	cout << tab << "ОШИБКА УДАЛЕНИЯ ЭЛЕМЕНТА. НАХОДИТСЯ ЗА ПРЕДЕЛАМИ lista" << endl;
	////}
	////list.print();


	//cout << "На сколько элементов очистить лист: "; cin >> n;
	//for (int i = 0; i < n; i++) {
	//	list.pop_back();
	//	list.print();
	//}
}