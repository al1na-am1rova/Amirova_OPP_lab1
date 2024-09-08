#pragma once
#include "Amirova_Group.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

vector<Amirova_Actor*> Amirova_Group :: actors;

void Amirova_Group::add_actor()
{
	cout << "Ввод нового актера" << endl;
	Amirova_Actor* actor = new Amirova_Actor;
	cin >> *actor;
	actors.insert(actors.begin(), actor);
}

void Amirova_Group::show_all_actors()
{
	if (actors.size() > 0) {
		cout << "Список всех актеров" << endl;
		for (auto& actor : actors) {
			cout << *actor << endl;
		}
	}
	else {
		cout << "Список пуст" << endl;
	}
}

void Amirova_Group::clear_all() {
	for (auto i : actors) {
		delete i;
	}
	actors.clear();
	cout << "Список актеров очищен" << endl;	
}

void Amirova_Group::save_to_file()
{
	if (actors.size() == 0) {
		cout << "Нет данных для сохранения" << endl;
	}
	else {
		string filename;
		cout << "Введите название файла:" << endl;
		cin >> filename;
		ofstream fout;
		fout.open(filename, ios::out);
		if (fout.is_open()) {
			fout << actors.size() << endl;
			for (auto& actor : actors) {
				(*actor).load_data_to_file(fout);
			}
			cout << "Данные успешно сохранены в файл" << endl;
		}
		else {
			cout << "При сохранении возникла ошибка. Возможно, такого файла не существует" << endl;
		}
	}
}

void Amirova_Group::load_from_file()
{
	string filename;
	cout << "Введите название файла:" << endl;
	cin >> filename;
	ifstream fin;
	fin.open(filename, ios::in);
	if (fin.is_open()) {
		int counter;
		fin >> counter;
		for (int i = 0; i < counter; i ++) {
			Amirova_Actor* actor = new Amirova_Actor;
			(*actor).get_data_from_file(fin);
			actors.insert(actors.begin(), actor);
		}
		cout << "Данные успешно считаны из файла" << endl;
	}
	else {
		cout << "При считывании данных произошла ошибка. Возможно, такого файла не существует" << endl;
	}
}
