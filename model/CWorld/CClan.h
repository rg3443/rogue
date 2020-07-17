#ifndef CCLAN_H_INCLUDED
#define CCLAN_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <ctime>
using namespace std;

#include "GWorld.h"
#include "CPerson.h"

class CClan {
public:
	CClan() {}
	void init(int clan_id,int clan_type, string clan_name);
	void new_leader(SBasicPersonData leader) { titul_list.add_leader(leader); }
	void new_righthand(SBasicPersonData rhand) { titul_list.add_righthand(rhand); }
	void new_pretender(SBasicPersonData pretender) { titul_list.add_pretender(pretender); }
	void add_member(CPerson* new_member) { members.push_back(new_member); }

	int get_id() { return clan_id; }
	int get_type() { return clan_type; }
	string get_name() { return clan_name; }
	int get_leader_id() { return titul_list.leader.person_id; }
	int get_rhand_id() { return titul_list.righthand.person_id; }
	int get_pretender_id() { return titul_list.pretender.person_id; }
	SPolitics* get_politics() { return &politics_with_other_clans; }
	int get_person_size() { return members.size(); }
	//
	void consoleShowMembers();
protected:
	int clan_id,clan_type;
	string clan_name;
	STituls titul_list;
	SPolitics politics_with_other_clans;
	vector<CPerson*> members;
};

#endif
