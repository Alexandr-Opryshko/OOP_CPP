#include"Header.h"



void main() {
	setlocale(LC_ALL, "");

	Object Obj;					// создаем объект

	Figures* group[] =
	{
		new Square(4, 5),		// создадим квадрат
		new Square(5,5),
		new Rhombus(40,2),
		new Rhombus(40,5),
		new Rhombus(40,20),
		new Rhombus(40,30),
		new Rhombus(40,40),
		new Rhombus(40,45),
		new Rhombus(40,50),
		new Rhombus(40,60),
		new Rhombus(40,70),
		new Rhombus(40,80),
		new Rhombus(40,90)
	};
	
	for (int i = 0; i < size(group);i++) {
		Obj.print(group[i]);				// передадим в консоль объекта массив фигур
	}

	for (int i = 0; i < size(group); i++) {
		delete group[i];
	}
}