#include<iostream>
using namespace std;
#define DEBUG
class Tree {
private:
	
	class Element {
	private:
		int Data;
		
		Element* pLeft;
		Element* pRight;
	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr) :
			Data(Data), pLeft(pLeft), pRight(pRight) {
#ifdef DEBUG
			cout << "EConstructor\t" << this << endl;
#endif // DEBUG
		}
		~Element() {

#ifdef DEBUG
			cout << "EDestructor\t" << this << endl;
#endif // DEBUG
		}

		friend class Tree;
	}*Root;

public:

	Element* getRoot() {
		return Root;
	}
//////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////// Конструкторы /////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
	// конструктор по умолчанию
	Tree() {
		Root = nullptr;
#ifdef DEBUG
		cout << "TConstructor\t" << this << endl;
#endif // DEBUG
	}
	Tree(int Data) {
#ifdef DEBUG
		cout << "DataConstructor\t" << this << endl;
#endif // DEBUG
		insert_(Data, this->Root);
	}
	Tree(const initializer_list<int>& il):Tree() {
#ifdef DEBUG
		cout << "ArbitraryConstructor\t" << this << endl;
#endif // DEBUG
		for (int i : il) {
			insert(i);
		}
	}
	~Tree() {
		erase_(Root);												// удаление элементов дерева
		delete Root;												// удаление корневого элемента
#ifdef DEBUG
		cout << "TDestructor\t" << this << endl;
#endif // DEBUG
	}

//////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////// обертка методов //////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
	void erase(int Data) {
		erase_(Data, getRoot());
	}
	// метод удаления элементов дерева
	void erase() {
		erase_(getRoot());
	}
	// метод добавления новых элементов в дерево
	void insert(int Data) {
		insert_(Data, getRoot());			// если есть ответвление перейдем к следующему элементу
	}
	// метод поиска максимального значения
	int maxValue() {
		return maxValue_(getRoot());					// иначе идем к максимальному значению
	}
	// метод поиска минимального значения
	int minValue() {
		return minValue_(getRoot());						// иначе идем к минимальному значению
	}
	// метод вывода элементов дерева на экран
	void print() {
		print_(getRoot());
	}
	int count() {
		return count_(getRoot());
	}
	int sum() {
		return sum_(getRoot());
	}

//////////////////////////////////////////////////////////////////////////////////////////////
////////////////// закрытая реализация методов //////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
private:
	// метод удаления элемента дерева по его значению
	void erase_(int Data, Element* Root) {
		if (Root == nullptr) return;
		else if (Root->Data == Data && !Root->pLeft && !Root->pRight) {
			delete Root;
			this->Root = nullptr;
			return;
		}
		else if (Root->Data == Data && Root->pLeft) {
			Element* Temp = Root->pLeft;
			if (Temp->pRight != nullptr) {
				insertMax(Temp->pRight, Root->pRight);
			}
			else Temp->pRight = Root->pRight;

			delete Root;
			this->Root = Temp;
		}
		else if (Root->Data == Data && Root->pRight) {
			Element* Temp = Root->pRight;
			if (Temp->pLeft != nullptr) {
				insertMin(Temp->pLeft, Root->pLeft);
			}
			else Temp->pLeft = Root->pLeft;
			delete Root;
			this->Root = Temp;
		}
		else if (Data > Root->Data && Root->pRight && Data != Root->pRight->Data) erase_(Data, Root->pRight);
		else if (Data < Root->Data && Root->pLeft && Data != Root->pLeft->Data) erase_(Data, Root->pLeft);
		else {
			
			if (Root->pRight && Data == Root->pRight->Data) {
				Element* Temp = Root->pRight;
				Root->pRight = Root->pRight->pLeft;
				if (Root->pRight != nullptr) {
					insertMax(Root->pRight, Temp->pRight);
				}
				delete Temp;
			}
			if (Root->pLeft && Data == Root->pLeft->Data) {
				Element* Temp = Root->pLeft;
				Root->pLeft = Root->pLeft->pRight;
				if (Root->pLeft != nullptr) {
					insertMin(Root->pLeft, Temp->pLeft); 
				}
				delete Temp;
			}
		}
	}
	void insertMin(Element* Root, Element* add) {
		if (Root == nullptr) return;
		else if (Root->pLeft == nullptr) {
			Root->pLeft = add;
			return;
		}
		else insertMin(Root->pLeft, add);
	}
	void insertMax(Element* Root, Element* add) {
		if (Root == nullptr) return;
		else if (Root->pRight == nullptr) {
			Root->pRight = add;
			return;
		}
		else insertMax(Root->pRight, add);
	}
	// метод очистки элементов дерева без корневого элемента
	void erase_(Element* Root) {
		if (Root == nullptr) return;
		erase_(Root->pLeft);
		delete Root->pLeft;
		Root->pLeft = nullptr;
		erase_(Root->pRight);
		delete Root->pRight;
		Root->pRight = nullptr;
	}
	// метод добавления новых элементов в дерево
	void insert_(int Data, Element* Root) {
		if (this->Root == nullptr) {								// если это добавляется первый элемент
			this->Root = new Element(Data);							// создаем первый элемент
			return;													// и выходим
		}
		if (Root == nullptr) return;								// условие выхода
		if (Data < Root->Data) {									// если значение меньше добавляемого
			if (Root->pLeft) insert_(Data, Root->pLeft);			// если есть ответвление перейдем к следующему элементу
			else Root->pLeft = new Element(Data);					// иначе создадим новый элемент
		}
		else {														// иначе значение больше добавляемого
			if (Root->pRight) insert_(Data, Root->pRight);			// если есть ответвление перейдем к следующему элементу
			else Root->pRight = new Element(Data);					// иначе создадим новый элемент
		}
	}
	// метод поиска максимального значения
	int maxValue_(Element* Root) {
		return Root ? Root->pRight ? maxValue_(Root->pRight) : Root->Data : int();
		//if (Root == nullptr) return -1;								// если дерево пустое
		//if (Root->pRight) maxValue_(Root->pRight);					// иначе идем к максимальному значению
		//else return Root->Data;										// возвращаем максимальное значение
	}
	// метод поиска минимального значения
	int minValue_(Element* Root) {
		return Root ? Root->pLeft ? minValue_(Root->pLeft) : Root->Data : int();
	}
	// метод вывода элементов дерева на экран
	void print_(Element* Root) {
		if (Root == nullptr) return;
		print_(Root->pLeft);
		cout << Root->Data << "\t";
		print_(Root->pRight);
	}
	// метод расчета размерности дерева
	int count_(Element* Root) {
		if (Root == nullptr) return 0;
		if (Root->pLeft == Root->pRight) return 1;
		else {
			return 1 + count_(Root->pLeft) + count_(Root->pRight);
		}
	}
	// метод расчета суммы элементов дерева
	int sum_(Element* Root) {
		if (Root == nullptr) return 0;
		if (Root->pLeft == Root->pRight) return Root->Data;
		else return Root->Data + sum_(Root->pLeft) + sum_(Root->pRight);
	}
};


void main() {

	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер дерева - "; cin >> n; cout << endl;
	/*Tree T801;
	cout << endl << T801.minValue() << "\t" << T801.maxValue() << endl;

	T801.print();*/
	Tree T800 = { 50,39,80,48,12,56,102,2,20,45,49,41,47,40 };
	T800.print();cout << endl;
	T800.erase(2);
	T800.erase(20);
	T800.erase(12);
	T800.erase(40);
	T800.erase(41);
	T800.erase(47);
	T800.erase(45);
	T800.erase(49);
	T800.erase(48);
	T800.erase(39);
	T800.erase(50);/*
	T800.erase(56);
	T800.erase(102);*/
	//T800.erase(80);
	
	/*cout << endl << T800.minValue() << "\t" << T800.maxValue() << endl;
	for (int i = 0; i < n; i++) {
		T800.insert(rand() % 100);
	}*/
	T800.print();cout << endl;
	//cout << endl << T800.minValue() << "\t" << T800.maxValue() << endl;
	//cout << T800.sum() << "\t" << T800.count() << endl;
}