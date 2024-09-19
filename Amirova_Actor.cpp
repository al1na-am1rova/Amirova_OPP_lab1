#include "Amirova_Actor.h"
#include "utils.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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
//
//ostream& operator << (ostream& out, const Amirova_Actor& actor) {
//    out << "���: " << actor.name
//        << "\t��� ��������: " << actor.birth_year
//        << "\t���: " << actor.gender
//        << "\t���� (� ������) : " << actor.height
//        << "\t������� ��������� ������(1 - ����, 0 - ���): " << actor.is_able_to_sing 
//        << "\t�����: " << actor.city << endl;
//    return out;
//}

void Amirova_Actor::show(ostream& out) {
    out << "���: " << name
        << "\t��� ��������: " << birth_year
        << "\t���: " << gender
        << "\t���� (� ������) : " << height
        << "\t������� ��������� ������(1 - ����, 0 - ���): " << is_able_to_sing
        << "\t�����: " << city;
}

//istream& operator >> (istream& in, Amirova_Actor& actor) {
//    cout << "���: ";
//    in.ignore(1000, '\n');
//    getline(in, actor.name);
//    cout << "��� ��������: " << endl;
//    actor.birth_year = get_correct_number(1900, 2024);
//    cout << "���: " << endl;
//    actor.gender = get_correct_gender();
//    cout << "���� (� ������) : " << endl;
//    actor.height = get_correct_number(0.0, 4.0);
//    cout << "������� ��������� ������(1 - ����, 0 - ���): " << endl;
//    actor.is_able_to_sing = get_correct_number(0, 1);
//    cout << "�����: ";
//    in.ignore(1000, '\n');
//    getline(in, actor.city);
//    return in;
//}

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

void Amirova_Actor::get_data_from_file(ifstream& fin)
{
    /*fin.ignore();
    getline(fin, name);
    fin >> birth_year >> gender >> height >> is_able_to_sing >> city;
    return;*/
}

void Amirova_Actor::load_data_to_file(ofstream& fout)
{
    /*fout << name << endl 
        << birth_year << endl 
        << gender << endl
        << height << endl
        << is_able_to_sing << endl
        << city << endl;
    return;*/
}
