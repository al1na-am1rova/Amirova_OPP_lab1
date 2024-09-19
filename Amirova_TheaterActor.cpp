#include "Amirova_TheaterActor.h"
#include "utils.h"
#include <iostream>
#include <fstream>
#include <string>

//ostream& operator << (ostream& out, const Amirova_TheaterActor& theater_actor) {
//    out << theater_actor;
//    out << "�����, � ������� ���� �������� � ��������� �����: " << theater_actor.theater_name << endl
//        << "����� ���� ������ � ������: " << theater_actor.experience << endl;
//    return out;
//}
//
//istream& operator >> (istream& in, Amirova_TheaterActor& theater_actor) {
//    in >> theater_actor;
//    cout << "������� �����, � ������� ���� �������� � ��������� �����: ";
//    in.ignore(1000, '\n');
//    getline(in, theater_actor.theater_name);
//    cout << "������� ����� ���� ������ � ������: ";
//    theater_actor.experience = get_correct_number(0,100);
//    return in;
//}

void Amirova_TheaterActor::show(ostream& out) {
    Amirova_Actor::show(cout);
    out << "�����, � ������� ���� �������� � ��������� �����: " << theater_name
        << "\t����� ���� ������ � ������: " << experience << endl;
}

void Amirova_TheaterActor::create(istream& in) {
    Amirova_Actor::create(cin);
    cout << "������� �����, � ������� ���� �������� � ��������� �����: ";
    getline(in, theater_name);
    cout << "������� ����� ���� ������ � ������: ";
    experience = get_correct_number(0, 2024 - birth_year);

}