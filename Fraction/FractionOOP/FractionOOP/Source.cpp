#include"ClassFraction.h"


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