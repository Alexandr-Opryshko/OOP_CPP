#pragma once
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

class Fraction{
	double numerator;
	double denominator;
	double rezult;
public:
	/// <summary>
	/// Возвращает значение числителя
	/// </summary>
	/// <returns></returns>
	double get_numerator() const {
		return numerator;
	}
	/// <summary>
	/// Возвращает значение знаменателя
	/// </summary>
	/// <returns></returns>
	double get_denominator() const {
		return denominator;
	}
	/// <summary> Возвращает результат деления числителя на знаменатель </summary>
	/// <returns></returns>
	double get_rezult() const {
		return rezult;
	}
	/// <summary> задает для объекта значение числителя </summary>
	/// <param name="numerator"></param>
	void set_numerator(double numerator) {
		this->numerator = numerator;
	}
	/// <summary> задает для объекта значение знаменателя </summary>
	/// <param name="denominator"></param>
	void set_denominator(double denominator) {
		this->denominator = denominator;
	}
	/// <summary> производит дробное вычисление и задает для объекта значение результата </summary>
	/// <param name="other"></param>
	void Rezult() {
		if (denominator == 0) {
			this->rezult = 0;
		}
		else {
			this->rezult = numerator / denominator;
		}
		return;
	}
	/// <summary>
	/// выводит в консоль значения чисел объекта и результат деления c проверкой деления на 0
	/// </summary>
	void Print() const {
		if (denominator == 0) {
			cout << "Ошибка деления на ноль " << numerator << " / " << denominator << " = Error" << endl;
		}
		else {
			cout << "Результат деления чисел " << numerator <<
				" / " << denominator << " = " << rezult << ";" << std::endl;
		}
		cout << endl;
	}
	/// <summary> Конструктор по умолчанию </summary>
	/// <param name="numerator"></param>
	/// <param name="denominator"></param>
	/// <returns></returns>
	Fraction(double numerator = 0, double denominator = 0) {
		this->numerator = numerator;
		this->denominator = denominator;
		this->rezult = -1;
	}
	/// <summary>
	/// Конструктор копирования
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	Fraction(const Fraction& other) {
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		this->rezult = other.rezult;
	}
	/// <summary>
	/// конструктор присвоения
	/// </summary>
	/// <param name="other"></param>
	void operator = (const Fraction& other) {
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		this->rezult = other.rezult;
	}

	~Fraction() {

	}
};

