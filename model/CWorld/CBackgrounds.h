#ifndef CBACKGROUNDS_H_INCLUDED
#define CBACKGROUNDS_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <ctime>
using namespace std;
#include "GWorld.h"

class CBackground {
public:
	CBackground() {}
	CBackground(string name) { this->set_name(name); }
	void set_name(string name) { this->name = name; }
	void add_bonuscode(int bonuscode) { bonuscodeList.push_back(bonuscode); }
	void add_sit_veigs(SConsequences newVeigs);
    void set_id(int id) { this->id = id; }

	string get_name() { return name; }
	int get_id() { return id; }
	vector<int> get_bonuscode_list() { return bonuscodeList; }
	friend std::ostream& operator<< (std::ostream &out, const CBackground &backgra);
	SConsequences GetSitVeigs() { return situationVeigs; }
protected:
    int id;
	string name;
	vector<int> bonuscodeList;
	SConsequences situationVeigs;
};

#endif
