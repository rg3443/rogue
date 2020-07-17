#ifndef CDIALOGUELIST_H_INCLUDED
#define CDIALOGUELIST_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <ctime>
using namespace std;
#include "CDialogue.h"

class CDialogueList {
public:
    CDialogueList() {}
    void Init();

    CDialogue* GetDialogue(int id) { return &dialogueList[id]; }
protected:
    vector<CDialogue> dialogueList;
};

#endif // CDIALOGUELIST_H_INCLUDED
