#ifndef CDIPLOMACY_H_INCLUDED
#define CDIPLOMACY_H_INCLUDED

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
//#include <thread>
//#include <mutex>
using namespace std;

enum EContractTypes {
    NEUTRAL,
    ALLY,
    WAR,
    NONATTACKPACT
};

struct SContract {
    int type,dayLong;
    SContract() {}
    SContract(int _type,int _dayLong) {
        this->Init(_type,_dayLong);
    }
    void Init(int _type,int _dayLong) {
        type = _type;
        dayLong = _dayLong;

    }
};

class CDiplomacy {
public:
    CDiplomacy() {}
    void Init( int clanAmmount );
    void NewContract( int clanId1,int clanId2,SContract contract );
    SContract GetCurrentContract( int clanId1,int clanId2 );


protected:
    vector< vector<SContract> > dyplomacyTable;
};

#endif // CDIPLOMACY_H_INCLUDED
