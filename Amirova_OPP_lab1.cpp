#include <iostream>
#include <string>
#include <windows.h> 
#include "Amirova_Actor.h"
#include "Amirova_Group.h"

using namespace std;

template <typename T>
T get_correct_number(T min, T max)
{
    T x;
    while ((cin >> x).fail()
        || cin.peek() != '\n'
        || x < min || x > max)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Введите число от " << min << " до " << max << ":";
    }
    return x;
}

void menu() {
	cout << "Меню" << endl
		<< "1 - ввести нового актера" << endl
		<< "2 - вывести всех актеров" << endl
		<< "3 - записать данные об актерах в файл" << endl
		<< "4 - считать данные об актерах из файла" << endl
        << "5 - очистить список" << endl
        << "6 - выход" << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

	while (true) {
		menu();
        int command = get_correct_number(1, 6);
        switch (command) {
        case 1:
            Amirova_Group::add_actor();
            break;
        case 2:
            Amirova_Group::show_all_actors();
            break;
        case 3:
            Amirova_Group::save_to_file();
            break;
        case 4:
            Amirova_Group::load_from_file();
            break;
        case 5:
            Amirova_Group::clear_all(); 
            break;
        case 6:
            return 0;
        }
	}
}
