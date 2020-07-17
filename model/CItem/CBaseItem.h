#ifndef CBASEITEM_H_INCLUDED
#define CBASEITEM_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <ctime>
using namespace std;

#include "../CGlobalModel.h"

class CBaseItem : public CBaseInGameObject {
public:
	CBaseItem() {}
	
	void set_cost(int cost) { this->cost = cost; }
	void set_usable(bool usable) { this->usable = usable; }
	void set_veigh(float veigh) { this->veigh = veigh; }
	int get_cost() { return cost; }
	bool is_usable() { return usable; } 
    float get_veigh() { return veigh; } 
protected:
	int cost;
	bool usable;
	float veigh;
};

#endif
