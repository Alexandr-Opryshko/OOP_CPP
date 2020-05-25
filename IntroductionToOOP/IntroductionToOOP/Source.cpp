#include<iostream>
using namespace std;

class Point {
public:
	// ����� �� ����� ��� ��������� � ������������� �����
	void PrintDisplay(int x, int y) {
		x = set_X(x);
		y = set_Y(y);
		std::cout << "Y-"<< this->get_Y_End() << std::endl;
		for (int i = this->Y_END; i > 0; i--) {
			std::cout << "|";
			for (int j = 0; j < this->X_END;j++) {
				if ((i == y) && (j == x)) {
					std::cout << "*";
				}
				else std::cout << " ";
			}
			std::cout << std::endl;
		}
		std::cout << "0";
		for (int i = 0; i < this->X_END;i++) {
			std::cout << "-";
		}
		std::cout << " X-" << this->get_X_End() << std::endl;
		return;
	}
	// ����� �� ����� ������������ ����� � ��������� ���������
	void PrintBorderControl(int x, int y) {
		if (x < 0) {
			std::cout << "��� x:\t" << x << " -> 0 -> " << this->get_X_End() << std::endl;
		}
		else if (x > this->get_X_End()) {
			std::cout << "��� x:\t0 -> " << this->get_X_End() << " -> " << x << std::endl;
		}
		else {
			std::cout << "��� x:\t0 -> " << x << " -> " << this->get_X_End() << std::endl;
		}
		if (y < 0) {
			std::cout << "��� y:\t" << y << " -> 0 -> " << this->get_Y_End() << std::endl;
		}
		else if (y > this->get_Y_End()) {
			std::cout << "��� y:\t0 -> " << this->get_Y_End() << " -> " << y << std::endl;
		}
		else {
			std::cout << "��� y:\t0 -> " << y << " -> " << this->get_Y_End() << std::endl;
		}
		return;
	}
	// ����� �� ����� ���������� ����� ������� x � y
	void PrintDistanceXY(int x, int y) {
		int d = 0;
		std::cout << "\n\t ���������� �� ����� X �� ����� Y ����������: ";
		x = (x < 0) ? -(x) : x;
		y = (y < 0) ? -(y) : y;
		d = (x * x) + (y * y);
		//d = SquareRoot(d);
		std::cout << SquareRoot(d) << " �����" << std::endl;
	}
	// ����� ��������� �������� �� ��� x
	int get_X()const {
		return x;
	}
	// ����� �������� �������� �� ��� x � ��������� �������� � ������ ��������� ���������
	int set_X(int x) {
		x = ErrorInputX(x);
		this->x = x;
		return x;
	}
	// ����� ��������� ���������� �������� �� ��� x
	int get_X_End()const {
		return this->X_END;
	}
	// ����� ��������� �������� �� ��� y
	int get_Y()const {
		return y;
	}
	// ����� �������� �������� �� ��� y � ��������� �������� � ������ ��������� ���������
	int set_Y(int y) {
		y = ErrorInputY(y);
		this->y = y;
		return y;
	}
	// ����� ��������� ���������� �������� �� ��� y
	int get_Y_End()const {
		return this->Y_END;
	}
private:
	int x = 0;
	int y = 0;
	const int X_END = 30;			// ������� ������� �� ��� x
	const int Y_END = 20;			// ������� ������� �� ��� y
	// ����� �������� �� ����� �� ����� �������� ��������� �� ��� x
	int ErrorInputX(int x) {
		if (x > X_END) return X_END - 1;
		else return x;
	}
	// ����� �������� �� ����� �� ����� �������� ��������� �� ��� 
	int ErrorInputY(int y) {
		if (y > Y_END) return Y_END - 1;
		else return y;
	}
	// ����� ���������� ����������� �����
	float SquareRoot(int d) {
		float sd = 0;
		while ((sd * sd) < d) {	// ��������� ���� �� ��������� �����������-������������� ����������
			sd = sd + 0.01;
		}
		int temp = (sd - 0.01) * 100;	// �������� ���������� �� �����
		sd = (float)temp / 100;			// 
		return sd;						// ������ ��������� ���������� ����������� �����
	}
};

void main() {
	setlocale(LC_ALL, "");
	Point A;
	Point B;
	int x = 0;
	int y = 0;
	A.set_X(5);

	std::cout << "������� ���� ������������ �� ��� x - "; std::cin >> x; std::cout << std::endl;
	std::cout << "������� ���� ������������ �� ��� y - "; std::cin >> y; std::cout << std::endl;

	D.PrintDisplay(x, y);
	D.PrintBorderControl(x, y);
	D.PrintDistanceXY(x, y);
	return;
}