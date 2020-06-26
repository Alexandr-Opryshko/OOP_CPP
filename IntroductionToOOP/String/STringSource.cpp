#include "String.h"
/******************************************************************************************/
/*////////////////////////////////////////////////////////////////////////////////////////*/

void String::Set_str(const char* valueStr) {
	this->size = (int)strlen(valueStr) + 1;
	delete[] this->str;
	this->str = new char[size];
	for (int i = 0; i < this->size - 1; i++) {
		this->str[i] = valueStr[i];
	}
}
/// <summary> получить длину строки константный метод</summary>
/// <returns></returns>
const int String::Get_size() const {
	return this->size;
}
/// <summary> получить длину строки </summary>
/// <returns></returns>
int String::Get_size() {
	return this->size;
}
/// <summary> получить строковое значени константный метод </summary>
/// <returns></returns>
const char* String::Get_str() const {
	return str;
}
/// <summary> получить строковое значени </summary>
/// <returns></returns>
char* String::Get_str() {
	return str;
}

/// <summary>  </summary>
/// <param name="size"></param>
/// <returns></returns>
String::String(int size) {
	this->size = size;
	this->str = new char[size] {};
	cout << "DefConstructor:\t\t" << this << endl;
}

String::String(const char* arrayChar) {
	this->size = (int)strlen(arrayChar) + 1;
	this->str = new char[size] {};
	for (int i = 0; i < this->size - 1; i++) {
		this->str[i] = arrayChar[i];
	}
	std::cout << "Constructor:\t\t" << this << std::endl;
}

String::String(const char& other) : str(new char(other)) {
	this->size = (int)strlen(str) + 1;
	std::cout << "Constructor:  ?\t\t" << this << std::endl;
}

String::String(String&& other) : str(other.str), size(other.size) {
	other.str = nullptr;
	std::cout << "MoveConstructor:\t" << this << std::endl;
}
/// <summary> конструктор копирования </summary>
/// <param name="other"></param>
/// <returns></returns>
String::String(const String& other) {
	this->size = other.size;
	this->str = new char[this->size]{};
	for (int i = 0; i < this->size - 1; i++) {
		this->str[i] = other.str[i];
	}
	cout << "CopyConstructor:\t" << this << endl;
}
// деструктор
String::~String() {
	delete[] str;
	cout << "Destructor:\t\t" << this << endl;
}
// --- Operators ---
String& String::operator= (const String& other) {
	if (this->size != other.size) {
		this->size = other.size;
		delete[] this->str;
		this->str = new char[this->size]{};
	}
	for (int i = 0; i < this->size - 1; i++) {
		this->str[i] = other.str[i];
	}
	cout << "AssignmentOperator\t" << this << endl;
	return *this;
}
// move assignment
String& String::operator= (String&& other) {
	delete[] this->str;
	this->size = other.size;
	this->str = other.str;
	other.str = nullptr;
	cout << "MoveAssignment\t\t" << this << endl;
	return *this;
}

String String::operator+(const String& other) const {
	int size = this->size + other.size - 1;
	String temp(this->size + other.size - 1);
	for (int i = 0, j = 0; i < size - 1; i++) {
		temp.str[i] = (i < this->size - 1) ? this->str[i] : other.str[j++];
	}
	cout << "SumOperator\t\t" << this << endl;
	return temp;
}


String& String::operator+=(const String& other) {
	return *this = *this + other;
}
// --------------------------------------------
void String::print() const {
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;
}
ostream& operator<<(ostream& os, const String& other) {
	cout << "Size:\t" << other.Get_size() << endl;
	cout << "Str:\t" << other.Get_str() << endl;

	return os;
}