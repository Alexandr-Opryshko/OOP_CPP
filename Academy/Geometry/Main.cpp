#include<iostream>
#include<string>
#include<Windows.h>
//using namespace std;

namespace Geometry {
	class Shape {
		std::string color;
	public:
		Shape(std::string color = "white") {
			this->color = color;
		}
		virtual ~Shape() {}

		virtual double area()const = 0;
		virtual double perimeter()const = 0;
		virtual void draw()const = 0;
	};

	class Square : public Shape {
		double side;
	public:
		double get_side()const {
			return side;
		}
		double set_side(double side) {
			if (side < 0)side = -side;
			return this->side = side;
		}

		Square(double side) {
			set_side(side);
			std::cout << "SqConstructor:\t" << this << std::endl;
		}
		~Square() {
			std::cout << "SqDestructor:\t" << this << std::endl;
		}

		double area()const {
			return side * side;
		}
		double perimeter()const {
			return side * 4;
		}
		void draw() const {
			for (int i = 0; i < side; i++) {
				for (int j = 0; j < side; j++) {
					std::cout << "* ";
				}
				std::cout << std::endl;
			}
		}
	};

	class Rectangle :public Shape {
		double side1;
		double side2;
	public:
		double get_side1()const {
			return side1;
		}
		double get_side2()const {
			return side2;
		}
		double set_side1(double side1) {
			if (side1 < 0)side1 = -side1;
			return this->side1 = side1;
		}
		double set_side2(double side2) {
			if (side2 < 0)side2 = -side2;
			return this->side2 = side2;
		}

		Rectangle(double side1, double side2) {
			set_side1(side1);
			set_side2(side2);
			std::cout << "RectConstructor:\t" << this << std::endl;
		}
		~Rectangle() {
			std::cout << "RectDestructor:\t" << this << std::endl;
		}

		double area()const {
			return side1 * side2;
		}
		double perimeter()const {
			return (side1 + side2) * 2;
		}
		double diag()const {
			return sqrt(pow(side1, 2) + pow(side2, 2));
		}
		void draw()const {
			for (int i = 0; i < side1; i++) {
				for (int j = 0; j < side2; j++) {
					std::cout << "* ";
				}
				std::cout << std::endl;
			}
		}
	};
	class Triagle : public Shape {
	public:
		double get_side_1()const {
			return side_1;
		}
		double get_side_2()const {
			return side_2;
		}
		double get_side_3()const {
			return side_3;
		}
		double set_side_1(double side_1) {
			if (side_1 < 0) side_1 = -side_1;
			return this->side_1 = side_1;
		}
		double set_side_2(double side_2) {
			if (side_2 < 0) side_2 = -side_2;
			return  this->side_2 = side_2;
		}
		double set_side_3(double side_3) {
			if (side_3 < 0) side_3 = -side_3;
			return  this->side_3 = side_3;
		}
		double area()const {
			double p = (get_side_1() + get_side_2() + get_side_3()) / 2;
			return sqrt(p * (p - get_side_1()) * (p - get_side_2()) * (p - get_side_3()));
		}
		double perimeter()const {
			return (get_side_1() + get_side_2() + get_side_3());
		}
		void draw()const {

		}
		Triagle(double side_1, double side_2, double side_3) {
			set_side_1(side_1);
			set_side_2(side_2);
			set_side_3(side_3);
			if ((side_1 + side_2) <= side_3 || (side_2 + side_3) <= side_1 || (side_3 + side_1) <= side_2) throw std::exception("Bad side");
		}
	private:
		double side_1, side_2, side_3;
	};
}

void main() {
	setlocale(LC_ALL, "");
	Geometry::Square sq(5);
	std::cout << "Square area:\t" << sq.area() << std::endl;
	std::cout << "Square perimeter:\t" << sq.perimeter() << std::endl;
	sq.draw();

	Geometry::Rectangle rect(5, 8);
	std::cout << "Rectangle area:\t" << sq.area() << std::endl;
	std::cout << "Rectangle perimeter:\t" << sq.perimeter() << std::endl;
	rect.draw();

	try
	{
		Geometry::Triagle trg(2, 2, 2);
		std::cout << "Triagle area:\t" << trg.area() << std::endl;
		std::cout << "Triagle perimeter:\t" << trg.perimeter() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	catch (...) {

	}

}