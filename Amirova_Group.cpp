#pragma once
#include "Amirova_Group.h"

BOOST_CLASS_EXPORT(Amirova_TheaterActor)

using boost::archive::archive_flags;

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
	if (!actors.empty()) {
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
			write << actors;

			cout << "������ ������� ��������� � ����" << endl;
		}

		else {
			cout << "��� ���������� �������� ������. ��������, ������ ����� �� ����������" << endl;
		}
	}

}

void Amirova_Group::load_from_file()
{
	clear_all();
	string filename;
	cout << "������� �������� �����:" << endl;
	cin.ignore();
	getline(cin, filename);
	ifstream fin;
	fin.open(filename, ios::in);

	if (fin.is_open()) {
		boost::archive::text_iarchive load(fin, archive_flags::no_header);
		load >> actors;
		cout << "������ ������� ������� �� �����" << endl;
	}

	else {
		cout << "��� ���������� ������ ��������� ������. ��������, ������ ����� �� ����������" << endl;
	}
}
