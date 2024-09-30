#include "Amirova_Actor.h"
#include "utils.h"
using namespace std;

BOOST_CLASS_IMPLEMENTATION(Amirova_Actor, boost::serialization::level_type::object_serializable)

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

void Amirova_Actor::show(ostream& out) {
    out << "Имя: " << name
        << "\tГод рождения: " << birth_year
        << "\tПол: " << gender
        << "\tРост (в метрах) : " << height
        << "\tНаличие вокальных данных(1 - есть, 0 - нет): " << is_able_to_sing
        << "\tГород: " << city << endl;
}

void Amirova_Actor::create(istream& in) {
    cout << "Новый актёр" << endl;
    cout << "Имя: ";
    in.ignore(1000, '\n');
    getline(in, name);
    cout << "Год рождения: " << endl;
    birth_year = get_correct_number(1900, 2024);
    cout << "Пол: " << endl;
    gender = get_correct_gender();
    cout << "Рост (в метрах) : " << endl;
    height = get_correct_number(0.0, 4.0);
    cout << "Наличие вокальных данных(1 - есть, 0 - нет): " << endl;
    is_able_to_sing = get_correct_number(0, 1);
    cout << "Город: ";
    in.ignore(1000, '\n');
    getline(in, city);
}
