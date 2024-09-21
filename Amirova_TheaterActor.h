#pragma once
#include "Amirova_Actor.h"

class Amirova_TheaterActor :
    public Amirova_Actor
{
friend class boost::serialization::access;
public:
    string theater_name;
    int experience;

public:

	void create(istream& in) override;
	void show(ostream& out) override;

	template <class Archive>
	void serialize(Archive& ar, const unsigned int version) {
		ar& boost::serialization::base_object<Amirova_Actor>(*this);
		ar& theater_name;
		ar& experience;
	}
};

