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
	// добавить в начало списка
	void push_front(int Data) {
		Element* New = new Element(Data);		// создаем новый элемент, и сохран€ем в него добавл€емое значение
		New->pNext = Head;
		Head = New;
		this->IndexList++;
	}
	// добавить в конец списка
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
	// удаление первого элемента
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
	// удаление последнего элемента
	void pop_back() {
		if(this->IndexList <= 1){						// если элементов 0 или 1
			Head = nullptr;								// просто очистим указатель
			this->IndexList = 0;						// и колличество элементов
			return;
		}
		Element* Temp = Head;							// скопируем начальный адрес листа
		Element* TempStep = Temp->pNext;				// скопируем последующий адрес элемента листа
		while (TempStep->pNext) {						// дойдем до последнего элемента листа
			TempStep = TempStep->pNext;					// мен€€ адрес последующего элемента
			Temp = Temp->pNext;							// мен€€ адрес текующего элемента
		}
		Temp->pNext = nullptr;							// очистим адрес последующего элемента в текущем
		this->IndexList--;								// и уменьшим индекс колличества элементов
		return;
	}
	// вставить значение по индексу
	bool insert(int Data, int index) {
		if (this->IndexList < index) return false;		// выйдем с предупреждением о нахождении индекса за пределами списка
		Element* New = new Element(Data);				// создадим элемент
		Element* Temp = Head;							// запишим начальный адрес lista
		Element* TempStep = Temp->pNext;				// запишим адрес следующего элемента lista
		for (int i = 0; i < index - 1; i++) {			// перейдем к указанному индексу
			Temp = Temp->pNext;							// перейдем к следующему элементу
			TempStep = TempStep->pNext;					// перейдем к последующему элементу
		}
		New->pNext = TempStep;							// произведем запись в элемент последующего элемента
		Temp->pNext = New;								// а в предыдущий адрес нового элемента
		this->IndexList++;

		return true;
	}
	// удаление элемента по индексу
	bool erase(int index) {
		if (this->IndexList <= index) return false;		// выйдем с предупреждением о нахождении индекса за пределами списка
		Element* Temp = Head;							// запишим начальный адрес листа
		Element* TempStep = Temp->pNext;				// и последующего элемента
		if (index == 0) {								// если удал€етс€ 0-й элемент
			Head = TempStep;
		}
		else {
			for (int i = 0; i < index - 1; i++) {		// перейдем к указанному элементу по индексу
				if (TempStep == nullptr) return false;	// если конец листа - выйдем с предупреждением
				Temp = Temp->pNext;						// переход к следующему элементу
				TempStep = TempStep->pNext;				// переход к последующему элементу
			}
			if (TempStep != nullptr) {					// если это не последний элемент
				Temp->pNext = TempStep->pNext;			// запишим адрес элемента хран€щегос€ в последующем
				Temp = TempStep;						// и удалим элемент перезаписав адрес последующего
			}
			else {										// иначе
				Temp->pNext = nullptr;					// запишим конечный адрес листа
				return false;							// и выйдем с предупреждением что это конец списка
			}
		}
		if (this->IndexList != 0)
			this->IndexList--;
		return true;										// выйдем с удачным удалением элемента
	}

	void print() {
		Element* Temp = Head;					// Temp - это итератор (указатель при помощи которого можно
												// получить доступ доступ к элементам структуры данных)
		while (Temp != nullptr) {
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;					// переход на следующий элемент
		}

		cout << endl << tab << "Ёлементов в list: "<<this->IndexList << endl;
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
		cout << tab << "ќЎ»Ѕ ј ¬—“ј¬ » ЁЋ≈ћ≈Ќ“ј. Ќј’ќƒ»“—я «ј ѕ–≈ƒ≈Ћјћ» lista" << endl;
	}
	list.print();
	cout << endl;

	if (list.erase(4) == false) {
		cout << tab << "ќЎ»Ѕ ј ”ƒјЋ≈Ќ»я ЁЋ≈ћ≈Ќ“ј. Ќј’ќƒ»“—я «ј ѕ–≈ƒ≈Ћјћ» lista" << endl;
	}
	list.print();

	cout << "Ќа сколько элементов очистить лист: "; cin >> n;
	for (int i = 0; i < n; i++) {
		list.pop_back();
		list.print();
	}
}