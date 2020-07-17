#include "CDialogueList.h"

void CDialogueList::Init()
{
    const int DIALOG_SIZE = 1;
    dialogueList.resize( DIALOG_SIZE );
    dialogueList[0].Create(0);
    dialogueList[0].AddBlock( 0,"have a nicesex,ok?" );
        dialogueList[0].AddAnswerToBlock( 0,"ok",1 );
    dialogueList[0].AddBlock( 1,"ok is ok, dont worry" );
        dialogueList[0].AddAnswerToBlock( 1,"*cool bit*",2 );
    dialogueList[0].AddBlock( 2,"test in progress" );
        dialogueList[0].AddAnswerToBlock( 2,"hmmmmm",END_OF_DIALOGUE );
        dialogueList[0].AddAnswerToBlock( 2,"hmmmmm2",END_OF_DIALOGUE );

}
