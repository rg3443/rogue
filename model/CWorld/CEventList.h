#ifndef CEVENTLIST_H_INCLUDED
#define CEVENTLIST_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <ctime>
using namespace std;

#include "CEvent.h"
#include "CBackgroundsList.h"

class CEventList {
public:
    CEventList() {}
    void Init(CBackgroundsList* backcodeList);
	
	//	GETTERS
	CEvent* GetEvent(int typeID,int id);
    CEvent* GetRandomEventByType(int type);
    CEvent* GetEvent(corda pairID);
    int GetTypeSize(int type);
	int GetTypesSize() { return eventList.size(); }
	//	SETTERS

	//	METHODS
    void AddEvent(string name,int type,SConsequences cons);
    void AddBackcodeTriger(string eventName,CBackcodeTriger triger);
    void AddActorsSlot(string eventName,string slotName,int slotSize,SCondition condit,SPersonalConsequences personConceq);
    void AddPropertyRule(string eventName,SPropertyRules newRule);
protected:
    int EVENT_TYPE_AMMOUNT;
    vector<vector<CEvent>> eventList;
    CBackgroundsList* backcodeList;
};

#endif // CEVENTLIST_H_INCLUDED
