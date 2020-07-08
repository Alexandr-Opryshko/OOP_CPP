#include"Header.h"



void main() {
	setlocale(LC_ALL, "");

	Object Obj;					// создаем объект
	Square sq(4,5);				// создадим квадрат
	

	Obj.print(&sq);				// передадим в консоль объекта фигуру квадрат

}