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
	
	Tree(){
		Root = nullptr;
#ifdef DEBUG
		cout << "TConstructor\t" << this << endl;
#endif // DEBUG
	}
	Tree(int Data) {
		insert(Data, this->Root);
	}
	~Tree() {
#ifdef DEBUG
		cout << "TDestructor\t" << this << endl;
#endif // DEBUG
	}
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
	int maxValue(Element* Root) {
		if (Root == nullptr) return -1;
		if (Root->pRight) maxValue(Root->pRight);
		else return Root->Data;
	}
	int minValue(Element* Root) {
		if (Root == nullptr) return -1;
		if (Root->pLeft) minValue(Root->pLeft);
		else return Root->Data;
	}
	void print(Element* Root) {
		if (Root == nullptr) return;
		print(Root->pLeft);
		cout << Root->Data << "\t";
		print(Root->pRight);
	}
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
	Tree T800(50);
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