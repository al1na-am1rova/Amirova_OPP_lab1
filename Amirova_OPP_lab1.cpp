﻿#include <iostream>
#include <string>
#include <windows.h> 
#include "Amirova_Actor.h"
#include "Amirova_Group.h"
#include "utils.h"

using namespace std;

void menu() {
	cout << "Меню" << endl
		<< "1 - ввести нового актера" << endl
        << "2 - ввести нового актера театра" << endl
		<< "3 - вывести всех актеров" << endl
		<< "4 - записать данные об актерах в файл" << endl
		<< "5 - считать данные об актерах из файла" << endl
        << "6 - очистить список" << endl
        << "7 - выход" << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Amirova_Group group;

	while (true) {
		menu();
        int command = get_correct_number(1, 7);
        switch (command) {
        case 1:
            group.add_actor();
            break;
        case 2:
            group.add_theater_actor();
            break;
        case 3:
            group.show_all_actors();
            break;
        case 4:
            group.save_to_file();
            break;
        case 5:
            group.load_from_file();
            break;
        case 6:
            group.clear_all(); 
            break;
        case 7:
            return 0;
        }
	}
}
