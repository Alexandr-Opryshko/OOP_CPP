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
	/// <summary> ћетод, который переводит неправильную дробь в правильную и возвращает результат </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	Fraction& ToProper(const Fraction& other);
	Fraction& ToProper();
	/*
	void ToProper();
	*/
	/// <summary> ћетод, который переводит значение в неправильную дробь и возвращает результат </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	Fraction& ToImproper(const Fraction& other);
	Fraction& ToImproper();
/*	void ToImproper();
	*/
	/// <summary> ћетод, который сокращает дробь  и возвращает результат </summary>
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
	/// <summary> перегрузка оператора сложени€ дробей </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	Fraction operator +(const Fraction& other);
	/// <summary> перегрузка оператора отнимани€ дробей </summary>
/// <param name="other"></param>
/// <returns></returns>
	Fraction operator -(const Fraction& other);
	/// <summary> перегрузка оператора умножени€ </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	Fraction operator *(const Fraction& other);
	/// <summary> перегрузка оператора делени€ </summary>
/// <param name="other"></param>
/// <returns></returns>
	Fraction operator /(const Fraction& other);
	/// <summary> перегрузка оператора сложени€ с присвоением </summary>
/// <param name="other"></param>
/// <returns></returns>
	Fraction& operator +=(const Fraction& other);
	/// <summary> перегрузка оператора отнимани€ с присвоением </summary>
/// <param name="other"></param>
/// <returns></returns>
	Fraction& operator -=(const Fraction& other);
	/// <summary> перегрузка оператора умножить с присвоением. ¬озвращает правильную дробь</summary>
	/// <param name="other"></param>
	/// <returns></returns>
	Fraction& operator *=(const Fraction& other);
	/// <summary> перегрузка оператора делени€ с присвоением </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	Fraction& operator /=(const Fraction& other);
	bool operator !=(const Fraction& other);

	bool operator ==(const Fraction& other);
	bool operator >(const Fraction& other);
	bool operator <(const Fraction& other);
	/// <summary> ѕрефиксный инкремент </summary>
	/// <returns></returns>
	Fraction& operator++();
	/// <summary> ѕостфиксный инкремент </summary>
/// <returns></returns>
	Fraction operator++(int);

	Fraction operator()(int integer, int numerator, int denomenator);
	/// <summary> ћетод, который выводит на экран результат с проверкой на 0 </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	void print()const;
};

