#pragma once
#include <iostream>
#include <string>

using namespace std;

class Amirova_Actor
{
private:
	string name;
	int birth_year;
	string gender;
	double height; 
	bool is_able_to_sing;
	string city;
public:
	friend ostream& operator << (ostream& out, const Amirova_Actor& actor);
	friend istream& operator >> (istream& in, Amirova_Actor& actor);
	
	template <typename T>
	friend T get_correct_number(T min, T max);
	friend string get_correct_gender();

	void get_data_from_file(ifstream& fin);
	void load_data_to_file(ofstream& fout);
};

