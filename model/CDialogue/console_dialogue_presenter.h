#ifndef CONSOLE_DIALOGUE_PRESENTER_H_INCLUDED
#define CONSOLE_DIALOGUE_PRESENTER_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <ctime>
using namespace std;
#include "CDialogue.h"

class CConsoleDialoguePresenter {
public:
    CConsoleDialoguePresenter() {}
    void Init(CDialogue * dialog);
    void Show();
protected:
    CDialogue * dialog;
};

#endif // CONSOLE_DIALOGUE_PRESENTER_H_INCLUDED
