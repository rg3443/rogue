#ifndef CGLOBALMODEL_H_INCLUDED
#define CGLOBALMODEL_H_INCLUDED

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
//#include <thread>
//#include <mutex>
using namespace std;
#include "../pcgGlobal.h"
#include "CBaseModelObject.h"

template<typename T,class C>
struct SPair {
    T obj1;
    C obj2;
    SPair() {}
    SPair(T obj1_, C obj2_) {
        obj1 = obj1_;
        obj2 = obj2_;
    }
    SPair(const SPair<T,C> & copyS) {
        obj1 = copyS.obj1;
        obj2 = copyS.obj2;
    }
};

enum ESpecialType {
    NOTHING = 0,
    DEFFAULT = 1,
    IN_INVENTORY = 2
};

enum EGroundTypes {
    EARTH = 10,
    STONE = 11,
    WOOD = 12
};

enum EObjectTypes {
    WALL_SPECIAL = 20,
    CREATURE_SPECIAL = 21,
    PLAYER_SPECIAL = 22,
    ITEM_SPECIAL = 23
};

enum ENPCStatus {
    AGGRESIVE = 100,
    NEUTRAL = 101,
    FRIENDLY = 102
};

enum EEnemyTypes {
    FORESTWOLF = 31
};

enum EButtonCodes {
    PAUSE,
    GAMEPLAY,
    MAINMENU,
    AMOVEDOWN,
    AMOVEUP,
    AMOVELEFT,
    AMOVERIGHT,
    AEXIT,
    //
    INVETORY,
    WORLD,
    HEALWOUNDS
};


struct SCurrentPlayData {
	cords currentLocationPos;
	bool quit;
	void SetCurrentLocationPos(int locIdX, int locidY) {
		currentLocationPos.x = locIdX;
		currentLocationPos.y = locidY;
	}
	int GetCurrentLocationX() { return currentLocationPos.x; }
	int GetCurrentLocationY() { return currentLocationPos.y; }

	void TravelNorth() { currentLocationPos.y--; }
	void TravelEast() { currentLocationPos.x++; }
	void TravelWest() { currentLocationPos.x--; }
	void TravelSouth() { currentLocationPos.y++; }
};

class CBaseInGameObject : public CBaseModelObject {
public:
    CBaseInGameObject() {}

    void set_coordiantes_on_current_level(cords new_pos) { coordinates_on_current_level = new_pos; }
    int get_x() { return coordinates_on_current_level.x; }
    int get_y() { return coordinates_on_current_level.y; }
    cords get_full_cords() { return coordinates_on_current_level; }


    void set_global_id(int id) { global_id = id; }
    int get_global_id() { return global_id; }
protected:
    cords coordinates_on_current_level;
    long int global_id;
};

#endif // CGLOBALMODEL_H_INCLUDED
