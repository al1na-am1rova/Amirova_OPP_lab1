#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Amirova_Actor.h"

using namespace std;

class Amirova_Group
{
	public:
		static vector <Amirova_Actor> actors;
		static void add_actor();
		static void show_all_actors();
		static void clear_all();
		static void save_to_file();
		static void load_from_file();
};

