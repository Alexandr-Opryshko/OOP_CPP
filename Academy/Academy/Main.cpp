#include"Header.h"


void main() {
	setlocale(LC_ALL, "");

	Human* group[] =
	{
	new Student("Даня", "Дудченко", 17, true, "PV_911", 100, 100, "Программист"),
	new Student("Дмитрий", "Никулин", 16, true, "PV_911", 100, 99, "Программист"),
	new Student("Максим", "Пышненко", 16, true, "PV_911", 100, 99, "Программист"),
	new Teacher("Андрей", "Кобылинский", 40, true, "Преподаватель", 20, "HardwarePC", false)
	};
	for (int i = 0; i < size(group);i++) {
		/*group[i]->print();*/
		
		cout << *group[i] << endl;
		
	}
	for (int i = 0; i < size(group);i++) {
		delete group[i];
	}
	Basa basa;
	basa.print(&Student("Даня", "Дудченко", 17, true, "PV_911", 100, 100, "Программист"));

		//Human A("Viktor","Tichev",20,true);
		//cout << A << endl;
		//cout << "/////////////////////////////////////////////////////////////////////" << endl;
		//Student St("Stas", "Kovikov", 20, true,"P-911",986,99,"Programer");
		//St.print();
		//cout << "/////////////////////////////////////////////////////////////////////" << endl;
		//Teacher Te("Andrey", "Pupcov", 12, true, "History", 12, "Historic", true);
		////cout << Te << endl;
		//Te.print();
		//cout << "/////////////////////////////////////////////////////////////////////" << endl;

		//Graduate Gr(St, "Винищення бурьяну");
		//Gr.print();

		//char temp;
		//int temp1;
		//string name;		// имя
		//string surname;		// фамилия
		//int age;			// возраст
		//bool gender;		// пол try - мужской false - женский

		//string speccialty;	// специальность

		//string group;		// группа
		//double rating;		// рейтинг
		//double attendence;	// посещаемость
		//

		//string subject;		// тема
		//double experience;	// опыт
		//bool evil;			// характер Злой?

		//cout << "Your name: ";cin >> name;
		//cout << "Your surname: ";cin >> surname;
		//cout << "Your age: ";cin >> age;
		//while (true) {
		//	cin.clear();
		//	cout << "Your gender M/F: ";cin >> temp;
		//	if (temp == 'M') {
		//		gender = true;break;
		//	}
		//	else if (temp == 'F') {
		//		gender = false;break;
		//	}
		//}
		//cout << "Your specialty: ";cin >> speccialty;
		//while (true) {
		//	cin.clear();
		//	cout << "Your student Y/N: ";cin >> temp;
		//	if (temp == 'Y') {
		//		temp1 = 1;break;
		//	}
		//	else if (temp == 'N') {
		//		temp1 = 0;break;
		//	}
		//}
		//if (temp1 == 0) {											// если не студент
		//	while (true) {
		//		cin.clear();
		//		cout << "Your teacher Y/N: ";cin >> temp;
		//		if (temp == 'Y') {
		//			temp1 = 2;break;
		//		}
		//		else if (temp == 'N') {
		//			temp1 = 0;break;
		//		}
		//	}
		//}
		//if (temp1 == 0) {												// если просто человек
		//	Human Hm(name, surname, age, gender);
		//	system("cls");
		//	cout << "You are an ordinary person" << endl;
		//	Hm.print();
		//}
		//else if(temp1 == 1) {											// если студент
		//	cout << "What group are you studying in: "; cin >> group;
		//	cout << "What is your rating: "; cin >> rating;
		//	cout << "What is your attendance (0-100%): "; cin >> attendence;
		//	Student St(name, surname, age, gender, group, rating, attendence, speccialty);
		//	system("cls");
		//	cout << "Are you a student" << endl;
		//	St.print();
		//}
		//else {															// если учитель
		//	cout << "What topic do you teach: "; cin >> subject;
		//	cout << "Your work experience (ears): "; cin >> experience;
		//	while (true) {
		//		cin.clear();
		//		cout << "You are mean (Y/N): "; cin >> temp;
		//		if (temp == 'Y') {
		//			evil = true;break;
		//		}
		//		else if (temp == 'N') {
		//			evil = false;break;
		//		}
		//	}
		//	Teacher Te(name, surname, age, gender, subject, experience, speccialty, evil);
		//	system("cls");
		//	cout << "Are you a teacher" << endl;
		//	Te.print();
	//}
}