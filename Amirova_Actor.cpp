#include "Amirova_Actor.h"
#include "utils.h"
#include <iostream>
#include <fstream>
#include <string>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
using namespace std;

BOOST_CLASS_IMPLEMENTATION(Amirova_Actor, boost::serialization::level_type::object_serializable)

string get_correct_gender() {
    string gender;
    while ((cin >> gender).fail()
        || cin.peek() != '\n'
        || (gender != "�������" && gender != "�������"))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "������� ��� ('�������' / '�������') :" << endl;
    }
    return gender;
}

void Amirova_Actor::show(ostream& out) {
    out << "���: " << name
        << "\t��� ��������: " << birth_year
        << "\t���: " << gender
        << "\t���� (� ������) : " << height
        << "\t������� ��������� ������(1 - ����, 0 - ���): " << is_able_to_sing
        << "\t�����: " << city << endl;
}

void Amirova_Actor::create(istream& in) {
    cout << "����� ����" << endl;
    cout << "���: ";
    in.ignore(1000, '\n');
    getline(in, name);
    cout << "��� ��������: " << endl;
    birth_year = get_correct_number(1900, 2024);
    cout << "���: " << endl;
    gender = get_correct_gender();
    cout << "���� (� ������) : " << endl;
    height = get_correct_number(0.0, 4.0);
    cout << "������� ��������� ������(1 - ����, 0 - ���): " << endl;
    is_able_to_sing = get_correct_number(0, 1);
    cout << "�����: ";
    in.ignore(1000, '\n');
    getline(in, city);
}

//void Amirova_Actor::get_data_from_file(ifstream& fin)
//{
//    /*fin.ignore();
//    getline(fin, name);
//    fin >> birth_year >> gender >> height >> is_able_to_sing >> city;
//    return;*/
//}
//
//void Amirova_Actor::load_data_to_file(ofstream& fout)
//{
//    /*fout << name << endl 
//        << birth_year << endl 
//        << gender << endl
//        << height << endl
//        << is_able_to_sing << endl
//        << city << endl;
//    return;*/
//}
