#pragma once
#include "Amirova_Group.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/export.hpp>

using boost::archive::archive_flags;

vector<shared_ptr<Amirova_Actor>> Amirova_Group :: actors;

void Amirova_Group::add_actor()
{
	cout << "Ввод нового актера" << endl;
	shared_ptr<Amirova_Actor> actor = make_shared<Amirova_Actor>();
	actor->Amirova_Actor::create(cin);
	actors.insert(actors.begin(), actor);
}

void Amirova_Group::add_theater_actor()
{
	cout << "Ввод нового актера" << endl;
	shared_ptr<Amirova_TheaterActor> theater_actor = make_shared<Amirova_TheaterActor>();
	theater_actor->Amirova_TheaterActor::create(cin);
	actors.insert(actors.begin(), theater_actor);
}

void Amirova_Group::show_all_actors()
{
	if (actors.size() > 0) {
		cout << "Список всех актеров" << endl;
		for (auto& actor : actors) {
			actor->show(cout);
		}
	}
	else {
		cout << "Список пуст" << endl;
	}
}

void Amirova_Group::clear_all() {
	/*for (auto& i : actors) {
		delete i;
	}*/
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
		cin.ignore();
		getline(cin, filename);

		ofstream fout;
		fout.open(filename, ios::out);

		if (fout.is_open()) {

			boost::archive::text_oarchive write(fout, archive_flags::no_header);
			write << actors.size();
			for (auto& actor : actors) {
				write << *actor;
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
	cin.ignore();
	getline(cin, filename);
	ifstream fin;
	fin.open(filename, ios::in);

	if (fin.is_open()) {
		boost::archive::text_iarchive load(fin, archive_flags::no_header);
		int counter;
		load >> counter;
		for (int i = 0; i < counter; i ++) {
			shared_ptr<Amirova_Actor> actor = make_shared<Amirova_Actor>();

			load >> *actor;

			actors.insert(actors.begin(), actor);
		}
		cout << "Данные успешно считаны из файла" << endl;
	}

	else {
		cout << "При считывании данных произошла ошибка. Возможно, такого файла не существует" << endl;
	}
}
