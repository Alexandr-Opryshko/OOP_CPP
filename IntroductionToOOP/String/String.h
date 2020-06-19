#pragma once
using namespace std;

class String {

    int size;
    char* str;
public:
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

