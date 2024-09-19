#include "Amirova_TheaterActor.h"
#include "utils.h"
#include <iostream>
#include <fstream>
#include <string>

//ostream& operator << (ostream& out, const Amirova_TheaterActor& theater_actor) {
//    out << theater_actor;
//    out << "Театр, в котором актёр работает в настоящее время: " << theater_actor.theater_name << endl
//        << "Общий стаж работы в театре: " << theater_actor.experience << endl;
//    return out;
//}
//
//istream& operator >> (istream& in, Amirova_TheaterActor& theater_actor) {
//    in >> theater_actor;
//    cout << "Введите театр, в котором актёр работает в настоящее время: ";
//    in.ignore(1000, '\n');
//    getline(in, theater_actor.theater_name);
//    cout << "Введите общий стаж работы в театре: ";
//    theater_actor.experience = get_correct_number(0,100);
//    return in;
//}

void Amirova_TheaterActor::show(ostream& out) {
    Amirova_Actor::show(cout);
    out << "Театр, в котором актёр работает в настоящее время: " << theater_name
        << "\tОбщий стаж работы в театре: " << experience << endl;
}

void Amirova_TheaterActor::create(istream& in) {
    Amirova_Actor::create(cin);
    cout << "Введите театр, в котором актёр работает в настоящее время: ";
    getline(in, theater_name);
    cout << "Введите общий стаж работы в театре: ";
    experience = get_correct_number(0, 2024 - birth_year);

}