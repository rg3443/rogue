#ifndef CCLANLIST_H_INCLUDED
#define CCLANLIST_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <ctime>
using namespace std;

#include "../../Sup/rndptk/rndforclan.h"
#include "CClan.h"

class CClanList {
public:
	CClanList(){}
	void init(int clan_ammount);
	CClan* get_clan(int clan_id) { return &all_clans[clan_id]; }
	int size() {return all_clans.size(); }
protected:
	vector<CClan> all_clans;
	CRandomClanGenerator clan_generator;
};


#endif
