#include<iostream>
#include "String.h"

void main() {
	setlocale(LC_ALL, "");

	String str(8);
	str.print();
	String str1 = "Hello";
	str1.print();


	//	String str2 = str1;
	//	str2.print();
	/*
		cout << str2 << endl;
		str = str1;
		cout << str1 << endl;
		*/
}