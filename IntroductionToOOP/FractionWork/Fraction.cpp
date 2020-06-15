#include "Fraction.h"

#include<iostream>

using namespace std;
#define FRACTION_TRANSFER
//#define OVERLOAD_Operator
//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK

/*
Fraction operator *(Fraction left, Fraction right) {
	left.ToImproper(left);
	right.ToImproper(right);
	Fraction rezult(left.get_numerator() * right.get_numerator(), left.get_denominator() * right.get_denominator());

	rezult.Reduce(rezult);
	rezult.ToProper(rezult);
	return rezult;

}
*/


void main() {
	setlocale(LC_ALL, "");
#ifdef FRACTION_TRANSFER
		int integer, numerator, denominator;

		cout << "Для демонстрации дробей введите:" << endl;
		cout << "Целое число:\t"; cin >> integer;
		cout << "Числитель:\t"; cin >> numerator;
		cout << "Знаменатель:\t"; cin >> denominator;

		Fraction data(integer, numerator, denominator);			// создадим объект с данными
		Fraction proper;								// объект для правильных дробей
		Fraction improper;									// объект для неправильных дробей
		data.Reduce();
		data.print();


		if ((integer != 0) && (numerator != 0)) {
			if (numerator > denominator) {
				cout << "Введенная дробь не правильная, а также смешанная. Попробуем перевести ее в правильную смешанную:" << endl;
				proper.ToProper(data);
				proper.print();
				cout << "А теперь в неправильную:" << endl;
				improper.ToImproper(data);
				improper.print();
			}
			else {
				cout << "Введенная дробь правильная, а также смешанная. Переведем ее в не правильную:" << endl;
				improper.ToImproper(data);
				improper.print();
			}
		}
		else if(numerator == 0) {
			if (integer == 0) 			{
				cout << "Число относится к целым числам. Результат нулевой." << endl;
			}
			else {
				cout << "Результатом является не дробное число. Переведем его в не правильную:" << endl;
				improper.ToImproper(data);
				improper.print();
			}
		}
		else {
			if (numerator > denominator) {
				cout << "Введенная дробь не правильная. Переведем ее в правильную смешанную:" << endl;
				proper.ToProper(data);
				proper.print();
			}
			else {
				cout << "Введенная дробь правильная." << endl;
				data.print();
			}
		}
#endif // FRACTION_TRANSFER

#ifdef OVERLOAD_Operator

	Fraction rezult;			// создадим объект с данными
	Fraction A(2, 3, 4);
	Fraction B(5, 7, 8);
	A.print();
	B.print();
	std::cout << "------------Сокращение дробей-------------------" << std::endl;
	A.Reduce();
	B.Reduce();
	A.print();
	B.print();

	std::cout << "------------Перегрузка оператора сложения-------" << std::endl;
	rezult = A + B;
	rezult.print();

	std::cout << "------------Перегрузка оператора отнимания------" << std::endl;
	rezult = A - B;
	rezult.print();

	std::cout << "------------Перегрузка оператора умножения------" << std::endl;
	rezult = A * B;
	rezult.print();

	std::cout << "------------Перегрузка оператора деления--------" << std::endl;
	rezult = A / B;
	rezult.print();

	Fraction C(1, 1, 2);
	C.print();
	A.print();
	std::cout << "------------Перегрузка оператора сложения с присвоением------" << std::endl;
	C += A;
	C.print();
	std::cout << "------------Перегрузка оператора отнимания с присвоением-----" << std::endl;
	C -= A;
	C.print();
	std::cout << "------------Перегрузка оператора умножения с присвоением-----" << std::endl;
	C *= A;
	C.print();
	std::cout << "------------Перегрузка оператора деления с присвоением-------" << std::endl;
	C /= A;
	C.print();
	std::cout << "------------Перегрузка оператора сравнения == != > <------------" << std::endl;
	if (C != A) {
		std::cout << "Объекты не равны" << std::endl;
		if (C > A) std::cout << "Объект C больше A" << std::endl;
		else if (C < A) std::cout << "Объект C меньше A" << std::endl;
	}
	else if(C == A) std::cout << "Объекты равны" << std::endl;
	else std::cout << "Ошибка сравнения" << std::endl;

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
