#ifndef CTURNCHECKER_INCLUDED
#define CTURNCHECKER_INCLUDED

#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
#include "CPersonList.h"
#include "CPerson.h"
#include "CPropertyList.h"
#include "CLocation.h"

class CTurnChecker {
public:
	CTurnChecker() {}
	void Init(CPersonList * personList, CPropertyList * propertyList, SLocationMap locationMap);
	void CheckTurn();
protected:
	CPersonList * personList;
	CPropertyList * propertyList;
	SLocationMap locationMap;
};

#endif
