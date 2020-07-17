#ifndef CDIALOGUE_H_INCLUDED
#define CDIALOGUE_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <ctime>
using namespace std;
#include "CDialogueBlock.h"

enum ESpecialDialogueCode {
    END_OF_DIALOGUE = -1
};

class CDialogue {
public:
    CDialogue() {}
    void Create(int id) { this->id = id; }
    void AddBlock(int id,string npcText);
    void AddAnswerToBlock(int blockID,string answerText,int leadToBlockID);


    int GetCurrentBlockID() { return currentBlock; }
    int GetId() { return id; }
    bool IsDone() { return done; }
    CDialogueBlock* GetBlock(int id) { return &blockList[id]; }
    int GetBlockSize() { return blockList.size(); }

    //ingame manipulations
    void Start();
    void AddAnswerToCurrentBlock(int answerID);
protected:
    int id,currentBlock;
    bool done;
    vector<CDialogueBlock> blockList;
};

#endif // CDIALOGUE_H_INCLUDED
