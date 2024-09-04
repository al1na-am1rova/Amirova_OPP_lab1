#include "Amirova_Actor.h"
#include <iostream>
#include <fstream>
#include <string>

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

string get_correct_gender() {
    string gender;
    while ((cin >> gender).fail()
        || cin.peek() != '\n'
        || (gender != "мужской" && gender != "женский"))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Введите пол ('мужской' / 'женский') :" << endl;
    }
    return gender;
}

ostream& operator << (ostream& out, const Amirova_Actor& actor) {
    out << "Имя: " << actor.name
        << "\tГод рождения: " << actor.birth_year
        << "\tПол: " << actor.gender
        << "\tРост (в метрах) : " << actor.height
        << "\tНаличие вокальных данных(1 - есть, 0 - нет): " << actor.is_able_to_sing 
        << "\tГород: " << actor.city << endl;
    return out;
}

istream& operator >> (istream& in, Amirova_Actor& actor) {
    cout << "Новый актёр" << endl;
    cout << "Имя: ";
    in.ignore(1000, '\n');
    getline(in, actor.name);
    cout << "Год рождения: " << endl;
    actor.birth_year = get_correct_number(1900, 2024);
    cout << "Пол: " << endl;
    actor.gender = get_correct_gender();
    cout << "Рост (в метрах) : " << endl;
    actor.height = get_correct_number(0.0, 4.0);
    cout << "Наличие вокальных данных(1 - есть, 0 - нет): " << endl;
    actor.is_able_to_sing = get_correct_number(0, 1);
    cout << "Город: ";
    in.ignore(1000, '\n');
    getline(in, actor.city);
    return in;
}

void Amirova_Actor::get_data_from_file(ifstream& fin)
{
    fin.ignore();
    getline(fin, name);
    fin >> birth_year >> gender >> height >> is_able_to_sing >> city;
    return;
}

void Amirova_Actor::load_data_to_file(ofstream& fout)
{
    fout << name << endl 
        << birth_year << endl 
        << gender << endl
        << height << endl
        << is_able_to_sing << endl
        << city << endl;
    return;
}
