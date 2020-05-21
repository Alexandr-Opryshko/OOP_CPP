#include<iostream>
using namespace std;

#include <iostream>     // std::cout
#include <iterator>     // std::distance
#include <list>         // std::list

class Distance {
public:
	void PrintDisplay(int x, int y) {
		x = set_X(x);
		y = set_Y(y);
		std::cout << " ";
		for (int i = 0; i < this->x_end;i++) {
			std::cout << "+";
		}
		std::cout << std::endl;
		for (int i = 0; i < this->y_end;i++) {
			std::cout << "+";
			for (int j = 0; j < this->x_end;j++) {
				if ((i == y) && (j == x)) {
					std::cout << "*";
				}
				else std::cout << " ";
			}
			std::cout << "+" << std::endl;
		}
		std::cout << " ";
		for (int i = 0; i < this->x_end;i++) {
			std::cout << "+";
		}
		std::cout << std::endl;
		return;
	}
	int get_X()const {
		return x;
	}
	int set_X(int x) {
		x = ErrorInputX(x);
		this->x = x;
		return x;
	}
	int get_X_End()const {
		return this->x_end;
	}
	int get_Y()const {
		return y;
	}
	int set_Y(int y) {
		y = ErrorInputY(y);
		this->y = y;
		return y;
	}
	int get_Y_End()const {
		return this->y_end;
	}
private:
	int x = 0;
	int y = 0;
	const int x_end = 30;
	const int y_end = 20;
	int ErrorInputX(int x) {
		if (x > x_end) return x_end - 1;
		else return x;
	}
	int ErrorInputY(int y) {
		if (y > y_end) return y_end - 1;
		else return y;
	}
};

void main() {
	setlocale(LC_ALL, "");
	Distance D;
	int x = 0;
	int y = 0;
	std::cout << "Введите ваше расположение по оси x - "; std::cin >> x; std::cout << std::endl;
	std::cout << "Введите ваше расположение по оси y - "; std::cin >> y; std::cout << std::endl;

	D.PrintDisplay(x, y);

	x = D.get_X_End() - x;
	y = D.get_Y_End() - y;
	if ((x < 0) || (y < 0)) {
		std::cout << "Вы вышли за границы оси координат:"<< std::endl;
		std::cout << "\t x = " << x << "\t y = " << y << std::endl;
	}
	else {
		std::cout << "Остаток до границы по оси x - " << x << std::endl;
		std::cout << "Остаток до границы по оси y - " << y << std::endl;
	}
	


}