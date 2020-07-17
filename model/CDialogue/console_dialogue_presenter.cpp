#include "console_dialogue_presenter.h"
#include "CDialogueBlock.h"

void CConsoleDialoguePresenter::Init(CDialogue * dialog)
{
    this->dialog = dialog;
}

void CConsoleDialoguePresenter::Show()
{
    dialog->Start();
    while(!dialog->IsDone())
    {
            CDialogueBlock * currentBlock = dialog->GetBlock(dialog->GetCurrentBlockID());
            string npcText = currentBlock->GetNpcText();
            cout << npcText << endl;
            vector<string> answerText(currentBlock->GetAnswerSize());
            for(int answerID=0;answerID<currentBlock->GetAnswerSize();answerID++)
            {
                answerText[answerID] = currentBlock->GetAnswer(answerID)->text;
                cout << answerText[answerID] << endl;
            }
            int choosenAnswer;
            cin >> choosenAnswer;
            dialog->AddAnswerToCurrentBlock(choosenAnswer);
    }
}
