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
		this-> numerator =  numerator;
	}
	/// <summary> ������ ��� ������� �������� ����������� </summary>
	/// <param name="denominator"></param>
	void set_denominator(double denominator) {
		this-> denominator = denominator;
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
	void Print() const{
		if (denominator == 0) {
			cout << "������ ������� �� ���� " << numerator << " / " << denominator << " = Error"<< endl;
		}
		else {
			cout << "��������� ������� ����� " << numerator <<
				" / " << denominator << " = " << rezult << ";"<< std::endl;
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

void main() {

	setlocale(LC_ALL, "");
	double numerator;
	double denomerator;
	cout << "������� ��������� ��� ������� 1 - "; cin >> numerator;
	cout << "������� ����������� ��� ������� 1 - "; cin >> denomerator;
	
	Fraction Rezult_1(numerator, denomerator);							// ������� ������� ��������
	Rezult_1.Rezult();											// ���������� ����������
	Rezult_1.Print();													// ������� �� ����� ���������

	cout << "������� ��������� ��� ������� 2 - "; cin >> numerator;
	cout << "������� ����������� ��� ������� 2 - "; cin >> denomerator;
	Fraction Rezult_2;
	Rezult_2.set_numerator(numerator);
	Rezult_2.set_denominator(denomerator);
	Rezult_2.Rezult();
	Rezult_2.Print();
	
	cout << "��������� - ��������� ������� 1 - " << Rezult_1.get_rezult() << endl;
	cout << "����������� - ��������� ������� 2 - " << Rezult_2.get_rezult() << endl;
	Fraction Rezult_3(Rezult_1.get_rezult(), Rezult_2.get_rezult());
	Rezult_3.Rezult();
	cout << "��������� ������� ������� 1 �� ������ 2 - \t";
	Rezult_3.Print();

	cout << "��������� �������� ������� 2 � ������ 3 - " << endl;
	Rezult_3 = Rezult_2;
	Rezult_3.Print();

	cout << "���������� ������� 3 �������� ������� 1 - " << endl;
	Rezult_3.operator=(Rezult_1);
	Rezult_3.Print();

	return;
}