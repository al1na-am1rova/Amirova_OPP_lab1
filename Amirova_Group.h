#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Amirova_Actor.h"
#include "Amirova_TheaterActor.h"

using namespace std;

class Amirova_Group
{
	private:
		static vector <shared_ptr<Amirova_Actor>> actors;
	public:
		/*~Amirova_Group() {
			for (auto& i : actors) {
				delete i;
			}
			actors.clear();
			cout << "Список актеров очищен" << endl;
		}*/
		static void add_actor();
		static void add_theater_actor();
		static void show_all_actors();
		static void clear_all();
		static void save_to_file();
		static void load_from_file();
};

