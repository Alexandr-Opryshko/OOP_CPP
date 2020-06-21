#pragma once
using namespace std;

class String {

    int size;
    char* str;
public:
	/// <summary>
	/// 
	/// </summary>
	/// <param name="valueStr"></param>
	void Set_str(const char* valueStr) {
		this->size = strlen(valueStr) + 1;
		delete[] this->str;
		this->str = new char[size];
		for (int i = 0; i < this->size; i++) {
			this->str[i] = valueStr[i];
		}
	}
	/// <summary> получить длину строки </summary>
	/// <returns></returns>
	const int Get_size() {
		return this->size;
	}
	/// <summary> получить строковое значени </summary>
	/// <returns></returns>
	const char& Get_str() {
		return *str;
	}
    /// <summary>
    /// 
    /// </summary>
    /// <param name="size"></param>
    /// <returns></returns>
    explicit String(int size = 80) {
        this->size = size;
        this->str = new char[size] {};
        cout << "DefConstructor:\t" << this << endl;
    }
    ~String() {
        delete[] str;
        cout << "Destructor:\t" << this << endl;
    }

	String(const char* arrayChar) {
        this->str = nullptr;
		this->size = strlen(arrayChar)+1;
        this->str = new char[size] {};
		for (int i = 0; i < size; i++) {
				this->str[i] = arrayChar[i];
		}
	}

	void print() {
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};

