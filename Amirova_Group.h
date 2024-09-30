#pragma once
#include <iostream>
#include "Amirova_Actor.h"
#include "Amirova_TheaterActor.h"
#include "boost.h"

using namespace std;

class Amirova_Group
{
		friend class boost::serialization::access;
		vector <shared_ptr<Amirova_Actor>> actors;
	public:
		template<class Archive>
		void serialize(Archive& ar, const unsigned int version)
		{
			ar& actors;
		}
		/*~Amirova_Group() {
			for (auto& i : actors) {
				delete i;
			}
			actors.clear();
			cout << "Список актеров очищен" << endl;
		}*/
		void add_actor();
		void add_theater_actor();
		void show_all_actors();
		void clear_all();
		virtual void save_to_file();
		virtual void load_from_file();
};

