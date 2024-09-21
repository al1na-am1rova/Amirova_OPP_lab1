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
	cout << "���� ������ ������" << endl;
	shared_ptr<Amirova_Actor> actor = make_shared<Amirova_Actor>();
	actor->Amirova_Actor::create(cin);
	actors.insert(actors.begin(), actor);
}

void Amirova_Group::add_theater_actor()
{
	cout << "���� ������ ������" << endl;
	shared_ptr<Amirova_TheaterActor> theater_actor = make_shared<Amirova_TheaterActor>();
	theater_actor->Amirova_TheaterActor::create(cin);
	actors.insert(actors.begin(), theater_actor);
}

void Amirova_Group::show_all_actors()
{
	if (actors.size() > 0) {
		cout << "������ ���� �������" << endl;
		for (auto& actor : actors) {
			actor->show(cout);
		}
	}
	else {
		cout << "������ ����" << endl;
	}
}

void Amirova_Group::clear_all() {
	/*for (auto& i : actors) {
		delete i;
	}*/
	actors.clear();
	cout << "������ ������� ������" << endl;	
}

void Amirova_Group::save_to_file()
{
	if (actors.size() == 0) {
		cout << "��� ������ ��� ����������" << endl;
	}
	else {
		string filename;
		cout << "������� �������� �����:" << endl;
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

			cout << "������ ������� ��������� � ����" << endl;
		}

		else {
			cout << "��� ���������� �������� ������. ��������, ������ ����� �� ����������" << endl;
		}
	}

}

void Amirova_Group::load_from_file()
{
	string filename;
	cout << "������� �������� �����:" << endl;
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
		cout << "������ ������� ������� �� �����" << endl;
	}

	else {
		cout << "��� ���������� ������ ��������� ������. ��������, ������ ����� �� ����������" << endl;
	}
}
