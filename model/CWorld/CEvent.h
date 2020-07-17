#ifndef CEVENT_H_INCLUDED
#define CEVENT_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <ctime>
using namespace std;

#include "GWorld.h"
#include "CBackgrounds.h"
#include "CPerson.h"

enum EEventTypes {
    PEACEFULL_MEETING = 0,
    THREAT = 1,
    DEAL = 2,
    NEGOTIATION = 3,
    INCIDENT = 4,
	PROPERTY_MANAGMENT = 5
};

enum ESpesialCodesForEvents {
    WHOLE_POPULATION = 1212 //WHOLE LOCATION POPULATION
};

class CBackcodeRule {
    CBackground * backcode;
    SConsequences rule;
public:
    CBackcodeRule() {}
    CBackcodeRule(CBackground * backcode_,SConsequences rule_) {
        backcode = backcode_;
        rule = rule_;
    }
    CBackground * GetBackcode() { return backcode; }
    SConsequences GetRule() { return rule; }
};

class CBackcodeTriger {
public:
    CBackcodeTriger() {}
    CBackcodeTriger(CBackground * triger_,int veig_) { 
		triger = triger_; 
		veig = veig_;
	}
    CBackground* GetBackcode() { return triger; }
    int GetVeig() { return veig; }
    CBackground* GetTriger() { return triger; }
private:
    CBackground * triger;
    int veig; //in %
};

/*
	uslovija dlya uchastija personi v slote
	esli cond == -99 usloviy net
*/

struct SPropertyRules {
	string slotNameOldOwner,slotNameNewOwner;
	SPropertyRules() {}
	SPropertyRules(string oldOwnerSlotName,string newOwnerSlotName) {
		slotNameOldOwner = oldOwnerSlotName;
		slotNameNewOwner = newOwnerSlotName;
	}
};

struct SCondition {
	int needFame,needInfluence,needMoney,needWounds;
	SCondition() {}
	SCondition(int fame,int influence,int money,int wounds) {
		needFame = fame;
		needInfluence = influence;
		needMoney = money;
		needWounds = wounds;
	}
};

struct SSlot {
    string slotName;
    int actorAmmount;
	SCondition personCondition;
	SPersonalConsequences personalConsequences;
    SSlot() {}
    SSlot(string name_,int actorAm,SCondition condition) {
        slotName = name_;
        actorAmmount = actorAm;
		personCondition = condition;
    }
	void AddPersonalConseq(SPersonalConsequences pc) {
		personalConsequences = pc;
	}
};

class CEvent {
public:
    CEvent() {}
    ~CEvent() {} //todo:
   // CEvent(const CEvent &ev) {cout << "copy worked\n"; /*todo: тут нечисто тоже*/ }

   //	GETTERS
    string GetName() { return name; }
    string GetDescription() { return description; }
    int GetType() { return type; }
    SConsequences* GetSituationPoints() { return &startingSituation; }
    CBackcodeRule* GetBackcodeRule(int id) { return &backcodeRuleList[id]; }
    CBackcodeTriger* GetBackcodeTriger(int id) { return &backcodeTrigerList[id]; }
	int GetBackcodeRuleSize() { return backcodeRuleList.size(); }
    int GetBackcodeTrigerSize() { return backcodeTrigerList.size(); }
    int GetActorsAmmount() { return actorsAmmount; }
	SSlot* GetSlot(int actorId);
	int GetMemberIdBySlotForEventChain(string slotName);
	SPropertyRules* GetPropertyRule() { return &propertyRule; }
	
    //      EVENT CREATING
    void Init(string name,int type,SConsequences sS);
    void AddActorSlot(string slotTypeName,int actorsAmmount,SCondition personCondition,SPersonalConsequences personConseq);
    void AddDescription(string description);
    void AddBackcodeRule(CBackground * backcode, SConsequences rule);
    void AddBackcodeTriger(CBackcodeTriger backcodeTriger);
    void AddPersonData(int rolecode1,int rolecode2,CBackground * backcode);
	void AddPropertyRule(SPropertyRules newRule);
protected:
    string name,description/*optional*/;
    int type,actorsAmmount;
    SConsequences startingSituation;
	
    vector<SSlot> actorSlot;

    vector<CBackcodeRule> backcodeRuleList;
    vector<CBackcodeTriger> backcodeTrigerList;
	SPropertyRules propertyRule;
};

#endif // CEVENT_H_INCLUDED
