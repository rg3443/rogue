#include "CInventory.h"
/*
void CInventory::init()
{
	max_veigh = 10.f;
	current_overall_veigh = 0.f;
//	equip.init(SWear(NONE,NONE,NONE,NONE),NONE,NONE);
}

void CInventory::add_item(CBaseItem* item)
{
	float item_veigh = item->get_veigh();
	try {
		if(item_veigh > this->get_left_veigh() )
		{
			throw "ERROR : ITEM VEIGH IS GREATER THAN INVENTORY LEFT VEIGH\n";
		} else {
			items.push_back(item);
			this->recalculate_veigh();
		}
	}
	catch(const char* eror) { printf(eror); }
}

float CInventory::get_left_veigh()
{
	return max_veigh - current_overall_veigh;
}

void CInventory::recalculate_veigh()
{
	float veigh_counter = 0.f;
	for(int item_id=0;item_id<items.size();item_id++)
	{
		veigh_counter += items[item_id]->get_veigh();
	}
	printf("STATUS : RECALC INVENTORY DONE : BEFORE %f, AFTER %f\n",current_overall_veigh,veigh_counter);
	
	current_overall_veigh = veigh_counter;
}
*/
