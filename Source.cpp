#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <time.h>
using namespace std;


class Student
{
public:
	string FirstName;
	int age;
	Student (){}

	Student(string _name, int _age)
	{
		FirstName = _name;
		age = _age;
	}
	void Print()
	{
		cout << setw(15) << FirstName << setw(6) << age << endl;
	}

	

};
bool sortageup(const Student& st1, const Student& st2) {
	return st1.age > st2.age;
}

bool sortagedown(const Student& st1, const Student& st2) {
	return st1.age < st2.age;
}

bool tooyoung(const Student& st1) {
	return st1.age < 18;
}



int increaseby2(const Student& st1) {
	return st1.age + 2;
}

int decreaseby2(const Student& st1) {
	return st1.age - 2;
}

void main (){
	setlocale(LC_ALL, "ru");

	cout << "Список студентов: " << endl;
	vector <Student> students{
	Student("Anya", 15),
	Student("Lisa", 24),
	Student("Katya", 37),
	Student("Victor", 16),
	Student("Denis", 22)
	};

	for (auto el : students)
	{
		el.Print();
	}
	cout << endl;

	cout << "Поиск минимального возраста: ";
	auto iit = min_element(students.begin(), students.end(), [](Student& st1, Student& st2) {return st1.age < st2.age; });
	cout << iit->age << endl << endl;


	cout << "Поиск максимального возраста: ";
	auto it = max_element(students.begin(), students.end(), [](Student& st1, Student& st2) {return st1.age < st2.age; });
	cout << it->age << endl << endl;



	cout << "Сортировка по убыванию: " << endl;
	sort(students.begin(), students.end(), sortageup);

	for (auto el : students)
	{
		el.Print();
	}
	cout << endl;

	cout << "Сортировка по возрастанию: " << endl;

	sort(students.begin(), students.end(), sortagedown);

	for (auto el : students)
	{
		el.Print();
	}
	cout << endl;

	cout << "Увеличение возраста на 2: " << endl;
	for_each(students.begin(), students.end(), [](Student& st1) {return st1.age + 2; });
	for (auto el : students)
	{
		el.Print();
	}
	cout << endl;

	cout << "Уменьшение возраста на 2: " << endl;
	for_each(students.begin(), students.end(), decreaseby2);
	for (auto el : students)
	{
		el.Print();
	}
	cout << endl;

	cout << "Удаление по искомому значению (меньше 18 лет): " << endl;

	auto res = remove_if(students.begin(), students.end(), tooyoung);
	students.erase(res, students.end());

	for (auto el : students)
	{
		el.Print();
	}
	cout << endl;
}