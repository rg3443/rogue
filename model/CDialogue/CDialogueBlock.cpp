#include "CDialogueBlock.h"

void CDialogueBlock::Create(int id,string text)
{
    this->id = id;
    npcText = text;
}

void CDialogueBlock::AddAnswer(string text,int blockLead)
{
    answerList.push_back( SAnswerVariant(text,blockLead) );
}

void CDialogueBlock::ChooseAnswer(int id)
{
    try {
        if(id < 0 || id > answerList.size()-1) {
            throw "ERROR:(CDialogueList):answerID IS GREATER THAN ANSWERLIST.SIZE\n";
        } else {
            blockLeadResult = answerList[id].leadsToBlockId;
            passed = true;
        }

    }
    catch(const char* eror) { printf(eror); }
}
