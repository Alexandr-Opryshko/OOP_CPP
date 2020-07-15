#include<iostream>
using namespace std;

class Binary {
public:
	unsigned int get_Binary() const {
		return this->binary;
	}
	unsigned int set_Binary(unsigned int binary) {
		return this->binary = binary;
	}
	Binary operator =(unsigned int other) {
		set_Binary(other);
		return *this;
	}
	Binary operator =(const Binary& other) {
		set_Binary(other.binary);
		return *this;
	}
	Binary operator &=(unsigned int other) {
		set_Binary(other & get_Binary());
		return *this;
	}
	Binary operator &=(const Binary& other) {
		set_Binary(other.binary & get_Binary());
		return *this;
	}
	Binary operator |=(unsigned int other) {
		set_Binary(other | get_Binary());
		return *this;
	}
	Binary operator |=(const Binary& other) {
		set_Binary(other.binary | get_Binary());
		return *this;
	}
	Binary operator ^=(unsigned int other) {
		set_Binary(other ^ get_Binary());
		return *this;
	}
	Binary operator ^=(const Binary& other) {
		set_Binary(other.binary ^ get_Binary());
		return *this;
	}
	Binary(unsigned char binary) {
		this->binary = binary;
		cout << "Constructor" << endl;
	}
	Binary() {
		this->binary = 0;
		cout << "DefaultConstructor" << endl;
	}
	~Binary() {
		cout << "Destructor" << endl;
	}
	void Print() const {
		unsigned int temp = 0x8000;
		cout << "\t\t0 b ";
		for (int i = 0; i < 16; i++) {
			if ((this->binary & temp) != 0) {
				cout << "1 ";
			}
			else {
				cout << "0 ";
			}
			temp >>= 1;
		}
		cout << endl;
	}

private:
	unsigned int binary;
};


void main() {
	setlocale(LC_ALL, "");
	Binary A;
	Binary B;

	A = 0xF0F0;
	A.Print();
	B = 0x9955;
	B.Print();
	A &= B;
	A.Print();
	A ^= B;
	A.Print();
	A |= B;
	A.Print();

}