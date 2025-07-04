#include <iostream>
#include "struct_hw.h"
#include <Windows.h>

//1
Complex complexAdd(Complex& num1, Complex& num2) {
	Complex num;
	num.a = num1.a + num2.a;
	num.b = num1.b + num2.b;
	return num;
}

Complex complexSubtract(Complex& num1, Complex& num2) {
	Complex num;
	num.a = num1.a - num2.a;
	num.b = num1.b - num2.b;
	return num;
}

Complex complexMultiply(Complex& num1, Complex& num2) {
	Complex num;
	num.a = (num1.a * num2.a) - (num1.b * num2.b);
	num.b = (num1.a * num2.b) + (num1.b * num2.a);
	return num;
}

Complex complexDivide(Complex& num1, Complex& num2) {
	Complex num;
	double denom = (num2.a * num2.a) + (num2.b * num2.b);
	num.a = ((num1.a * num2.a) + (num1.b * num2.b)) / denom;
	num.b = ((num1.a * num2.b) + (num1.b * num2.a)) / denom;
	return num;
}

void complexPrint(Complex num) {
	if (num.b < 0) {
		std::cout << num.a << num.b << 'i' << '\n';
	}
	else {
		std::cout << num.a << '+' << num.b << 'i' << '\n';
	}
}

//2
Car GetCar() {
	Car car;
	std::cout << "������ ������� ���������: ";
	std::cin >> car.len;
	std::cout << "������ ������ �������: ";
	std::cin >> car.clr;
	std::cout << "������ ��'�� �������: ";
	std::cin >> car.eng;
	std::cout << "������ ��������� �������: ";
	std::cin >> car.powr;
	std::cout << "������ ������ ����: ";
	std::cin >> car.diam;
	std::cin.ignore();
	std::cout << "������ ����: ";
	std::cin.getline(car.col, 50);
	std::cout << "������ ��� ������� �������: ";
	std::cin.getline(car.gear, 50);
	return car;
}

void PrintCar(Car& car) {
	std::cout << "�������: " << car.len << '\n';
	std::cout << "������ �������: " << car.clr << '\n';
	std::cout << "��'�� �������: " << car.eng << '\n';
	std::cout << "��������� �������: " << car.powr << '\n';
	std::cout << "ĳ����� ����: " << car.diam << '\n';
	std::cout << "����: " << car.col << '\n';
	std::cout << "��� ������� �������: " << car.gear << '\n';
}

//3
void GetBook(Book& book) {
	std::cout << "������ ����� �����: ";
	std::cin.getline(book.name, 50);
	std::cout << "������ ������ �����: ";
	std::cin.getline(book.author, 50);
	std::cout << "������ ����������� �����: ";
	std::cin.getline(book.publish, 50);
	std::cout << "������ ���� �����: ";
	std::cin.getline(book.genre, 50);
}

void GetBooks(Book bookarr[], const int& size) {
	for (int i = 0; i < size; i++) {
		GetBook(bookarr[i]);
		std::cout << '\n';
	}
}

void PrintAllBooks(Book bookarr[], const int& size) {
	for (int i = 0; i < size; i++) {
		std::cout << "����� �����: " << bookarr[i].name << '\n';
		std::cout << "����� �����: " << bookarr[i].author << '\n';
		std::cout << "����������� �����: " << bookarr[i].publish << '\n';
		std::cout << "���� �����: " << bookarr[i].genre << '\n';
		std::cout << '\n';
	}
}

void SearchByAuthor(Book bookarr[], const int& size) {
	char temp[50];
	std::cout << "������ ������ �����: ";
	std::cin.getline(temp, 50);
	int check = 0;
	for (int i = 0; i < size; i++) {
		if (strcmp(temp, bookarr[i].author) == 0) {
			std::cout << "����� ��������: " << bookarr[i].name << '\n';
			check++;
			break;
		}
	}
	if (check == 0) {
		std::cout << "����� �� ��������." << '\n';
	}
}
void SearchByName(Book bookarr[], const int& size) {
	char temp[50];
	std::cout << "������ ����� �����: ";
	std::cin.getline(temp, 50);
	int check = 0;
	for (int i = 0; i < size; i++) {
		if (strcmp(temp, bookarr[i].name) == 0) {
			std::cout << "����� ��������: " << bookarr[i].name << '\n';
			check++;
			break;
		}
	}
	if (check == 0) {
		std::cout << "����� �� ��������." << '\n';
	}
}

void SortByName(Book bookarr[], const int& size) {
	Book* buffer = bookarr;
	for (int i = 1; i < size; i++) {
		Book temp = bookarr[i];
	    int j = i - 1;
		while (j >= 0 && (int)bookarr[j].name[0] > (int)temp.name[0]) {
	        bookarr[j + 1] = bookarr[j];
	        j--;
	    }
	    bookarr[j + 1] = temp;
	}
	std::cout << "���������: ";
	for (int i = 0; i < size; i++) {
		std::cout << bookarr[i].name << ' ';
	}
	std::cout << '\n';
	bookarr = buffer;
	delete[] buffer;
}

void SortByAuthor(Book bookarr[], const int& size) {
	Book* buffer = bookarr;
	for (int i = 1; i < size; i++) {
		Book temp = bookarr[i];
		int j = i - 1;
		while (j >= 0 && (int)bookarr[j].author[0] > (int)temp.author[0]) {
			bookarr[j + 1] = bookarr[j];
			j--;
		}
		bookarr[j + 1] = temp;
	}
	std::cout << "���������: ";
	for (int i = 0; i < size; i++) {
		std::cout << bookarr[i].name << ' ';
	}
	std::cout << '\n';
	bookarr = buffer;
	delete[] buffer;
}

void SortByPublish(Book bookarr[], const int& size) {
	Book* buffer = bookarr;
	for (int i = 1; i < size; i++) {
		Book temp = bookarr[i];
		int j = i - 1;
		while (j >= 0 && (int)bookarr[j].publish[0] > (int)temp.publish[0]) {
			bookarr[j + 1] = bookarr[j];
			j--;
		}
		bookarr[j + 1] = temp;
	}
	std::cout << "���������: ";
	for (int i = 0; i < size; i++) {
		std::cout << bookarr[i].name << ' ';
	}
	std::cout << '\n';
	bookarr = buffer;
	delete[] buffer;
}

//4
Car2 GetCar2() {
	Car2 car;
	std::cout << "������ ���� ������: ";
	std::cin.getline(car.color, 50);
	std::cout << "������ ������ ������: ";
	std::cin.getline(car.model, 50);
	char choice;
	std::cout << "����� � ������ ����� - �, ����� � ������ ����� - b" << '\n';
	std::cin >> choice;
	if (choice == 'a') {
		std::cin.ignore();
		std::cout << "������ ����� (�� 5 ����): ";
		std::cin.getline(car.number, 6);
	}
	if (choice == 'b') {
		std::cin.ignore();
		std::cout << "������ ����� (�� 8 �������): ";
		std::cin.getline(car.number, 9);
	}
	return car;

}

void PrintCar2(Car2& car) {
	std::cout << "����: " << car.color << '\n';
	std::cout << "������: " << car.model << '\n';
	std::cout << "�����: " << car.number << '\n';
}

void GetCars(Car2 cararr[], const int& size) {
	for (int i = 0; i < size; i++) {
		cararr[i] = GetCar2();
		std::cout << '\n';
	}
}

void PrintCars(Car2 cararr[], const int& size) {
	for (int i = 0; i < size; i++) {
		PrintCar2(cararr[i]);
		std::cout << '\n';
	}
}

void SearchCar(Car2 cararr[], const int& size) {
	char choice;
	char input[9];
	std::cout << "����� � ������ ����� - �, ����� � ������ ����� - b" << '\n';
	std::cin >> choice;
	if (choice == 'a') {
		std::cout << "������ ����� (�� 5 ����): ";
		std::cin.ignore();
		std::cin.getline(input, 6);
	}
	if (choice == 'b') {
		std::cout << "������ ����� (�� 8 �������): ";
		std::cin.ignore();
		std::cin.getline(input, 9);
	}
	int check = 0;
	for (int i = 0; i < size; i++) {
		if (strcmp(input, cararr[i].number) == 0) {
			std::cout << "������ ��������: " << cararr[i].number << '\n';
			check++;
			break;
		}
	}
	if (check == 0) { 
		std::cout << "������ �� ��������." << '\n';
	}
}

//5
Creature GetCreature() {
	Creature creature;
	std::cout << "������ �������� �����������: ";
	std::cin >> creature.spd;
	char choice;
	std::cout << "���� - �, ������ - b, ������ - c" << '\n';
	std::cin >> choice;
	std::cin.ignore();
	std::cout << "������ ����: ";
	std::cin.getline(creature.color, 50);
	switch (choice) {
	case 'a':
		strcpy_s(creature.type, strlen("����") + 1, "����");
		std::cout << "������ �������� �������: ";
		std::cin >> creature.flspd;
		break;
	case 'b':
		strcpy_s(creature.type, strlen("������") + 1, "������");
		char choice;
		std::cout << "������������ ������ - �, �� ������������ - b: ";
		std::cin >> choice;
		if (choice == 'a') {
			creature.ch = true;
		}
		else if (choice == 'b') {
			creature.ch = false;
		}
		break;
	case 'c':
		strcpy_s(creature.type, strlen("������") + 1, "������");
		std::cout << "������ ����� IQ ������: ";
		std::cin >> creature.iq;
		break;
	}
	return creature;
} 

void PrintCreature(Creature& creature) {
	std::cout << "�������� �����������: " << creature.spd << '\n';
	std::cout << "���: " << creature.type << '\n';
	std::cout << "����: " << creature.color << '\n';
	if (strcmp(creature.type, "����") == 0) {
		std::cout << "�������� �������: " << creature.flspd << '\n';
	}
	else if (strcmp(creature.type, "������") == 0) {
		if (creature.ch) {
			std::cout << "������������: ���" << '\n';
		}
		else {
			std::cout << "������������: �" << '\n';
		}
	}
	else if (strcmp(creature.type, "������") == 0) {
		std::cout << "г���� IQ: " << creature.iq << '\n';
	}
}

void GetCreatures(Creature crearr[], const int& size) {
	for (int i = 0; i < size; i++) {
		crearr[i] = GetCreature();
		std::cout << '\n';
	}
}

void PrintCreatures(Creature crearr[], const int& size) {
	for (int i = 0; i < size; i++) {
		PrintCreature(crearr[i]);
		std::cout << '\n';
	}
}

void SearchCreature(Creature crearr[], const int& size) {
	char choice;
	std::cout << "���� - �, ������ - b, ������ - c" << '\n';
	std::cin >> choice;
	if (choice == 'a') {
		double input;
		std::cout << "������ �������� �������: ";
		std::cin >> input;
		int check = 0;
		for (int i = 0; i < size; i++) {
			if (input = crearr[i].flspd) {
				std::cout << "����� ��������: " << crearr[i].flspd << '\n';
				check++;
				break;
			}
		}
		if (check == 0) {
			std::cout << "����� �� ��������." << '\n';
		}
	}
	else if (choice == 'b') {
		char choice;
		bool input;
		std::cout << "������������ ������ - �, �� ������������ - b: ";
		std::cin >> choice;
		if (choice == 'a') {
			input = true;
		}
		else if (choice == 'b') {
			input = false;
		}
		int check = 0;
		for (int i = 0; i < size; i++) {
			if ((input == crearr[i].ch) && strcmp(crearr[i].type, "������") == 0) {
				std::cout << "������ ��������: " << crearr[i].color << '\n';
				check++;
				break;
			}
		}
		if (check == 0) {
			std::cout << "������ �� ��������." << '\n';
		}
	}
	else if (choice == 'c') {
		int input;
		std::cout << "������ ����� IQ ������: ";
		std::cin >> input;
		int check = 0;
		for (int i = 0; i < size; i++) {
			if (input = crearr[i].iq) {
				std::cout << "������ ��������: " << crearr[i].iq << '\n';
				check++;
				break;
			}
		}
		if (check == 0) {
			std::cout << "������ �� ��������." << '\n';
		}
	}
}

//6
Student GetStudent() {
	Student student;
	std::cout << "������ ������� ��������: ";
	std::cin.getline(student.surname, 50);
	std::cout << "������ ����� �����: ";
	std::cin.getline(student.group, 50);
	for (int i = 0; i < student.grades_size; i++) {
		std::cout << "������ ������ ��������: ";
		std::cin >> student.grades[i];
	}
	std::cin.ignore();
	return student;
}

void PrintStudent(Student& student) {
	std::cout << "������� ��������: " << student.surname << '\n';
	std::cout << "����� �����: " << student.group << '\n';
	std::cout << "������: ";
	for (int i = 0; i < student.grades_size; i++) {
		std::cout << student.grades[i] << ' ';
	}
	std::cout << '\n';
}

void GetStudents(Student* studentarr, int& size) {
	for (int i = 0; i < size; i++) {
		studentarr[i] = GetStudent();
		std::cout << '\n';
	}
}

void PrintStudents(Student* studentarr, int& size) {
	for (int i = 0; i < size; i++) {
		PrintStudent(studentarr[i]);
		std::cout << '\n';
	}
}

Student* ChangeSize(Student* studentarr, int& size) {
	int size_new;
	std::cout << "������ ����� ����� ������: ";
	std::cin >> size_new;
	Student* temp = new Student[size_new];
	int temp_size = size;
	size = size_new;
	std::cin.ignore();
	for (int i = 0; i < temp_size; i++) {
		temp[i] = studentarr[i];
		std::cout << '\n';
	}
	for (int i = temp_size; i < size_new; i++) {
		temp[i] = GetStudent();
		std::cout << '\n';
	}
	delete[] studentarr;
	return temp;
}

void FastLearnerList(Student* studentarr, int& size) {
	int fl_size = 0;
	for (int i = 0; i < size; i++) {
		int check = 0;
		for (int j = 0; j < studentarr[i].grades_size; j++) {
			if ((studentarr[i].grades[j] == 12) || (studentarr[i].grades[j] == 11) || (studentarr[i].grades[j] == 10)) {
				check++;
			}
		}
		if (check >= ((int)studentarr[i].grades_size * 0.75)) {
			fl_size++;
		}
	}
	Student* flarr = new Student[fl_size];
	int x = 0;
	for (int i = 0; i < size; i++) {
		int check = 0;
		for (int j = 0; j < studentarr[i].grades_size; j++) {
			if ((studentarr[i].grades[j] == 12) || (studentarr[i].grades[j] == 11) || (studentarr[i].grades[j] == 10)) {
				check++;
			}
		}
		if (check >= ((int)studentarr[i].grades_size * 0.75)) {
			flarr[x] = studentarr[i];
			x++;
		}
	}
	std::cout << "������ ��������: " << '\n';
	for (int i = 0; i < fl_size; i++) {
		std::cout << flarr[i].surname << '\n';
	}
	std::cout << '\n';
}

void SlowLearnerList(Student* studentarr, int& size) {
	int sl_size = 0;
	for (int i = 0; i < size; i++) {
		int check = 0;
		for (int j = 0; j < studentarr[i].grades_size; j++) {
			if ((studentarr[i].grades[j] == 2) || (studentarr[i].grades[j] == 3) || (studentarr[i].grades[j] == 1)) {
				check++;
			}
		}
		if (check >= ((int)studentarr[i].grades_size * 0.5)) {
			sl_size++;
		}
	}
	Student* slarr = new Student[sl_size];
	int x = 0;
	for (int i = 0; i < size; i++) {
		int check = 0;
		for (int j = 0; j < studentarr[i].grades_size; j++) {
			if ((studentarr[i].grades[j] == 2) || (studentarr[i].grades[j] == 3) || (studentarr[i].grades[j] == 1)) {
				check++;
			}
		}
		if (check >= ((int)studentarr[i].grades_size * 0.5)) {
			slarr[x] = studentarr[i];
			x++;
		}
	}
	std::cout << "������ �⳺�����: " << '\n';
	for (int i = 0; i < sl_size; i++) {
		std::cout << slarr[i].surname << '\n';
	}
	std::cout << '\n';
}

//7
Man GetMan() {
	Man man;
	std::cout << "������ �������: ";
	std::cin.getline(man.surname, 50);
	std::cout << "������ ��'�: ";
	std::cin.getline(man.name, 50);
	std::cout << "������ ��: ";
	std::cin >> man.age;
	std::cout << "������ ���� ����������: ";
	std::cin >> man.date.day;
	std::cout << "������ ����� ����������: ";
	std::cin >> man.date.month;
	std::cout << "������ �� ����������: ";
	std::cin >> man.date.year;
	std::cin.ignore();
	return man;
}

void PrintMan(Man& man) {
	std::cout << "�������: " << man.surname << '\n';
	std::cout << "��'�: " << man.name << '\n';
	std::cout << "³�: " << man.age << '\n';
	std::cout << "���� ����������: " << man.date.day << '.' << man.date.month << '.' << man.date.year << '\n';
}

void GetMen(Man* manarr, int& size) {
	for (int i = 0; i < size; i++) {
		manarr[i] = GetMan();
		std::cout << '\n';
	}
}

void PrintMen(Man* manarr, int& size) {
	for (int i = 0; i < size; i++) {
		PrintMan(manarr[i]);
		std::cout << '\n';
	}
}

void SortBySurname(Man* manarr, int& size) {
	Man* buffer = manarr;
	for (int i = 1; i < size; i++) {
		Man temp = manarr[i];
		int j = i - 1;
		while (j >= 0 && (int)manarr[j].surname[0] > (int)temp.surname[0]) {
			manarr[j + 1] = manarr[j];
			j--;
		}
		manarr[j + 1] = temp;
	}
	std::cout << "³������������ ������: " << '\n';
	for (int i = 0; i < size; i++) {
		std::cout << manarr[i].surname << '\n';
	}
	manarr = buffer;
	delete[] buffer;
}

void SortByName(Man* manarr, int& size) {
	Man* buffer = manarr;
	for (int i = 1; i < size; i++) {
		Man temp = manarr[i];
		int j = i - 1;
		while (j >= 0 && (int)manarr[j].name[0] > (int)temp.name[0]) {
			manarr[j + 1] = manarr[j];
			j--;
		}
		manarr[j + 1] = temp;
	}
	std::cout << "³������������ ������: " << '\n';
	for (int i = 0; i < size; i++) {
		std::cout << manarr[i].name << '\n';
	}
	manarr = buffer;
	delete[] buffer;
}

void PrintBirthday(Man* manarr, int& size) {
	srand(time(NULL));
	int month;
	std::cout << "������ ����� ����������: ";
	std::cin >> month;
	std::cout << "����������: " << '\n';
	int check = 0;
	for (int i = 0; i < size; i++) {
		if (manarr[i].date.month == month) {
			HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
			int color = rand() % 16;
			int color_date = rand() % 16;
			SetConsoleTextAttribute(h, color);
			std::cout << manarr[i].surname;
			SetConsoleTextAttribute(h, color_date);
			std::cout << ' ' << '(' << manarr[i].date.day << '.' << manarr[i].date.month << '.' << manarr[i].date.year << ')' << '\n';
			SetConsoleTextAttribute(h, 7);
		}
		else check++;
	}
	if (check == size) {
		std::cout << "� ����� ����� ���������� ����." << '\n';
	}
}

Man* ChangeManArrSize(Man* manarr, int& size) {
	int size_new;
	std::cout << "������ ����� ����� ������: ";
	std::cin >> size_new;
	Man* temp = new Man[size_new];
	int temp_size = size;
	size = size_new;
	if (size_new > temp_size) {
		std::cin.ignore();
		for (int i = 0; i < temp_size; i++) {
			temp[i] = manarr[i];
		}
		for (int i = temp_size; i < size_new; i++) {
			temp[i] = GetMan();
			std::cout << '\n';
		}
		delete[] manarr;
		return temp;
	}
	else if (size_new < temp_size) {
		std::cin.ignore();
		for (int i = 0; i < size_new; i++) {
			temp[i] = manarr[i];
		}
		delete[] manarr;
		std::cout << '\n';
		return temp;
	}
}

void SearchBySurname(Man* manarr, int& size) {
	char input[50];
	std::cout << "������ �������: ";
	std::cin.ignore();
	std::cin.getline(input, 50);
	int check = 0;
	for (int i = 0; i < size; i++) {
		if (strcmp(input, manarr[i].surname) == 0) {
			std::cout << "������ ��������: " << manarr[i].surname << '\n';
			check++;
			break;
		}
	}
	if (check == 0) {
		std::cout << "������ �� ��������." << '\n';
	}
}

void SearchByName(Man* manarr, int& size) {
	char input[50];
	std::cout << "������ ��'�: ";
	std::cin.ignore();
	std::cin.getline(input, 50);
	int check = 0;
	for (int i = 0; i < size; i++) {
		if (strcmp(input, manarr[i].name) == 0) {
			std::cout << "������ ��������: " << manarr[i].name << '\n';
			check++;
			break;
		}
	}
	if (check == 0) {
		std::cout << "������ �� ��������." << '\n';
	}
}