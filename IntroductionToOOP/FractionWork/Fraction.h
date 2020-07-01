#pragma once
#include<iostream>
using namespace std;

class Fraction {

	int integer;
	int numerator;
	int denominator;
public:
	
	const int get_integer()const;
	const int get_numerator()const;
	const int get_denominator()const;
	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);
	//		Constructors:
	Fraction();
	Fraction(double value);

	Fraction(int integer);
	Fraction(int numerator, int denominator);
	Fraction(int integer, int numerator, int denominator);
	Fraction(const Fraction& other);
	~Fraction();
	/// <summary> �����, ������� ��������� ������������ ����� � ���������� � ���������� ��������� </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	Fraction& ToProper(const Fraction& other);
	Fraction& ToProper();
	/*
	void ToProper();
	*/
	/// <summary> �����, ������� ��������� �������� � ������������ ����� � ���������� ��������� </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	Fraction& ToImproper(const Fraction& other);
	Fraction& ToImproper();
/*	void ToImproper();
	*/
	/// <summary> �����, ������� ��������� �����  � ���������� ��������� </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	Fraction& Reduce();
	/*
	void Reduce();
	*/
	//		Operators:
	operator double() const;
	explicit operator int();
	
	Fraction& operator=(const Fraction& other);
	/// <summary> ���������� ��������� �������� ������ </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	Fraction operator +(const Fraction& other);
	/// <summary> ���������� ��������� ��������� ������ </summary>
/// <param name="other"></param>
/// <returns></returns>
	Fraction operator -(const Fraction& other);
	/// <summary> ���������� ��������� ��������� </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	Fraction operator *(const Fraction& other);
	/// <summary> ���������� ��������� ������� </summary>
/// <param name="other"></param>
/// <returns></returns>
	Fraction operator /(const Fraction& other);
	/// <summary> ���������� ��������� �������� � ����������� </summary>
/// <param name="other"></param>
/// <returns></returns>
	Fraction& operator +=(const Fraction& other);
	/// <summary> ���������� ��������� ��������� � ����������� </summary>
/// <param name="other"></param>
/// <returns></returns>
	Fraction& operator -=(const Fraction& other);
	/// <summary> ���������� ��������� �������� � �����������. ���������� ���������� �����</summary>
	/// <param name="other"></param>
	/// <returns></returns>
	Fraction& operator *=(const Fraction& other);
	/// <summary> ���������� ��������� ������� � ����������� </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	Fraction& operator /=(const Fraction& other);
	bool operator !=(const Fraction& other);

	bool operator ==(const Fraction& other);
	bool operator >(const Fraction& other);
	bool operator <(const Fraction& other);
	/// <summary> ���������� ��������� </summary>
	/// <returns></returns>
	Fraction& operator++();
	/// <summary> ����������� ��������� </summary>
/// <returns></returns>
	Fraction operator++(int);

	Fraction operator()(int integer, int numerator, int denomenator);
	/// <summary> �����, ������� ������� �� ����� ��������� � ��������� �� 0 </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	void print()const;
};

