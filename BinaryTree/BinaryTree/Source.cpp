#include<iostream>
using namespace std;
//#define DEBUG
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
	Tree(/*int size, int Data, ...*/const initializer_list<int>& il):Tree() {
#ifdef DEBUG
		cout << "ArbitraryConstructor\t" << this << endl;
#endif // DEBUG
		/*const int* add = &Data;
		for (int i = 0; i < size; i++) {
			insert_(*add, this->Root);
			add++;
		}*/
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
		/*int i = 0;
		int& iterator = i;*/
		return count_(getRoot());
		/*count_(getRoot(), iterator);*/
		//return iterator;
	}
	int sum() {
		/*int a = 0;
		int& sum = a;*/
		return sum_(getRoot()/*, sum*/);
		/*return sum;*/
	}

//////////////////////////////////////////////////////////////////////////////////////////////
////////////////// закрытая реализация методов //////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
private:
	// метод удаления элемента дерева по его значению
	void erase_(int Data, Element* Root) {
		if (Root == nullptr) return;

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
	Tree T800 = { 2,50,20 };
	cout << endl << T800.minValue() << "\t" << T800.maxValue() << endl;
	for (int i = 0; i < n; i++) {
		T800.insert(rand() % 100);
	}
	T800.print();
	cout << endl << T800.minValue() << "\t" << T800.maxValue() << endl;
	cout << T800.sum() << "\t" << T800.count() << endl;
}