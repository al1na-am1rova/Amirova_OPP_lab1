#pragma once
#include "boost.h"

using namespace std;

class Amirova_Actor
{
	friend class boost::serialization::access;

protected:
	string name;
	int birth_year;
	string gender;
	double height; 
	bool is_able_to_sing;
	string city;
public:

	friend string get_correct_gender();

	virtual void create(istream& in);
	virtual void show(ostream& out);

	Amirova_Actor() {}
	virtual ~Amirova_Actor() {}

	template <class Archive>
	void serialize(Archive& ar, const unsigned int version) {
		ar& name;
		ar& birth_year;
		ar& gender;
		ar& height;
		ar& is_able_to_sing;
		ar& city;
	}
};

