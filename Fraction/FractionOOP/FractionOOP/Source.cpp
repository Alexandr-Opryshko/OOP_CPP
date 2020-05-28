#include"ClassFraction.h"


void main() {

	setlocale(LC_ALL, "");
	double numerator;
	double denomerator;
	cout << "Введите числитель для объекта 1 - "; cin >> numerator;
	cout << "Введите знаменатель для объекта 1 - "; cin >> denomerator;
	
	Fraction Rezult_1(numerator, denomerator);							// зададим объекту значения
	Rezult_1.Rezult();											// произведем вычисление
	Rezult_1.Print();													// выведем на экран результат

	cout << "Введите числитель для объекта 2 - "; cin >> numerator;
	cout << "Введите знаменатель для объекта 2 - "; cin >> denomerator;
	Fraction Rezult_2;
	Rezult_2.set_numerator(numerator);
	Rezult_2.set_denominator(denomerator);
	Rezult_2.Rezult();
	Rezult_2.Print();
	
	cout << "Числитель - результат объекта 1 - " << Rezult_1.get_rezult() << endl;
	cout << "Знаменатель - результат объекта 2 - " << Rezult_2.get_rezult() << endl;
	Fraction Rezult_3(Rezult_1.get_rezult(), Rezult_2.get_rezult());
	Rezult_3.Rezult();
	cout << "Результат деления объекта 1 на объект 2 - \t";
	Rezult_3.Print();

	cout << "Скопируем значения объекта 2 в объект 3 - " << endl;
	Rezult_3 = Rezult_2;
	Rezult_3.Print();

	cout << "Присвоение объекту 3 значений объекта 1 - " << endl;
	Rezult_3.operator=(Rezult_1);
	Rezult_3.Print();

	return;
}