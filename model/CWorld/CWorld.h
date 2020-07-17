#ifndef CWORLD_H_INCLUDED
#define CWORLD_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <ctime>
using namespace std;

#include "CLocation.h"
#include "CPerson.h"
#include "CClan.h"
#include "CClanList.h"
#include "CPersonList.h"
#include "GWorld.h"
#include "CEventList.h"
#include "CPropertyList.h"
#include "CEventRandomiser/CEventRandomiser.h"
#include "CEventChain.h"
#include "CTurnChecker.h"
#include "Sup/PSQL/cpsqldatabase.h"

class CWorld {
public:
    CWorld() { savesCounter = 0; }
	void Init();
    void _MadeTurn(int turnVal);

	void _CheckLocationTypes();
	void __SaveWorldInfo();

    SLocationMap GetLocMap();

    //  db tables handling
    void _firstCreateTables();
    void _rebuildDbTables();
    void _addLocationData(int turn,cords locationPos,int personAmmount,SConsequences * currentConseq);
    void _dropLocationData();
    void _addEventData(int turn,cords pos, string name);
    void _dropEventData();
    void _addPropertyData(int turn,int id,int globalPosX, int globalPosY, cords leftUperTile,cords rightDownTile,int personOwnerId/*, int type*/); //todo:
    void _rebuildPropertyData(int turnVal);
    void _dropPropertyData();
protected:
    vector< vector<CLocation> > locations;
	CPersonList personList;
	CClanList clanList;
	CBackgroundsList backgroundList;
	CEventList eventList;
    CPropertyList propertyList;
    CEventRandomiser eventRandomiser;
	CTurnChecker turnChecker;

    CPSQLDatabase connTool;
    int savesCounter;
};

#endif
