#include "CDiplomacy.h"

void CDiplomacy::Init(int clanAmmount)
{
    dyplomacyTable.resize( clanAmmount );
    for(int i=0;i<dyplomacyTable.size();i++)
    {
        dyplomacyTable[i].resize( clanAmmount );
        for(int d=0;d<dyplomacyTable[i].size();d++)
        {
            dyplomacyTable[i][d].Init( NEUTRAL,100 );
        }
    }
}

void CDiplomacy::NewContract( int clanId1,int clanId2,SContract newContract )
{
    try {
        if(clanId1 >= dyplomacyTable.size()) throw "ERROR:(code:1)clan id out of range(vector)";
        if(clanId2 >= dyplomacyTable.size()) throw "ERROR:(code:2)clan id out of range(vector)";
        dyplomacyTable[clanId1][clanId2] = newContract;
        dyplomacyTable[clanId2][clanId1] = newContract;

    }
    catch(const char* error) { printf(error); }
}

SContract CDiplomacy::GetCurrentContract( int clanId1,int clanId2 )
{
    return dyplomacyTable[clanId1][clanId1];
}
