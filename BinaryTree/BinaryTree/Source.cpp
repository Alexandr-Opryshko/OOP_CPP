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
	// конструктор по умолчанию
	Tree(){
		Root = nullptr;
#ifdef DEBUG
		cout << "TConstructor\t" << this << endl;
#endif // DEBUG
	}
	Tree(int size,int Data,...) {
#ifdef DEBUG
		cout << "ArbitraryConstructor\t" << this << endl;
#endif // DEBUG
		const int* add = &Data;
		for (int i = 0; i < size; i++) {
			insert(*add, this->Root);
			add++;
		}
	}
	~Tree() {
		erase(Root);												// удаление элементов дерева
		delete Root;												// удаление корневого элемента
#ifdef DEBUG
		cout << "TDestructor\t" << this << endl;
#endif // DEBUG
	}
	// метод очистки элементов дерева без корневого элемента
	void erase(Element* Root) {
		if (Root == nullptr) return;
		erase(Root->pLeft);
		delete Root->pLeft;
		Root->pLeft = nullptr;
		erase(Root->pRight);
		delete Root->pRight;
		Root->pRight = nullptr;
	}
	// метод добавления новых элементов в дерево
	void insert(int Data, Element* Root) {
		if (this->Root == nullptr) {								// если это добавляется первый элемент
			this->Root = new Element(Data);							// создаем первый элемент
			return;													// и выходим
		}
		if (Root == nullptr) return;								// условие выхода
		if (Data < Root->Data) {									// если значение меньше добавляемого
			if (Root->pLeft) insert(Data, Root->pLeft);				// если есть ответвление перейдем к следующему элементу
			else Root->pLeft = new Element(Data);					// иначе создадим новый элемент
		}
		else {														// иначе значение больше добавляемого
			if (Root->pRight) insert(Data, Root->pRight);			// если есть ответвление перейдем к следующему элементу
			else Root->pRight = new Element(Data);					// иначе создадим новый элемент
		}
	}
	// метод поиска максимального значения
	int maxValue(Element* Root) {
		if (Root == nullptr) return -1;								// если дерево пустое
		if (Root->pRight) maxValue(Root->pRight);					// иначе идем к максимальному значению
		else return Root->Data;										// возвращаем максимальное значение
	}
	// метод поиска минимального значения
	int minValue(Element* Root) {
		if (Root == nullptr) return -1;								// если дерево пустое
		if (Root->pLeft) minValue(Root->pLeft);						// иначе идем к минимальному значению
		else return Root->Data;										// возвращаем минимальное значение
	}
	// метод вывода элементов дерева на экран
	void print(Element* Root) {
		if (Root == nullptr) return;
		print(Root->pLeft);
		cout << Root->Data << "\t";
		print(Root->pRight);
	}
	// метод расчета размерности дерева
	int sizeTree(Element* Root) {
		int i = 0;
		int& iterator = i;
		sizeTree_(Root, iterator);
		return iterator;
	}
	void sizeTree_(Element* Root, int& iterator) {
		if (Root == nullptr) return;
		sizeTree_(Root->pLeft, iterator);
		iterator++;
		sizeTree_(Root->pRight, iterator);
	}
	// метод расчета суммы элементов дерева
	int sum(Element* Root) {
		int a = 0;
		int& sum = a;
		sum_(Root,sum);
		return sum;
	}
	void sum_(Element* Root, int& tempData) {
		if (Root == nullptr) 
			return;
		sum_(Root->pLeft, tempData);
		tempData += Root->Data;
		sum_(Root->pRight, tempData);
	}
};



void main() {
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер дерева - "; cin >> n; cout << endl;
	Tree T800 = { 2,50,20 };
	cout << endl << T800.minValue(T800.getRoot()) << "\t" << T800.maxValue(T800.getRoot()) << endl;
	for (int i = 0; i < n; i++) {
		T800.insert(rand() % 100, T800.getRoot());
	}
	T800.print(T800.getRoot());
	cout << endl << T800.minValue(T800.getRoot()) << "\t" << T800.maxValue(T800.getRoot()) << endl;
	int sum = T800.sum(T800.getRoot());
	int iterator = T800.sizeTree(T800.getRoot());
	cout << sum << "\t" << iterator << endl;
}