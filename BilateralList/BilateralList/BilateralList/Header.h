#pragma once
#include<iostream>
using namespace std;
#define tab	"\t"

template<typename T>
class List {
private:
	class Element {

	public:
		Element(T Data, Element* pNext = nullptr, Element* pPrev = nullptr);
		~Element();
		friend class List;
		friend class Iterator;
		friend class ReversIterator;
	private:
		T Data;
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
		Iterator(Element* Temp);
		~Iterator();
		Iterator& operator++();
		Iterator& operator--();
		Iterator& operator++(int);
		Iterator& operator--(int);
		bool operator!=(const Iterator& other) const;
		bool operator!=(Element* other_el) const;
		const T& operator*() const;
		T& operator*();
		// ������ Temp != nulptr �� Temp
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
		const T& operator*() const;
		T& operator*();
		operator bool()const;
	};

	const Iterator begin() const;
	const Iterator end() const;
	const ReversIterator rbegin() const;
	const ReversIterator rend() const;
	// �����������
	List();
	// ����������� �����������
	List(const List& other);
	// ����������� � ���������� ������������ ����������
	List(const std::initializer_list<T>& il);
	~List();
	//---------------------------------------------------------------------
	// Method
	// �������� � ������ ������
	void push_front(T Data);
	// �������� ������� ��������
	void pop_front();
	// �������� � ����� ������
	void push_back(T Data);
	// �������� ���������� ��������
	void pop_back();
	// �������� �������� �� �������
	bool insert(T data, int index);
	// �������� �������� �� �������
	bool erase(int index);
	//CopyMethods;
	List& operator =(const List& Head);
	//MoveMethods;
	List& operator =(List&& Head);
	//operator+;
	List operator +(const List& Head) const;
	//operator+=;
	void operator +=(const List& Head);
	// ����� ��������� � ������� ������ ���
	void print();
	// ����� ��������� � ������� �������� ���
	void printRevers();
};

