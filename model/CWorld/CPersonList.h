#ifndef CPERSONLIST_H_INCLUDED
#define CPERSONLIST_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <ctime>
using namespace std;

#include "../../Sup/rndptk/rndname.h"
#include "../../Sup/rndptk/rndsname.h"
#include "../../Sup/rndptk/rndptk.h"
#include "CPerson.h"
#include "CBackgroundsList.h"
#include "CLocation.h"
//#include "CPropertyList.h"
//class CLocation;

class CPersonList {
public:
	CPersonList() {}
	void init(int person_ammount);
	CPerson* get_person(int person_id) { return &all_persons[person_id]; }
    CPerson* get_person_by_global_id(int global_id);
    //void CheckAlive(SLocationMap map,SPropertyList * propList); // нужно как-то передать список пропов сюда, либо каждой персоне давать id своего проперти, либо как-то убрать этот лист из проплиста

	int size() { return all_persons.size(); }
	void SaveData(int saveID);
protected:
	vector<CPerson> all_persons;
    vector<CPerson> dead_persons;
	CRandomNameGenerator random_name_generator;
	CRandomSNameGenerator random_sname_generator;
};

#endif
