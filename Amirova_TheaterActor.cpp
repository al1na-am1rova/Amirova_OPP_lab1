#include "Amirova_TheaterActor.h"
#include "utils.h"

void Amirova_TheaterActor::show(ostream& out) {
    Amirova_Actor::show(cout);
    out << "Театр, в котором актёр работает в настоящее время: " << theater_name
        << "\tОбщий стаж работы в театре (лет): " << experience << endl;
}

void Amirova_TheaterActor::create(istream& in) {
    Amirova_Actor::create(cin);
    cout << "Введите театр, в котором актёр работает в настоящее время: ";
    getline(in, theater_name);
    cout << "Введите общий стаж работы в театре (лет): ";
    experience = get_correct_number(0, 2024 - birth_year);

}
