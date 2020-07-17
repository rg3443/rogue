#ifndef CLEVEL_H_INCLUDED
#define CLEVEL_H_INCLUDED

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
//#include <thread>
//#include <mutex>
using namespace std;
#include "../CGlobalModel.h"
#include "../CBaseModelObject.h"
#include "CMap/CMap.h"
#include "../CPlayer/CPlayer.h"
#include "../Creatures/CEnemy/CEnemy.h"
#include "../Creatures/CEnemy/CEnemy_list.h"

#include "../CWorld/GWorld.h"
#include "../CWorld/CWorld.h"
#include "../CWorld/CPerson.h"
#include "../CRuler/CRuler.h"

#include "../Creatures/CPawn.h"


class CLevel : public CBaseModelObject {
public:
    CLevel( ) {}
    CLevel( CLocation * new_current_location,CPlayer * player );
    void Init(CPlayer * player,CLocation * location,int comedir);

    int GetPlayerPawnPosX() { return playerPawn.get_x(); }
    int GetPlayerPawnPosY() { return playerPawn.get_y(); }

    CLocation * GetLocation() { return currentLocation; }




    void __console_tile_ground_show( );
    void __console_tile_object_show( );

    void CreateCreature(CEnemy* enemy_to_copy, cords pos);
   // SCreatures_list* GetCreatureList() { return &creature_list; }


    int GetPersonPawnSize() { return personPawnList.size(); }
    int GetEnemyPawnSize() { return wenemyPawnList.size(); }
    CPersonPawn* GetPersonPawn(int id) { return &personPawnList[id]; }
    CEnemyPawn* GetEnemyPawn(int id) { return &wenemyPawnList[id]; }
protected:
    //CMap map_field;
    vector<CPersonPawn> personPawnList;
    vector<CEnemyPawn> wenemyPawnList;
    CLocation * currentLocation;
    CPlayerPawn playerPawn;
    CPlayer * player;

    CEnemy_list possibeWildEnemyList;
};

#endif // CLEVEL_H_INCLUDED
