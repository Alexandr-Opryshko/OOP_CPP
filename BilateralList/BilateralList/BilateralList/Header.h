#pragma once
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
		friend class Iterator;
		friend class ReversIterator;
	private:
		int Data;
		Element* pNext;
		Element* pPrev;
	};
	Element* Head;
	Element* Tail;
	int size;
public:

	class Iterator {
	private:
		Element* Temp;
	public:
		Iterator(Element* Temp = nullptr);
		~Iterator();
		Iterator& operator++();
		Iterator& operator--();
		Iterator& operator++(int);
		Iterator& operator--(int);
		bool operator!=(const Iterator& other) const;
		bool operator!=(Element* other_el) const;
		const int& operator*() const;
		int& operator*();
		// замена Temp != nulptr на Temp
		operator bool()const;

	};
	class ReversIterator {
	private:
		Element* Temp;
	public:
		ReversIterator(Element* Temp = nullptr);
		~ReversIterator();
		ReversIterator& operator++();
		ReversIterator& operator--();
		ReversIterator& operator++(int);
		ReversIterator& operator--(int);
		bool operator!=(const ReversIterator& other) const;
		bool operator!=(Element* other_el) const;
		const int& operator*() const;
		int& operator*();
		operator bool()const;
	};

	const Iterator begin() const;
	const Iterator end() const;
	const ReversIterator rbegin() const;
	const ReversIterator rend() const;
	// конструктор
	List();
	// конструктор копирования
	List(const List& other);
	// конструктор с переменным колличеством параметров
	List(const std::initializer_list<int>& il);
	~List();
	//---------------------------------------------------------------------
	// Method
	// добавить в начало списка
	void push_front(int Data);
	// удаление первого элемента
	void pop_front();
	// добавить в конец списка
	void push_back(int Data);
	// удаление последнего элемента
	void pop_back();
	// вставить значение по индексу
	bool insert(int data, int index);
	// удаление элемента по индексу
	bool erase(int index);
	//CopyMethods;
	List& operator =(const List& Head);
	//MoveMethods;
	List& operator =(List&& Head);
	//operator+;
	List operator +(const List& Head) const;
	//operator+=;
	void operator +=(const List& Head);
	// вывод элементов в консоль прямой ход
	void print();
	// вывод элементов в консоль обратный ход
	void printRevers();
};