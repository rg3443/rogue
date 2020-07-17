#ifndef CINVENTORY_H_INCLUDED
#define CINVENTORY_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <ctime>
using namespace std;

#include "../CBaseModelObject.h"
#include "CBaseItem.h"
/*
enum ESpecial {
	NONE = 0
};
class CBaseArmor; //todo:
struct SWearing {
	CBaseArmor * head,body,hands,legs;
	SWearing() {}
	/*
	SWearing(CBaseModelObject* nhead, CBaseModelObject* nbody, CBaseModelObject* nhands, CBaseModelObject* nlegs) {
		head = nhead;
		body = nbody;
		hands = nhands;
		legs = nlegs;
	}
	*/
	/*
};
*/
/*
struct SMainEquip {
	SWearing armor;
	CBaseWeapon* left_hand,right_hand;
	SMainEquip(){}
	SMainEquip(SWearing wear, CBaseWeapon* lefth,CBaseWeapon* righth) {
		init(wear, lefth,righth);
	}
	void init(SWearing wear, CBaseWeapon* lefth,CBaseWeapon* righth) {
		armor = wear;
		left_hand = lefth;
		right_hand = righth;
	}
};

class CInventory : public CBaseModelObject {
public:
	CInventory() {}
	void init();
	
	void add_item(CBaseItem* item);
	CBaseModelObject* get_item_by_type(int type_id) { }
	CBaseModelObject* get_item_by_name(string name) { }
	int items_size() { return items.size(); }
	void recalculate_veigh();
	float get_left_veigh();
protected:
	SMainEquip equip;
	vector<CBaseItem*> items;
	float max_veigh,current_overall_veigh;
};
*/
#endif
