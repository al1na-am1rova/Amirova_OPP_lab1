#include "Amirova_TheaterActor.h"
#include "utils.h"
#include <iostream>
#include <fstream>
#include <string>
#include <boost/serialization/export.hpp>

BOOST_CLASS_EXPORT(Amirova_TheaterActor)

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