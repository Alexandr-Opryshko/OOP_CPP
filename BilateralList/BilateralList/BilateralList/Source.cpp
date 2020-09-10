#include"Header.h"
#include"ImplementList.cpp"			// об€зательно в шаблонных типах

void main() {
	setlocale(LC_ALL, "");
	int n;
	int i;
	/*cout << "Input list size: "; cin >> n;
	cout << "¬ставить по индексу: "; cin >> i;*/
	List<int> list = { 5,2,3,4,6 };
	List<double> list2 = { 5.1,2.4,3.5,4.7,6.4 };
	List<string> list3 = { "хорошо", "живет","на","свете","винипух" };
	for (string i : list3) {
		cout << i << tab;
	}
	cout << endl;

	for (List<string>::ReversIterator rit = list3.rbegin(); rit != list3.rend(); rit++) {
		cout << *rit << tab;
	}
	cout << endl;
	List<int> list4 = list;
	//list2.print();
	//list = list + list;
	//list.print();
	//list.printRevers();
	//
	//for (int i : list) {
	//	cout << i << endl;
	//}
	////for (List::Iterator it = list.begin(); it != list.end(); it++) 
	//for(List<int>::ReversIterator rit = list.rbegin(); rit != list.rend();rit++){
	//	cout << *rit << endl;
	//}
	//int a = 5;		
	//int& pa = a;	// ссылка
	//int* ua = &a;	// указатель
	//cout << " «начение " << a << " адресс " << &a 
	//	<< " «начение " << pa << " адресс " << &pa 
	//	<< " значение " << *ua << " адресс" << ua << endl;
	//List list1;
	//for (; n > 0; n--) {
	//	list.push_front(n);
	//	list1.push_back(n);
	//}
	/*list.push_back(32);
	list.push_back(54);
	list.push_back(43);*/
	//list.print();
	//list1.print();
	//list = list;
//	list1 = list1 + list1;
//	list.print();
//	list1 += list;
//	list1= std::move (list);
//	list1.print();
//	list.print();
//	list.erase(i);
//	list.insert(58, i);
//	list.print();
	/*list.push_back(5);
	list.print();
	list.pop_back();
	list.print();
	list.pop_front();
	list.print();*/
//	list.printRevers();

}