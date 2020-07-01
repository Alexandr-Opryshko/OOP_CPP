#include"Fraction.h"

using namespace std;

const int Fraction::get_integer()const {
	return integer;
}
const int Fraction::get_numerator()const {
	return numerator;
}
const int Fraction::get_denominator()const {
	return denominator;
}
void Fraction::set_integer(int integer) {
	this->integer = integer;
}
void Fraction::set_numerator(int numerator) {
	this->numerator = numerator;
}
void Fraction::set_denominator(int denominator) {
	if (denominator == 0)denominator = 1;
	this->denominator = denominator;
}
//		Constructors:
Fraction::Fraction() {
	this->integer = 0;
	this->numerator = 0;
	this->denominator = 1;
	cout << "DefConstructor:\t" << this << endl;
}
Fraction::Fraction(double value) {
	integer = (int)value;					// запишим целую часть
	value -= integer;						// уберем целую часть
	int i = 1;								// зададим denominator
	for (; i < 100000;) {					// выполняем пока не получим целую чась с округлением до 5-ти знаков
		if ((value - (int)value) != 0) {	// если остаток дробный
			i *= 10;						// увеличим denominator в 10 раз
			value *= 10;					// произведем умножение на 10
			continue;						// пропустим ниже код
		}
		break;								// иначе выход из цикла
	}
	numerator = (int)value == 0 ? 1 : (int)value;				// запишим результат
	denominator = i;						// запишим результат
	Reduce();								// сократим дробь
	cout << "Constructor double:\t" << this << endl;
}

Fraction::Fraction(int integer) {
	this->integer = integer;
	this->numerator = 0;
	this->denominator = 1;
	cout << "Constructor:\t" << this << endl;
}
Fraction::Fraction(int numerator, int denominator) {
	this->integer = 0;
	this->numerator = numerator;
	this->set_denominator(denominator);
	cout << "Constructor:\t" << this << endl;
}
Fraction::Fraction(int integer, int numerator, int denominator) {
	this->integer = integer;
	this->numerator = numerator;
	this->set_denominator(denominator);
	std::cout << "Constructor:\t" << this << std::endl;
}
Fraction::Fraction(const Fraction& other) {
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	std::cout << "CopyConstructor:" << this << std::endl;
}
Fraction::~Fraction() {
	std::cout << "Destructor:\t" << this << std::endl;
}
/// <summary> Метод, который переводит неправильную дробь в правильную и возвращает результат </summary>
/// <param name="other"></param>
/// <returns></returns>
Fraction& Fraction::ToProper(const Fraction& other) {		// -;
	this->integer = other.integer + other.numerator / other.denominator;
	this->numerator = other.numerator % other.denominator;
	this->denominator = other.denominator;
	return *this;
}
Fraction& Fraction::ToProper() {
	integer += numerator / denominator;
	numerator %= denominator;
	return *this;
}
/*
void Fraction::ToProper() {
	integer += numerator / denominator;
	numerator %= denominator;
}
*/
/// <summary> Метод, который переводит значение в неправильную дробь и возвращает результат </summary>
/// <param name="other"></param>
/// <returns></returns>
Fraction& Fraction::ToImproper(const Fraction& other) {
	this->numerator = other.integer * other.denominator + other.numerator;
	this->denominator = other.denominator;
	this->integer = 0;
	return *this;
}
Fraction& Fraction::ToImproper() {
	this->numerator = integer * denominator + numerator;
	this->denominator = denominator;
	this->integer = 0;
	return *this;
}
/*	void Fraction::ToImproper() {
		numerator += integer * denominator;
		integer = 0;
	}
	*/
	/// <summary> Метод, который сокращает дробь  и возвращает результат </summary>
	/// <param name="other"></param>
	/// <returns></returns>
Fraction& Fraction::Reduce() {
	int znak = 1;
	int more;					// большее значение
	int less;					// меньшее значение
	int reminder = 0;			// остаток от деления
	if (numerator < 0) {
		numerator *= -1; znak = -1;
	}
	if (numerator > denominator) {
		more = numerator;
		less = denominator;
	}
	else {
		less = numerator;
		more = denominator;
	}
	do {
		reminder = more % less;
		more = less;
		less = reminder;
	} while (reminder);

	numerator /= more;
	denominator /= more;
	numerator *= znak;
	return *this;
}
/*
void Fraction::Reduce() {
	int znak = 1;
	int more;					// большее значение
	int less;					// меньшее значение
	int reminder = 0;			// остаток от деления
	if (numerator < 0) {
		numerator *= -1; znak = -1;
	}
	if (numerator > denominator) {
		more = numerator;
		less = denominator;
	}
	else {
		less = numerator;
		more = denominator;
	}
	do {
		reminder = more % less;
		more = less;
		less = reminder;
	} while (reminder);

	numerator /= more;
	denominator /= more;
	numerator *= znak;
}
*/
//		Operators:
Fraction::operator double() const {
	double value = (double)integer + ((double)numerator / denominator);
	value = (int)(value * 100000);
	value /= 100000;
	std::cout << "ConvertToDouble: " << this << std::endl;
	return value;
}
	Fraction::operator int() {
	return integer;
}


Fraction& Fraction::operator=(const Fraction& other) {
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	std::cout << "CopyAssignment: " << this << std::endl;
	return *this;
}
/// <summary> перегрузка оператора сложения дробей </summary>
/// <param name="other"></param>
/// <returns></returns>
Fraction Fraction::operator +(const Fraction& other) {
	Fraction rezult;
	Fraction left = *this;
	left.ToImproper();
	Fraction right = other;
	right.ToImproper();
	rezult.integer = 0;
	rezult.numerator = (left.numerator * right.denominator) + (left.denominator * right.numerator);
	rezult.denominator = (left.denominator * right.denominator);
	rezult.Reduce();
	return rezult;
}
/// <summary> перегрузка оператора отнимания дробей </summary>
/// <param name="other"></param>
/// <returns></returns>
Fraction Fraction::operator -(const Fraction& other) {
	Fraction rezult;
	Fraction left = *this;
	left.ToImproper();
	Fraction right = other;
	right.ToImproper();
	rezult.integer = 0;
	rezult.numerator = (left.numerator * right.denominator) - (left.denominator * right.numerator);
	rezult.denominator = (left.denominator * right.denominator);
	rezult.Reduce();
	return rezult;
}
/// <summary> перегрузка оператора умножения </summary>
/// <param name="other"></param>
/// <returns></returns>
Fraction Fraction::operator *(const Fraction& other) {
	Fraction rezult;
	Fraction left = *this;
	left.ToImproper();
	Fraction right = other;
	right.ToImproper();
	return Fraction((left.numerator * right.numerator), (left.denominator * right.denominator)).ToProper().Reduce();
}
/// <summary> перегрузка оператора деления </summary>
/// <param name="other"></param>
/// <returns></returns>
Fraction Fraction::operator /(const Fraction& other) {
	int temp;
	Fraction left = *this;
	left.ToImproper();
	Fraction right = other;
	right.ToImproper();
	temp = right.denominator;
	right.denominator = right.numerator;
	right.numerator = temp;
	return Fraction((left.numerator * right.numerator), (left.denominator * right.denominator)).ToProper().Reduce();
}
/// <summary> перегрузка оператора сложения с присвоением </summary>
/// <param name="other"></param>
/// <returns></returns>
Fraction& Fraction::operator +=(const Fraction& other) {
	Fraction right = other;
	right.ToImproper().Reduce();
	this->ToImproper().Reduce();
	this->numerator = (this->numerator * right.denominator) + (right.numerator * this->denominator);
	this->denominator *= right.denominator;
	return this->Reduce().ToProper();
}
/// <summary> перегрузка оператора отнимания с присвоением </summary>
/// <param name="other"></param>
/// <returns></returns>
Fraction& Fraction::operator -=(const Fraction& other) {
	Fraction right = other;
	right.ToImproper().Reduce();
	this->ToImproper().Reduce();
	this->numerator = (this->numerator * right.denominator) - (right.numerator * this->denominator);
	this->denominator *= right.denominator;
	return this->Reduce().ToProper();
}
/// <summary> перегрузка оператора умножить с присвоением. Возвращает правильную дробь</summary>
/// <param name="other"></param>
/// <returns></returns>
Fraction& Fraction::operator *=(const Fraction& other) {
	Fraction right = other;
	right.ToImproper().Reduce();
	this->ToImproper().Reduce();
	this->numerator *= right.numerator;
	this->denominator *= right.denominator;
	return this->Reduce().ToProper();
}
/// <summary> перегрузка оператора деления с присвоением </summary>
/// <param name="other"></param>
/// <returns></returns>
Fraction& Fraction::operator /=(const Fraction& other) {
	int temp;
	Fraction right = other;
	right.ToImproper().Reduce();
	temp = right.denominator;
	right.denominator = right.numerator;
	right.numerator = temp;
	this->ToImproper().Reduce();
	this->numerator *= right.numerator;
	this->denominator *= right.denominator;
	return this->Reduce().ToProper();
}

bool Fraction::operator !=(const Fraction& other) {
	Fraction right = other;
	Fraction left = *this;
	right.ToImproper().Reduce();
	left.ToImproper().Reduce();
	return (((float)left.numerator / left.denominator) != ((float)right.numerator / right.denominator)) ? true : false;
}

bool Fraction::operator ==(const Fraction& other) {
	Fraction right = other;
	Fraction left = *this;
	right.ToImproper().Reduce();
	left.ToImproper().Reduce();
	return (((float)left.numerator / left.denominator) == ((float)right.numerator / right.denominator)) ? true : false;
}
bool Fraction::operator >(const Fraction& other) {
	Fraction right = other;
	Fraction left = *this;
	right.ToImproper().Reduce();
	left.ToImproper().Reduce();
	return (((float)left.numerator / left.denominator) > ((float)right.numerator / right.denominator)) ? true : false;
}
bool Fraction::operator <(const Fraction& other) {
	Fraction right = other;
	Fraction left = *this;
	right.ToImproper().Reduce();
	left.ToImproper().Reduce();
	return (((float)left.numerator / left.denominator) < ((float)right.numerator / right.denominator)) ? true : false;
}
/// <summary> Префиксный инкремент </summary>
/// <returns></returns>
Fraction& Fraction::operator++() {
	integer++;
	return *this;
}
/// <summary> Постфиксный инкремент </summary>
/// <returns></returns>
Fraction Fraction::operator++(int) {
	Fraction bufer = *this;
	integer++;
	return *this;
}

Fraction Fraction::operator()(int integer, int numerator, int denomenator) {
	set_integer(integer);
	set_numerator(numerator);
	set_denominator(denomenator);
	cout << "Оператор()" << endl;
	return *this;
}
/// <summary> Метод, который выводит на экран результат с проверкой на 0 </summary>
/// <param name="other"></param>
/// <returns></returns>
void Fraction::print()const {
	if (integer)cout << integer;
	if (numerator) {
		if (integer)cout << "+";
		cout << numerator << "/" << denominator;
	}
	else if (integer == 0)
		cout << 0;
	cout << endl;
}