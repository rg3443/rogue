#ifndef CPERSON_H_INCLUDED
#define CPERSON_H_INCLUDED


#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <ctime>
using namespace std;

#include "GWorld.h"
#include "CBackgrounds.h"

enum EPersonRoles_slot1 {
    LAWFULL = 1000,
    NEUTRALSLOT1 = 1001,
    CHAOTIC = 1002
};
enum EPersonRoles_slot2 {
    GOOD = 1000,
    NEUTRALSLOT2 = 1001,
    EVIL = 1002
};


class CPerson {
public:
    CPerson() {}
    void Init(int id,string fname,string sname,int rolecode1,int rolecode2,CBackground * backcode);
	
	//	GETTERS
    int GetId() { return person_id; }
    string GetFname() { return first_name; }
    string GetSname() { return second_name; }
    int GetRolecode(int slot_id) { return person_role_code[slot_id]; }
    int GetMoney() { return money; }
    int GetFame() { return fame; }
    int GetInfluence() { return influence; }
    CBackground* GetBackground() { return background_code; }
	int GetWounds() { return wounds; }
	int GetDeath() { return death; }
    int GetCurrLocX() { return currentPosX; }
    int GetCurrLocY() { return currentPosY; }
    int PropertySize() { return propertys_owned.size(); }
    //	SETTERS
    void AddProperty(SProperty* new_property);
    void SetMoney(int money) { this->money = money; if(this->money < 0) { money = 0; } }
    void SetFame(int fame) { this->fame = fame; }
    void SetInfluence(int influence) { this->influence = influence; }
	void SetWounds(int wounds) { this->wounds = wounds; }
	void SetDeath(int death) { this->death = death; }
    //
    void set_current_location(int x,int y) { currentPosX = x; currentPosY = y; }
	
protected:
    int person_id;
    string first_name,second_name;
    int person_role_code[2];
    CBackground * background_code;

    //
    int money,fame,influence;
	int wounds,death;
    vector<SProperty*> propertys_owned;

    //
    int currentPosX,currentPosY;

};

#endif
