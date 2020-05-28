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
	/// ���������� �������� ���������
	/// </summary>
	/// <returns></returns>
	double get_numerator() const {
		return numerator;
	}
	/// <summary>
	/// ���������� �������� �����������
	/// </summary>
	/// <returns></returns>
	double get_denominator() const {
		return denominator;
	}
	/// <summary> ���������� ��������� ������� ��������� �� ����������� </summary>
	/// <returns></returns>
	double get_rezult() const {
		return rezult;
	}
	/// <summary> ������ ��� ������� �������� ��������� </summary>
	/// <param name="numerator"></param>
	void set_numerator(double numerator) {
		this->numerator = numerator;
	}
	/// <summary> ������ ��� ������� �������� ����������� </summary>
	/// <param name="denominator"></param>
	void set_denominator(double denominator) {
		this->denominator = denominator;
	}
	/// <summary> ���������� ������� ���������� � ������ ��� ������� �������� ���������� </summary>
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
	/// ������� � ������� �������� ����� ������� � ��������� ������� c ��������� ������� �� 0
	/// </summary>
	void Print() const {
		if (denominator == 0) {
			cout << "������ ������� �� ���� " << numerator << " / " << denominator << " = Error" << endl;
		}
		else {
			cout << "��������� ������� ����� " << numerator <<
				" / " << denominator << " = " << rezult << ";" << std::endl;
		}
		cout << endl;
	}
	/// <summary> ����������� �� ��������� </summary>
	/// <param name="numerator"></param>
	/// <param name="denominator"></param>
	/// <returns></returns>
	Fraction(double numerator = 0, double denominator = 0) {
		this->numerator = numerator;
		this->denominator = denominator;
		this->rezult = -1;
	}
	/// <summary>
	/// ����������� �����������
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	Fraction(const Fraction& other) {
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		this->rezult = other.rezult;
	}
	/// <summary>
	/// ����������� ����������
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

