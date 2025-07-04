#include <iostream>
#include <Windows.h>
#include "struct_hw.h";

using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	//1
	{
		//Complex num1;
		//Complex num2;

		//cout << "Введіть перше дійсне число першого комплексного числа: ";
		//cin >> num1.a;
		//cout << "Введіть друге дійсне число першого комплексного числа: ";
		//cin >> num1.b;
		//cout << "Введіть перше дійсне число другого комплексного числа: ";
		//cin >> num2.a;
		//cout << "Введіть друге дійсне число другого комплексного числа: ";
		//cin >> num2.b;
		//
		//cout << "Сума: ";
		//complexPrint(complexAdd(num1, num2));
		//cout << "Різниця: ";
		//complexPrint(complexSubtract(num1, num2));
		//cout << "Добуток: ";
		//complexPrint(complexMultiply(num1, num2));
		//cout << "Різниця: ";
		//complexPrint(complexDivide(num1, num2));
	}

	//2
	{
		//Car car1 = GetCar();
		//cout << '\n';
		//Car car2 = GetCar();
		//cout << '\n';
		//PrintCar(car1);
		//cout << '\n';
		//PrintCar(car2);
	}

	//3
	{
		//const int size = 10;
		//Book bookarr[size];
		//GetBooks(bookarr, size);
		//PrintAllBooks(bookarr, size);
		////GetBook(bookarr[0]);
		////PrintAllBooks(bookarr, size);
		//SortByName(bookarr, size);
		//SortByAuthor(bookarr, size);
		//SortByPublish(bookarr, size);
		//cout << '\n';
		//SearchByAuthor(bookarr, size);
		//SearchByName(bookarr, size);
	}

	//4
	{
		//Car2 car = GetCar2();
		//cout << '\n';
		//PrintCar2(car);
		//const int size = 10;
		//Car2 cararr[size];
		//GetCars(cararr, size);
		//PrintCars(cararr, size);
		//cararr[0] = GetCar2();
		//cout << '\n';
		//PrintCars(cararr, size);
		//SearchCar(cararr, size); 
	}

	//5
	{
		//Creature owl = GetCreature();
		//cout << '\n';
		//PrintCreature(owl);
		//const int size = 10;
		//Creature crearr[size];
		//GetCreatures(crearr, size);
		//PrintCreatures(crearr, size);
		//crearr[0] = GetCreature();
		//cout << '\n';
		//PrintCreatures(crearr, size);
		//SearchCreature(crearr, size);
	}

	//6
	{
		////Student student = GetStudent();
		////cout << '\n';
		////PrintStudent(student);
		//int size = 3;
		//Student* studentarr = new Student[size];
		//GetStudents(studentarr, size);
		//PrintStudents(studentarr, size);
		////studentarr = ChangeSize(studentarr, size);
		////PrintStudents(studentarr, size);
		//FastLearnerList(studentarr, size);
		//SlowLearnerList(studentarr, size);
		//delete[] studentarr;

	}

	//7
	{
		//Man man = GetMan();
		//cout << '\n';
		//PrintMan(man);
		int size = 2;
		Man* manarr = new Man[size];
		GetMen(manarr, size);
		PrintMen(manarr, size);
		while (true) {
			char choice;
			cout << "Відсортувати список - а\nВивести список іменинників місяця - b\nЗмінити розмір списку - c\nПошук - d\nРедагування запису - e\nВивести список - f\n";
			cin >> choice;
			cout << '\n';
			if (choice == 'a') {
				char choice;
				cout << "Відсортувати список за прізвищем - а\nВідсортувати список за ім'ям - b\n";
				cin >> choice;
				cout << '\n';
				if (choice == 'a') {
					SortBySurname(manarr, size);
					std::cout << '\n';
				}
				else if (choice == 'b') {
					SortByName(manarr, size);
					std::cout << '\n';
				}
			}
			if (choice == 'b') {
				PrintBirthday(manarr, size);
				std::cout << '\n';
			}
			if (choice == 'c') {
				manarr = ChangeManArrSize(manarr, size);
			}
			if (choice == 'd') {
				char choice;
				cout << "Знайти за прізвищем - а\nЗнайти за ім'ям - b\n";
				cin >> choice;
				cout << '\n';
				if (choice == 'a') {
					SearchBySurname(manarr, size);
					std::cout << '\n';
				}
				else if (choice == 'b') {
					SearchByName(manarr, size);
					std::cout << '\n';
				}
			}
			if (choice == 'e') {
				int choice;
				cout << "Введіть номер людини, яку треба змінити (починаючи з 0): ";
				cin >> choice;
				cin.ignore();
				manarr[choice] = GetMan();
				cout << '\n';
			}
			if (choice == 'f') {
				PrintMen(manarr, size);
			}
		}
		delete[] manarr;
	}
}

 