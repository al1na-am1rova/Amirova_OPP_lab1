#pragma once
#include "Amirova_Actor.h"

class Amirova_TheaterActor :
    public Amirova_Actor
{
public:
    string theater_name;
    int experience;

public:
	friend ostream& operator << (ostream& out, const Amirova_Actor& theater_actor);
	friend istream& operator >> (istream& in, Amirova_Actor& theater_actor);

	//template <typename T>
	//friend T get_correct_number(T min, T max);
	//friend string get_correct_gender();

	void create(istream& in) override;
	void show(ostream& out) override;

	void get_data_from_file(ifstream& fin);
	void load_data_to_file(ofstream& fout);
};

