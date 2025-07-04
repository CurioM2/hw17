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
	std::cout << "Введіть довжину автомобіля: ";
	std::cin >> car.len;
	std::cout << "Введіть висоту посадки: ";
	std::cin >> car.clr;
	std::cout << "Введіть об'єм двигуна: ";
	std::cin >> car.eng;
	std::cout << "Введіть потужність двигуна: ";
	std::cin >> car.powr;
	std::cout << "Введіть діаметр коліс: ";
	std::cin >> car.diam;
	std::cin.ignore();
	std::cout << "Введіть колір: ";
	std::cin.getline(car.col, 50);
	std::cout << "Введіть тип коробки передач: ";
	std::cin.getline(car.gear, 50);
	return car;
}

void PrintCar(Car& car) {
	std::cout << "Довжина: " << car.len << '\n';
	std::cout << "Висота посадки: " << car.clr << '\n';
	std::cout << "Об'єм двигуна: " << car.eng << '\n';
	std::cout << "Потужність двигуна: " << car.powr << '\n';
	std::cout << "Діаметр коліс: " << car.diam << '\n';
	std::cout << "Колір: " << car.col << '\n';
	std::cout << "Тип коробки передач: " << car.gear << '\n';
}

//3
void GetBook(Book& book) {
	std::cout << "Введіть назву книги: ";
	std::cin.getline(book.name, 50);
	std::cout << "Введіть автора книги: ";
	std::cin.getline(book.author, 50);
	std::cout << "Введіть видавництво книги: ";
	std::cin.getline(book.publish, 50);
	std::cout << "Введіть жанр книги: ";
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
		std::cout << "Назва книги: " << bookarr[i].name << '\n';
		std::cout << "Автор книги: " << bookarr[i].author << '\n';
		std::cout << "Видавництво книги: " << bookarr[i].publish << '\n';
		std::cout << "Жанр книги: " << bookarr[i].genre << '\n';
		std::cout << '\n';
	}
}

void SearchByAuthor(Book bookarr[], const int& size) {
	char temp[50];
	std::cout << "Введіть автора книги: ";
	std::cin.getline(temp, 50);
	int check = 0;
	for (int i = 0; i < size; i++) {
		if (strcmp(temp, bookarr[i].author) == 0) {
			std::cout << "Книгу знайдено: " << bookarr[i].name << '\n';
			check++;
			break;
		}
	}
	if (check == 0) {
		std::cout << "Книгу не знайдено." << '\n';
	}
}
void SearchByName(Book bookarr[], const int& size) {
	char temp[50];
	std::cout << "Введіть назву книги: ";
	std::cin.getline(temp, 50);
	int check = 0;
	for (int i = 0; i < size; i++) {
		if (strcmp(temp, bookarr[i].name) == 0) {
			std::cout << "Книгу знайдено: " << bookarr[i].name << '\n';
			check++;
			break;
		}
	}
	if (check == 0) {
		std::cout << "Книгу не знайдено." << '\n';
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
	std::cout << "Бібліотека: ";
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
	std::cout << "Бібліотека: ";
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
	std::cout << "Бібліотека: ";
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
	std::cout << "Введіть колір машини: ";
	std::cin.getline(car.color, 50);
	std::cout << "Введіть модель машини: ";
	std::cin.getline(car.model, 50);
	char choice;
	std::cout << "Номер у вигляді числа - а, Номер у вигляді слова - b" << '\n';
	std::cin >> choice;
	if (choice == 'a') {
		std::cin.ignore();
		std::cout << "Введіть номер (до 5 цифр): ";
		std::cin.getline(car.number, 6);
	}
	if (choice == 'b') {
		std::cin.ignore();
		std::cout << "Введіть слово (до 8 символів): ";
		std::cin.getline(car.number, 9);
	}
	return car;

}

void PrintCar2(Car2& car) {
	std::cout << "Колір: " << car.color << '\n';
	std::cout << "Модель: " << car.model << '\n';
	std::cout << "Номер: " << car.number << '\n';
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
	std::cout << "Номер у вигляді числа - а, Номер у вигляді слова - b" << '\n';
	std::cin >> choice;
	if (choice == 'a') {
		std::cout << "Введіть номер (до 5 цифр): ";
		std::cin.ignore();
		std::cin.getline(input, 6);
	}
	if (choice == 'b') {
		std::cout << "Введіть слово (до 8 символів): ";
		std::cin.ignore();
		std::cin.getline(input, 9);
	}
	int check = 0;
	for (int i = 0; i < size; i++) {
		if (strcmp(input, cararr[i].number) == 0) {
			std::cout << "Машину знайдено: " << cararr[i].number << '\n';
			check++;
			break;
		}
	}
	if (check == 0) { 
		std::cout << "Машину не знайдено." << '\n';
	}
}

//5
Creature GetCreature() {
	Creature creature;
	std::cout << "Введіть швидкість пересування: ";
	std::cin >> creature.spd;
	char choice;
	std::cout << "Птах - а, худоба - b, людина - c" << '\n';
	std::cin >> choice;
	std::cin.ignore();
	std::cout << "Введіть колір: ";
	std::cin.getline(creature.color, 50);
	switch (choice) {
	case 'a':
		strcpy_s(creature.type, strlen("птах") + 1, "птах");
		std::cout << "Введіть швидкість польоту: ";
		std::cin >> creature.flspd;
		break;
	case 'b':
		strcpy_s(creature.type, strlen("худоба") + 1, "худоба");
		char choice;
		std::cout << "Парнокопитна худоба - а, не парнокопитна - b: ";
		std::cin >> choice;
		if (choice == 'a') {
			creature.ch = true;
		}
		else if (choice == 'b') {
			creature.ch = false;
		}
		break;
	case 'c':
		strcpy_s(creature.type, strlen("людина") + 1, "людина");
		std::cout << "Введіть рівень IQ людини: ";
		std::cin >> creature.iq;
		break;
	}
	return creature;
} 

void PrintCreature(Creature& creature) {
	std::cout << "Швидкість пересування: " << creature.spd << '\n';
	std::cout << "Тип: " << creature.type << '\n';
	std::cout << "Колір: " << creature.color << '\n';
	if (strcmp(creature.type, "птах") == 0) {
		std::cout << "Швидкість польоту: " << creature.flspd << '\n';
	}
	else if (strcmp(creature.type, "худоба") == 0) {
		if (creature.ch) {
			std::cout << "Парнокопитне: так" << '\n';
		}
		else {
			std::cout << "Парнокопитне: ні" << '\n';
		}
	}
	else if (strcmp(creature.type, "людина") == 0) {
		std::cout << "Рівень IQ: " << creature.iq << '\n';
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
	std::cout << "Птах - а, худоба - b, людина - c" << '\n';
	std::cin >> choice;
	if (choice == 'a') {
		double input;
		std::cout << "Введіть швидкість польоту: ";
		std::cin >> input;
		int check = 0;
		for (int i = 0; i < size; i++) {
			if (input = crearr[i].flspd) {
				std::cout << "Птаху знайдено: " << crearr[i].flspd << '\n';
				check++;
				break;
			}
		}
		if (check == 0) {
			std::cout << "Птаху не знайдено." << '\n';
		}
	}
	else if (choice == 'b') {
		char choice;
		bool input;
		std::cout << "Парнокопитна худоба - а, не парнокопитна - b: ";
		std::cin >> choice;
		if (choice == 'a') {
			input = true;
		}
		else if (choice == 'b') {
			input = false;
		}
		int check = 0;
		for (int i = 0; i < size; i++) {
			if ((input == crearr[i].ch) && strcmp(crearr[i].type, "худоба") == 0) {
				std::cout << "Худобу знайдено: " << crearr[i].color << '\n';
				check++;
				break;
			}
		}
		if (check == 0) {
			std::cout << "Худобу не знайдено." << '\n';
		}
	}
	else if (choice == 'c') {
		int input;
		std::cout << "Введіть рівень IQ людини: ";
		std::cin >> input;
		int check = 0;
		for (int i = 0; i < size; i++) {
			if (input = crearr[i].iq) {
				std::cout << "Людину знайдено: " << crearr[i].iq << '\n';
				check++;
				break;
			}
		}
		if (check == 0) {
			std::cout << "Людину не знайдено." << '\n';
		}
	}
}

//6
Student GetStudent() {
	Student student;
	std::cout << "Введіть прізвище студента: ";
	std::cin.getline(student.surname, 50);
	std::cout << "Введіть назву групи: ";
	std::cin.getline(student.group, 50);
	for (int i = 0; i < student.grades_size; i++) {
		std::cout << "Введіть оцінку студента: ";
		std::cin >> student.grades[i];
	}
	std::cin.ignore();
	return student;
}

void PrintStudent(Student& student) {
	std::cout << "Прізвище студента: " << student.surname << '\n';
	std::cout << "Назва групи: " << student.group << '\n';
	std::cout << "Оцінки: ";
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
	std::cout << "Введіть новий розмір списку: ";
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
	std::cout << "Список відмінників: " << '\n';
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
	std::cout << "Список двієчників: " << '\n';
	for (int i = 0; i < sl_size; i++) {
		std::cout << slarr[i].surname << '\n';
	}
	std::cout << '\n';
}

//7
Man GetMan() {
	Man man;
	std::cout << "Введіть прізвище: ";
	std::cin.getline(man.surname, 50);
	std::cout << "Введіть ім'я: ";
	std::cin.getline(man.name, 50);
	std::cout << "Введіть вік: ";
	std::cin >> man.age;
	std::cout << "Введіть день народження: ";
	std::cin >> man.date.day;
	std::cout << "Введіть місяць народження: ";
	std::cin >> man.date.month;
	std::cout << "Введіть рік народження: ";
	std::cin >> man.date.year;
	std::cin.ignore();
	return man;
}

void PrintMan(Man& man) {
	std::cout << "Прізвище: " << man.surname << '\n';
	std::cout << "Ім'я: " << man.name << '\n';
	std::cout << "Вік: " << man.age << '\n';
	std::cout << "Дата народження: " << man.date.day << '.' << man.date.month << '.' << man.date.year << '\n';
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
	std::cout << "Відсортованний список: " << '\n';
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
	std::cout << "Відсортованний список: " << '\n';
	for (int i = 0; i < size; i++) {
		std::cout << manarr[i].name << '\n';
	}
	manarr = buffer;
	delete[] buffer;
}

void PrintBirthday(Man* manarr, int& size) {
	srand(time(NULL));
	int month;
	std::cout << "Введіть місяць народження: ";
	std::cin >> month;
	std::cout << "Іменинники: " << '\n';
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
		std::cout << "У цьому місяці іменинників немає." << '\n';
	}
}

Man* ChangeManArrSize(Man* manarr, int& size) {
	int size_new;
	std::cout << "Введіть новий розмір списку: ";
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
	std::cout << "Введіть прізвище: ";
	std::cin.ignore();
	std::cin.getline(input, 50);
	int check = 0;
	for (int i = 0; i < size; i++) {
		if (strcmp(input, manarr[i].surname) == 0) {
			std::cout << "Людину знайдено: " << manarr[i].surname << '\n';
			check++;
			break;
		}
	}
	if (check == 0) {
		std::cout << "Людину не знайдено." << '\n';
	}
}

void SearchByName(Man* manarr, int& size) {
	char input[50];
	std::cout << "Введіть ім'я: ";
	std::cin.ignore();
	std::cin.getline(input, 50);
	int check = 0;
	for (int i = 0; i < size; i++) {
		if (strcmp(input, manarr[i].name) == 0) {
			std::cout << "Людину знайдено: " << manarr[i].name << '\n';
			check++;
			break;
		}
	}
	if (check == 0) {
		std::cout << "Людину не знайдено." << '\n';
	}
}