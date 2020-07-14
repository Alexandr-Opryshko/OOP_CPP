#include<iostream>
#include<exception>
#include<Windows.h>

using namespace std;

//#define DEVISISION_BY_ZERO
//#define FACTORIAL

unsigned int factorial(unsigned int n) {
	unsigned int f = 1;
	if (n > 12) throw exception("To lager number");
	for (int i = 1; i <= n; i++) {
		f *= i;
		cout << "!" << i<< " = "<<f << endl;
	}
	return f;
}

void main() {
	setlocale(LC_ALL, "");
#ifdef DEVISION_BY_ZERO
	int a = 2;
	int b = 0;
	try {
		//throw exception("eto nashe iscluchenie");
		cout << a / b << endl;
	}
	catch (const std::exception& e) {
		cerr << e.what() << endl;
	}
	catch (...) {
		cerr << "Error" << endl;
		MessageBox(NULL, "Someeting happend", "Some ex", MB_OK | MB_ICONERROR);
	}
#endif // DEVISION_BY_ZERO

#ifdef FACTORIAL
	throw exception("Ex");
	int n;
	cout << "¬ведите число: "; cin >> n;

	try {
		cout << factorial(n) << endl;
	}
	catch (const std::exception& e) {
		cerr << e.what() << endl;
	}
#endif // FACTORIAL

	int n;
	cout << "¬ведите размер массива: "; cin >> n;
	int* arr = nullptr;
	try {
		arr = new int[n];

		delete[] arr;
		
	}
	catch (const std::exception& e) {
		cerr << e.what() << endl;
	}

	
}