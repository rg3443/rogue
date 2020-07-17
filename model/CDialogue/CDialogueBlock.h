#ifndef CDIALOGUEBLOCK_H_INCLUDED
#define CDIALOGUEBLOCK_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <ctime>
using namespace std;

struct SAnswerVariant {
    string text;
    int leadsToBlockId;
    SAnswerVariant() {}
    SAnswerVariant(string _text,int _id) {
        text = _text;
        leadsToBlockId = _id;
    }
};

class CDialogueBlock {
public:
    CDialogueBlock() { passed = false; }
    void Create(int id,string text);
    void AddAnswer(string text,int blockLead);
    //
    void ChooseAnswer(int id);

    int GetId() { return id; }
    int GetLeadResult() { return blockLeadResult; }
    int GetAnswerSize() { return answerList.size(); }
    bool IsPassed() { return passed; }
    string GetNpcText() { return npcText; }
    SAnswerVariant* GetAnswer(int id) { return &answerList[id]; }

    void SetPassed(bool pass) { passed = pass; }
protected:
    int id,blockLeadResult;
    bool passed;
    string npcText;
    vector<SAnswerVariant> answerList;
};

#endif // CDIALOGUEBLOCK_H_INCLUDED
