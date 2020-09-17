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
/////////////////////////// ������������ /////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
	// ����������� �� ���������
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
		erase_(Root);												// �������� ��������� ������
		delete Root;												// �������� ��������� ��������
#ifdef DEBUG
		cout << "TDestructor\t" << this << endl;
#endif // DEBUG
	}

//////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////// ������� ������� //////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
	void erase(int Data) {
		erase_(Data, getRoot());
	}
	// ����� �������� ��������� ������
	void erase() {
		erase_(getRoot());
	}
	// ����� ���������� ����� ��������� � ������
	void insert(int Data) {
		insert_(Data, getRoot());			// ���� ���� ����������� �������� � ���������� ��������
	}
	// ����� ������ ������������� ��������
	int maxValue() {
		return maxValue_(getRoot());					// ����� ���� � ������������� ��������
	}
	// ����� ������ ������������ ��������
	int minValue() {
		return minValue_(getRoot());						// ����� ���� � ������������ ��������
	}
	// ����� ������ ��������� ������ �� �����
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
////////////////// �������� ���������� ������� //////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
private:
	// ����� �������� �������� ������ �� ��� ��������
	void erase_(int Data, Element* Root) {
		if (Root == nullptr) return;

	}
	// ����� ������� ��������� ������ ��� ��������� ��������
	void erase_(Element* Root) {
		if (Root == nullptr) return;
		erase_(Root->pLeft);
		delete Root->pLeft;
		Root->pLeft = nullptr;
		erase_(Root->pRight);
		delete Root->pRight;
		Root->pRight = nullptr;
	}
	// ����� ���������� ����� ��������� � ������
	void insert_(int Data, Element* Root) {
		if (this->Root == nullptr) {								// ���� ��� ����������� ������ �������
			this->Root = new Element(Data);							// ������� ������ �������
			return;													// � �������
		}
		if (Root == nullptr) return;								// ������� ������
		if (Data < Root->Data) {									// ���� �������� ������ ������������
			if (Root->pLeft) insert_(Data, Root->pLeft);			// ���� ���� ����������� �������� � ���������� ��������
			else Root->pLeft = new Element(Data);					// ����� �������� ����� �������
		}
		else {														// ����� �������� ������ ������������
			if (Root->pRight) insert_(Data, Root->pRight);			// ���� ���� ����������� �������� � ���������� ��������
			else Root->pRight = new Element(Data);					// ����� �������� ����� �������
		}
	}
	// ����� ������ ������������� ��������
	int maxValue_(Element* Root) {
		return Root ? Root->pRight ? maxValue_(Root->pRight) : Root->Data : int();
		//if (Root == nullptr) return -1;								// ���� ������ ������
		//if (Root->pRight) maxValue_(Root->pRight);					// ����� ���� � ������������� ��������
		//else return Root->Data;										// ���������� ������������ ��������
	}
	// ����� ������ ������������ ��������
	int minValue_(Element* Root) {
		return Root ? Root->pLeft ? minValue_(Root->pLeft) : Root->Data : int();
	}
	// ����� ������ ��������� ������ �� �����
	void print_(Element* Root) {
		if (Root == nullptr) return;
		print_(Root->pLeft);
		cout << Root->Data << "\t";
		print_(Root->pRight);
	}
	// ����� ������� ����������� ������
	int count_(Element* Root) {
		if (Root == nullptr) return 0;
		if (Root->pLeft == Root->pRight) return 1;
		else {
			return 1 + count_(Root->pLeft) + count_(Root->pRight);
		}
	}
	// ����� ������� ����� ��������� ������
	int sum_(Element* Root) {
		if (Root == nullptr) return 0;
		if (Root->pLeft == Root->pRight) return Root->Data;
		else return Root->Data + sum_(Root->pLeft) + sum_(Root->pRight);
	}
};


void main() {

	setlocale(LC_ALL, "");
	int n;
	cout << "������� ������ ������ - "; cin >> n; cout << endl;
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