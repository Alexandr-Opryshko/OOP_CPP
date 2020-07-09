#pragma once
#include<iostream>
#include<string>
#include<math.h>

using namespace std;


//################################ ����� ����������� ������ � ������ ���������� ################
class Figures {
public:
	virtual void print() = 0;
	
protected:
	int length = 0;			// �����
	int width = 0;			// ������
	int hieght = 0;			// ������
	int angle = 0;			// ����
	float area = 0;			// �������
	long perimeter = 0;		// ��������
};

//################################ ������ "�������" ################
class Square: public Figures {
public:
	void print() override;
	const int get_length() const;
	const int get_width() const;
	const long get_perimeter() const;
	const float get_area() const;
	int set_length(int length);
	int set_width(int width);
	
	Square(int lenght = 0, int width = 0);
	~Square();

private:
	long set_perimeter(long perimeter);
	float set_area(float area);
};

//################################ ������ "����" ################
class Rhombus : public Figures{
public:
	void print() override;
	const int get_length() const;
	const int get_width() const;
	const int get_angle() const;
	const long get_perimeter() const;
	const float get_area() const;
	int set_length(int length);
	int set_width(int width);
	int set_angle(int angle);
	Rhombus(int side = 0, int angle = 90);
	~Rhombus();

private:
	long set_perimeter(long perimeter);
	float set_area(float area);
	double leftShift;
};

//################################ ������ "�����������" ################
class Triangle : public Figures{
public:
	void print() override;
	const int get_length() const;
	const int get_width() const;
	const int get_hieght() const;
	const int get_angle() const;
	const long get_perimeter() const;
	const float get_area() const;
	int set_length(int length);
	int set_width(int width);
	int set_hieght(int hieght);
	int set_angle(int angle);
	Triangle(int a = 0, int b = 0, int c = 0);
	~Triangle();

private:
	long set_perimeter(long perimeter);
	float set_area(float area);
	
	double leftShift;
};

//################################


//################################ ������ ���������� � ���� ���������� ����������  ������ ################
class Object {
public:

	void print(Figures* obj) {
		obj->print();
	}

private:

};