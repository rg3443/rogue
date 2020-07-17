#ifndef CPROPERTYLIST_H
#define CPROPERTYLIST_H

#include <iostream>
#include <stdio.h>
#include "GWorld.h"
#include <vector>
#include "CPersonList.h"
#include "CLocation.h"

using namespace std;

class CPropertyList {
public:
    CPropertyList();
    void Init(CPersonList * prsLst,SLocationMap locMap);

    void AddProperty(SProperty* newProp);
    SProperty* GetProperty(int globalId);
	SProperty* GetPropertyByOwnerId(int personOwnerId);
    int GetSize() { return propertyList.size(); }
    //void CheckOwners();
private:
    vector<SProperty*> propertyList;
    int idCounter;
    CPersonList * personList;
    SLocationMap locationMap;
};

struct SPropertyList {
    CPropertyList * propList;
    SPropertyList() {}
    SPropertyList(CPropertyList * pList) {
        propList = pList;
    }
};

#endif // CPROPERTYLIST_H
