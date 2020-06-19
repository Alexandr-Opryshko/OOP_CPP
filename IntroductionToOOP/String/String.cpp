#include<iostream>
#include "String.h"

void main() {
	setlocale(LC_ALL, "");

	String str(8);
	str.print();
	String str1 = "Hello";
	str1.print();
}