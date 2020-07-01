#include<iostream>
#include "String.h"



ostream& operator<<(ostream& os, const String& other) {
	cout << "Size:\t" << other.Get_size() << endl;
	cout << "Str:\t" << other.Get_str() << endl;

	return os;
}

void main() {
	setlocale(LC_ALL, "");


	String str(8);
	str.print();
	String str1 = "Hello!";
	str1.print();


	/*String str2 = str1;
	cout << str2 << endl;
	str2 = str;
	cout << str1 << endl;
	str2 = "What is your name?";
	cout << str2 << endl;
	str = "Good by.";
	cout << str << endl;
	cout << str.Get_str() << " " << str.Get_str() << endl;

	str = str1 + str2 + str;
	cout << str << endl;
	str += str;
	cout << str << endl;*/

	String A("Hello!");
	A.print();
	String C = String("Hello");
	C.print();
	String B = A;
	B.print();
	B = C;
	B.print();
	A = A + B;
	A.print();
	A += C;
	A.print();	
}