#pragma once
using namespace std;

class String {

    int size;
    char* str;
public:
	/// <summary>  </summary>
	/// <param name="valueStr"></param>
	void Set_str(const char* valueStr) {
		this->size = (int)strlen(valueStr) + 1;
		delete[] this->str;
		this->str = new char[size];
		for (int i = 0; i < this->size-1; i++) {
			this->str[i] = valueStr[i];
		}
	}
	/// <summary> получить длину строки константный метод</summary>
	/// <returns></returns>
	const int Get_size() const{
		return this->size;
	}
	/// <summary> получить длину строки </summary>
	/// <returns></returns>
	int Get_size() {
		return this->size;
	}
	/// <summary> получить строковое значени константный метод </summary>
	/// <returns></returns>
	const char* Get_str() const{
		return str;
	}
	/// <summary> получить строковое значени </summary>
	/// <returns></returns>
	char* Get_str() {
		return str;
	}

    /// <summary>  </summary>
    /// <param name="size"></param>
    /// <returns></returns>
    explicit String(int size = 80) {
        this->size = size;
        this->str = new char[size] {};
        cout << "DefConstructor:\t\t" << this << endl;
    }

	String(const char* arrayChar) {
		this->size = (int)strlen(arrayChar) + 1;
		this->str = new char[size] {};
		for (int i = 0; i < this->size-1; i++) {
			this->str[i] = arrayChar[i];
		}
		std::cout << "Constructor:\t\t" << this << std::endl;
	}
	
	String(const char& other) : str(new char(other)) {
		this->size = (int)strlen(str) + 1;
		std::cout << "Constructor:  ?\t\t" << this << std::endl;
	}

	String(String&& other) : str(other.str), size(other.size) {
		other.str = nullptr;
		std::cout << "MoveConstructor:\t" << this << std::endl;
	}
	/// <summary> конструктор копирования </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	String(const String& other) {
		this->size = other.size;
		this->str = new char[this->size]{};
		for (int i = 0; i < this->size - 1; i++) {
			this->str[i] = other.str[i];
		}
		cout << "CopyConstructor:\t" << this << endl;
	}
	// деструктор
    ~String() {
        delete[] str;
        cout << "Destructor:\t\t" << this << endl;
    }
// --- Operators ---
	String& operator= (const String& other) {
		if (this->size != other.size) {
			this->size = other.size;
			delete[] this->str;
			this->str = new char[this->size]{};
		}
		for (int i = 0; i < this->size-1; i++) {
			this->str[i] = other.str[i];
		}
		cout << "AssignmentOperator\t" << this << endl;
		return *this;
	}
	// move assignment
	String& operator= (String&& other) {
		delete str;
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		cout << "MoveAssignment\t\t" << this << endl;
		return *this;
	}

	String operator+(const String& other) const{
		int size = this->size + other.size -1;
		String temp(this->size + other.size - 1);
		for (int i = 0, j = 0; i < size-1; i++) {
			temp.str[i] = (i < this->size-1) ? this->str[i] : other.str[j++];
		}
		cout << "SumOperator\t\t" << this << endl;
		return temp;
	}

	
	//// access content:
	//const char& content() const { 
	//	return *str; 
	//}
	//// addition:
	//String operator+(const String& other) {
	//	return String(content() + other.content());
	//}

	String& operator+=(const String& other) {
		int size = this->size + other.size - 1;
		String temp = *this;
		delete[] this->str;
		this->size = temp.size + other.size - 1;
		this->str = new char[this->size]{};
		for (int i = 0, j = 0; i < this->size - 1; i++) {
			this->str[i] = (i < temp.size - 1) ? temp.str[i] : other.str[j++];
		}
		cout << "SumAssignmentOperator\t" << this << endl;
		return *this;
	}
// --------------------------------------------
	void print() {
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};

