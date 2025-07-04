#pragma once

//1
struct Complex {
	double a;
	double b;
};
Complex complexAdd(Complex& num1, Complex& num2);
Complex complexSubtract(Complex& num1, Complex& num2);
Complex complexMultiply(Complex& num1, Complex& num2);
Complex complexDivide(Complex& num1, Complex& num2);
void complexPrint(Complex num);

//2
struct Car {
	int len;
	int clr;
	int eng;
	int powr;
	int diam;
	char col[50];
	char gear[50];
};
Car GetCar();  
void PrintCar(Car& car);

//3
struct Book {
	char name[50];
	char author[50];
	char publish[50];
	char genre[50];
};
void GetBook(Book& book);
void GetBooks(Book bookarr[], const int& size);
void PrintAllBooks(Book bookarr[], const int& size);
void SearchByAuthor(Book bookarr[], const int& size);
void SearchByName(Book bookarr[], const int& size);
void SortByName(Book bookarr[], const int& size);
void SortByAuthor(Book bookarr[], const int& size);
void SortByPublish(Book bookarr[], const int& size);

//4
struct Car2 {
	char color[50];
	char model[50];
	char number[9];
};
Car2 GetCar2();
void PrintCar2(Car2& car);
void GetCars(Car2 cararr[], const int& size);
void PrintCars(Car2 cararr[], const int& size);
void SearchCar(Car2 cararr[], const int& size);

//5
struct Creature {
	int spd;
	char type[50];
	char color[50];
	double flspd;
	bool ch;
	int iq;


};
Creature GetCreature(); 
void PrintCreature(Creature& creature);
void GetCreatures(Creature crearr[], const int& size);
void PrintCreatures(Creature crearr[], const int& size);
void SearchCreature(Creature crearr[], const int& size);

//6
struct Student {
	char surname[50];
	char group[50];
	int grades_size = 5;
	int* grades = new int[grades_size];
};

Student GetStudent();
void PrintStudent(Student& student);
void GetStudents(Student* studentarr, int& size);
void PrintStudents(Student* studentarr, int& size);
Student* ChangeSize(Student* studentarr, int& size);
void FastLearnerList(Student* studentarr, int& size);
void SlowLearnerList(Student* studentarr, int& size);

//7
struct Date {
	int day;
	int month;
	int year;
};
struct Man {
	char surname[50];
	char name[50];
	int age;
	Date date;
};
Man GetMan();
void PrintMan(Man& man);
void GetMen(Man* manarr, int& size);
void PrintMen(Man* manarr, int& size);
void SortBySurname(Man* manarr, int& size);
void SortByName(Man* manarr, int& size);
void PrintBirthday(Man* manarr, int& size);
Man* ChangeManArrSize(Man* studentarr, int& size);
void SearchBySurname(Man* manarr, int& size);
void SearchByName(Man* manarr, int& size);