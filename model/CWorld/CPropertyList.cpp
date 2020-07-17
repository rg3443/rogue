#include "cpropertylist.h"

CPropertyList::CPropertyList()
{
    idCounter = 0;
}

void CPropertyList::Init(CPersonList *prsLst,SLocationMap locMap)
{
    personList = prsLst;
    locationMap = locMap;
}


void CPropertyList::AddProperty(SProperty *newProp)
{
    newProp->id = idCounter;
    newProp->ownerId = -1;
    propertyList.push_back(newProp);
    idCounter++;
}

SProperty* CPropertyList::GetProperty(int globalId)
{
    for(int gid=0;gid<propertyList.size();gid++) {
        if(propertyList[gid]->id == globalId) return propertyList[gid];
    }
}

SProperty* CPropertyList::GetPropertyByOwnerId(int personOwnerId)
{
	try {
		for(int i=0;i<propertyList.size();i++) {
			if(propertyList[i]->ownerId = personOwnerId) return propertyList[i];
		}
		throw -1;
	}
	catch(int) {
		return nullptr;
	}
}

