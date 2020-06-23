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
	String str1 = "Hello ";
	str1.print();


		String str2 = str1;
		str2.print();
		cout << str2 << endl;
		str = "Good by ";
		cout << str << endl;
		str2 = str;
		cout << str1 << endl;

		str = str1 + str + str2;
		cout << str << endl;
		str += str1;
		cout << str << endl;

}