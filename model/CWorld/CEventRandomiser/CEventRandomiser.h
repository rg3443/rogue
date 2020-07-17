#ifndef CEVENTRANDOMISER_H_INCLUDED
#define CEVENTRANDOMISER_H_INCLUDED


#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <ctime>
using namespace std;

#include "../CEventList.h"
#include "../GWorld.h"
#include "../CBackgroundsList.h"
#include "../CLocation.h"

class CEventRandomiser {
public:
    CEventRandomiser() {}
    CEvent* GetNextEventId(CEventList * eventList,CLocation * location,CBackgroundsList * backList);

protected:

};

#endif // CEVENTRANDOMISER_H_INCLUDED
