#include<iostream>
using namespace std;

class Fraction {
	int integer;
	int numerator;
	int denominator;
public:
	const int get_integer()const {
		return integer;
	}
	const int get_numerator()const {
		return numerator;
	}
	const int get_denominator()const {
		return denominator;
	}
	void set_integer(int integer) {
		this->integer = integer;
	}
	void set_numerator(int numerator) {
		this->numerator = numerator;
	}
	void set_denominator(int denominator) {
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}
	//		Constructors:
	Fraction() {
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefConstructor:\t" << this << endl;
	}
	Fraction(int integer) {
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(int numerator, int denominator) {
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator) {
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(const Fraction& other) {
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:" << this << endl;
	}
	~Fraction() {
		cout << "Destructor:\t" << this << endl;
	}

	//		Operators:
	Fraction& operator=(const Fraction& other) {
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment: " << this << endl;
		return *this;
	}

	/// <summary> Метод, который переводит неправильную дробь в правильную и возвращает результат </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	Fraction& ToProper(const Fraction& other) {		// -;
		if (other.numerator > other.denominator) {		// если дробь неправильная
			this->integer = other.integer + other.numerator / other.denominator;
			this->numerator = other.numerator % other.denominator;
			this->denominator = other.denominator;
		}
		else {
			this->integer = other.integer;
			this->numerator = other.numerator;
			this->denominator = other.denominator;
		}
		return *this;
	}
	/// <summary> Метод, который переводит значение в неправильную дробь и возвращает результат </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	Fraction& ToImproper(const Fraction& other) {
		if ((other.integer != 0) && (other.numerator != 0)) {
			this->numerator = other.integer * other.denominator + other.numerator;
			this->denominator = other.denominator;
			this->integer = 0;
		}
		else if ((other.integer != 0) && (other.numerator == 0)) {
			this->numerator = other.integer;
			this->denominator = 1;
			this->integer = 0;
		}
		return *this;
	}
	/// <summary> Метод, который сокращает дробь  и возвращает результат </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	Fraction& Reduce_1(const Fraction& other) {
		this->integer = other.integer;					// защита при использовании разных объектов
		for (int i = other.denominator; i != 1; i--) {
			if (((other.denominator % i) == 0) && ((other.numerator % i) == 0)) {
				this->numerator = other.numerator / i;
				this->denominator = other.denominator / i;
				break;
			}
		}
		return *this;
	}

/// <summary> Еще один Метод, который сокращает дробь  и возвращает результат </summary>
/// <param name="other"></param>
/// <returns></returns>
	Fraction& Reduce_2(const Fraction& other) {
		int more;					// большее значение
		int less;					// меньшее значение
		int reminder = 0;			// остаток от деления
		if (other.numerator > other.denominator) {
			more = other.numerator;
			less = other.denominator;
		}
		else {
			less = other.numerator;
			more = other.denominator;
		}
		do {
			reminder = more % less;
			more = less;
			less = reminder;
		} while (reminder);

		this->numerator = other.numerator / more;
		this->denominator = other.denominator / more;
		return *this;
	}

	/// <summary> Метод, который выводит на экран результат с проверкой на 0 </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	void print()const {
		if (integer)cout << integer;
		if (numerator) {
			if (integer)cout << "+";
			cout << numerator << "/" << denominator;
		}
		else if (integer == 0)
			cout << 0;
		cout << endl;
	}
};

//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK

void main() {
	setlocale(LC_ALL, "");
	int integer, numerator, denominator;

	cout << "Для демонстрации дробей введите:" << endl;
	cout << "Целое число:\t"; cin >> integer;
	cout << "Числитель:\t"; cin >> numerator;
	cout << "Знаменатель:\t"; cin >> denominator;

	Fraction data(integer, numerator, denominator);			// создадим объект с данными

	data.Reduce_2(data);
	data.print();

	if ((integer != 0) && (numerator != 0)) {
		Fraction improper;									// объект для неправильных дробей
		if (numerator > denominator) {
			cout << "Введенная дробь не правильная, а также смешанная. Попробуем перевести ее в правильную смешанную:" << endl;
			Fraction proper;								// объект для правильных дробей
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
			Fraction improper;									// объект для неправильных дробей
			improper.ToImproper(data);
			improper.print();
		}
	}
	else {
		if (numerator > denominator) {
			cout << "Введенная дробь не правильная. Переведем ее в правильную смешанную:" << endl;
			Fraction proper;								// объект для неправильных дробей
			proper.ToProper(data);
			proper.print();
		}
		else {
			cout << "Введенная дробь правильная." << endl;
			data.print();
		}
	}
	

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