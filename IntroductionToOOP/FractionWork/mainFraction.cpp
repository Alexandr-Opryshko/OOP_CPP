#include "Fraction.h"

#include<iostream>

using namespace std;
//#define CONVERT_DOUBLE_TODO_FRACTION
//#define ARITHMETIC_OPERQTORS_CHECK
//#define FRACTION_TRANSFER
//#define OVERLOAD_Operator
#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK

/*
Fraction operator *(Fraction left, Fraction right) {
	left.ToImproper();
	right.ToImproper();

//	Fraction rezult(left.get_numerator() * right.get_numerator(), left.get_denominator() * right.get_denominator());
//	rezult.Reduce();
//	rezult.ToProper();
//	return rezult;

	return Fraction(left.get_numerator() * right.get_numerator(), left.get_denominator() * right.get_denominator()).ToImproper().Reduce();
}
*/

Fraction operator +(const Fraction& left, const Fraction& right) {
	return Fraction
	(
		left.get_integer() + right.get_integer(),
		(left.get_numerator() * right.get_denominator() + left.get_denominator() * right.get_numerator()),
		left.get_denominator() * right.get_denominator()
	).ToProper().Reduce();
}

ostream& operator<<(ostream& os, const Fraction& other) {
	if (other.get_integer()) cout << other.get_integer();
	if (other.get_numerator()) {
		//if (integer) cout << "(";
		if (other.get_integer()) cout << "+";
		cout << other.get_numerator() << "/" << other.get_denominator();
		//if (integer) cout << ")";
	}
	else if (other.get_integer() == 0) {
		cout << 0;
	}
	return os;
}


void main() {
	setlocale(LC_ALL, "");

#ifdef CONVERT_DOUBLE_TODO_FRACTION
	double a = 3.14;
	std::cout << a << std::endl;
	Fraction A = a;
	A.print();
	a = A;
	A(2, 3, 5);
	std::cout << a << std::endl;
#endif // CONVERT_DOUBLE_TODO_FRACTION

#ifdef ARITHMETIC_OPERQTORS_CHECK
		Fraction A(1, 2);
		Fraction B = A++;
		B.print();
		A.print();
		B = ++A;
		B = A + A;
		
		cout << A << " + " << B << " = " << (A+B).ToProper() << endl;
#endif // ARITHMETIC_OPERQTORS_CHECK



#ifdef FRACTION_TRANSFER
		int integer, numerator, denominator;

		cout << "��� ������������ ������ �������:" << endl;
		cout << "����� �����:\t"; cin >> integer;
		cout << "���������:\t"; cin >> numerator;
		cout << "�����������:\t"; cin >> denominator;

		Fraction data(integer, numerator, denominator);			// �������� ������ � �������
		Fraction proper;								// ������ ��� ���������� ������
		Fraction improper;									// ������ ��� ������������ ������
		data.Reduce();
		data.print();


		if ((integer != 0) && (numerator != 0)) {
			if (numerator > denominator) {
				cout << "��������� ����� �� ����������, � ����� ���������. ��������� ��������� �� � ���������� ���������:" << endl;
				proper.ToProper(data);
				proper.print();
				cout << "� ������ � ������������:" << endl;
				improper.ToImproper(data);
				improper.print();
			}
			else {
				cout << "��������� ����� ����������, � ����� ���������. ��������� �� � �� ����������:" << endl;
				improper.ToImproper(data);
				improper.print();
			}
		}
		else if(numerator == 0) {
			if (integer == 0) 			{
				cout << "����� ��������� � ����� ������. ��������� �������." << endl;
			}
			else {
				cout << "����������� �������� �� ������� �����. ��������� ��� � �� ����������:" << endl;
				improper.ToImproper(data);
				improper.print();
			}
		}
		else {
			if (numerator > denominator) {
				cout << "��������� ����� �� ����������. ��������� �� � ���������� ���������:" << endl;
				proper.ToProper(data);
				proper.print();
			}
			else {
				cout << "��������� ����� ����������." << endl;
				data.print();
			}
		}
#endif // FRACTION_TRANSFER

#ifdef OVERLOAD_Operator

	Fraction rezult;			// �������� ������ � �������
	Fraction A(2, 3, 4);
	Fraction B(5, 7, 8);
	A.print();
	B.print();
	std::cout << "------------���������� ������-------------------" << std::endl;
	A.Reduce();
	B.Reduce();
	A.print();
	B.print();

	std::cout << "------------���������� ��������� ��������-------" << std::endl;
	rezult = A + B;
	rezult.print();

	std::cout << "------------���������� ��������� ���������------" << std::endl;
	rezult = A - B;
	rezult.print();

	std::cout << "------------���������� ��������� ���������------" << std::endl;
	rezult = A * B;
	rezult.print();

	std::cout << "------------���������� ��������� �������--------" << std::endl;
	rezult = A / B;
	rezult.print();

	Fraction C(1, 1, 2);
	C.print();
	A.print();
	std::cout << "------------���������� ��������� �������� � �����������------" << std::endl;
	C += A;
	C.print();
	std::cout << "------------���������� ��������� ��������� � �����������-----" << std::endl;
	C -= A;
	C.print();
	std::cout << "------------���������� ��������� ��������� � �����������-----" << std::endl;
	C *= A;
	C.print();
	std::cout << "------------���������� ��������� ������� � �����������-------" << std::endl;
	C /= A;
	C.print();
	std::cout << "------------���������� ��������� ��������� == != > <------------" << std::endl;
	if (C != A) {
		std::cout << "������� �� �����" << std::endl;
		if (C > A) std::cout << "������ C ������ A" << std::endl;
		else if (C < A) std::cout << "������ C ������ A" << std::endl;
	}
	else if(C == A) std::cout << "������� �����" << std::endl;
	else std::cout << "������ ���������" << std::endl;

#endif // OVERLOAD_Operator


#ifdef CONSTRUCTORS_CHECK
	Fraction A;
	A.print();
	Fraction B = 3;
	B.print();
	Fraction C(4, 5);
	C.print();
	Fraction D(5, 4, 7);
	Fraction E = D;//CopyConstructor
	E.print();
	Fraction F;		//DefaultConstructor
	F = E;
	F.print();
#endif // CONSTRUCTORS_CHECK
#ifdef ASSIGNMENT_CHECK
	Fraction A(1, 2);
	A.print();
	Fraction B;
	B.print();
	cout << "\n-------------------------------------------\n";
	B = A;
	cout << "\n-------------------------------------------\n";*/

		int a, b, c;
	a = b = c = 0;
	Fraction D(1, 2);

	Fraction A, B, C;
	A = B = C = D;
#endif // ASSIGNMENT_CHECK
}
