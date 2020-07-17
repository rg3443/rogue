#include "CDialogue.h"

void CDialogue::AddBlock(int id,string npcText)
{
    CDialogueBlock buf;
    buf.Create(id,npcText);
    blockList.push_back( buf );
}

void CDialogue::AddAnswerToBlock(int blockID,string answerText,int leadToBlockID)
{
    blockList[blockID].AddAnswer( answerText,leadToBlockID );
}

void CDialogue::Start()
{
    currentBlock = 0;
    done = false;
}

void CDialogue::AddAnswerToCurrentBlock(int answerID)
{
    blockList[currentBlock].ChooseAnswer(answerID);
    if(!done)
    if(blockList[currentBlock].IsPassed()) {
        currentBlock++;
        if(currentBlock == blockList.size()) {
            done = true;
        }
    }
}

