#pragma once
#include<iostream>
using namespace std;

ostream& operator<<(std::ostream& os, const String& other);

class String {
	
    int size;
    char* str;
public:
	/// <summary>  </summary>
	/// <param name="valueStr"></param>
	void Set_str(const char* valueStr);
	/// <summary> получить длину строки константный метод</summary>
	/// <returns></returns>
	const int Get_size() const;
	/// <summary> получить длину строки </summary>
	/// <returns></returns>
	int Get_size();
	/// <summary> получить строковое значени константный метод </summary>
	/// <returns></returns>
	const char* Get_str() const;
	/// <summary> получить строковое значени </summary>
	/// <returns></returns>
	char* Get_str();
    /// <summary>  </summary>
    /// <param name="size"></param>
    /// <returns></returns>
	explicit String(int size = 80);

	String(const char* arrayChar);
	
	String(const char& other);

	String(String&& other);
	
	/// <summary> конструктор копирования </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	String(const String& other);
	// деструктор
	~String();
// --- Operators ---
	String& operator= (const String& other);
	// move assignment
	String& operator= (String&& other);

	String operator+(const String& other) const;

	
	//// access content:
	//const char& content() const { 
	//	return *str; 
	//}
	//// addition:
	//String operator+(const String& other) {
	//	return String(content() + other.content());
	//}

	String& operator+=(const String& other);
// --------------------------------------------
void print() const;

};
