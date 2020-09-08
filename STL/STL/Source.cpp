#include<iostream>
#include<list>
using namespace std;
//STL - Standard Template Libriary (—тандартна€ Ўаблонна€ библиотека)
// набор шаблонных контейнеров - списки деревь€ массивы.

void main() {
	setlocale(LC_ALL, "");
	list<int> my_list = { 3, 5, 8, 13, 21 };
	for (list<int>::iterator it = my_list.begin();it != my_list.end();it++) {
		cout << *it << "\t";
	}
	cout << endl;
	for (list<int>::reverse_iterator it = my_list.rbegin();it != my_list.rend();it++) {
		cout << *it << "\t";
	}
	cout << endl;
}