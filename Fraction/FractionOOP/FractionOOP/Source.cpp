#include<iostream>
using std::cout;
using std::cin;
using std::endl;

class Fraction {
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
		this-> numerator =  numerator;
	}
	/// <summary> задает для объекта значение знаменателя </summary>
	/// <param name="denominator"></param>
	void set_denominator(double denominator) {
		this-> denominator = denominator;
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
	void Print() const{
		if (denominator == 0) {
			cout << "Ошибка деления на ноль " << numerator << " / " << denominator << " = Error"<< endl;
		}
		else {
			cout << "Результат деления чисел " << numerator <<
				" / " << denominator << " = " << rezult << ";"<< std::endl;
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