#ifndef CEVENTCHAIN_H_INCLUDED
#define CEVENTCHAIN_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <ctime>
using namespace std;

#include "GWorld.h"
#include "CEvent.h"
#include "CPerson.h"
#include "CLocation.h"

class CEventChain {
public:
	CEventChain() {}
	~CEventChain();
    CEventChain(string name,CEvent event,SLocationStatus * localEvent,CLocation * currentLocation) { this->Create(name,event,localEvent,currentLocation); }
	
	//	SETTERS
	
	//GETTERS
	
	//METHODS
    void Create(string name,CEvent event,SLocationStatus * localEvent,CLocation * currentLocation);
	void AddMember(CPerson* newMember);
	void CalculateResults();/*managing persons items*/
	SConsequences* GetExitResult();

	void _console_show();
protected:
	string name;
	vector<CPerson*> memberList;
    CEvent currentEvent; //incoming flash event
	SLocationStatus * currentLocationEvent;//active event
    CLocation* currentLocation;
	SConsequences eventResult;
	int personCounter;
};

#endif
