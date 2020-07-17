#ifndef GWORLD_H_INCLUDED
#define GWORLD_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <ctime>
using namespace std;

#include "../../pcgGlobal.h"

const int AMMOUNT_EVENTS_PER_TURN = 3;

struct corda {
    int x,y;
    corda() {}
    corda(int nx,int ny) {
        x = nx;
        y = ny;
    }
};

struct SBasicPersonData {
	int person_id;
	string first_name,second_name;
};

struct STituls {
	SBasicPersonData leader,righthand,pretender;
	void add_leader(SBasicPersonData lead) { leader = lead; }
	void add_righthand(SBasicPersonData rhand) { righthand = rhand; }
	void add_pretender(SBasicPersonData pret) { pretender = pret; }
};

struct SPolitics {
	vector<int> enemy_list;
	vector<int> ally_list;
	vector<int> vassal_list;
	void add_ally(int id)
	{
		ally_list.push_back(id);
	}
	void add_enemy(int id)
	{
		enemy_list.push_back(id);
    }
	void add_vassal(int id)
	{
		vassal_list.push_back(id);
	}
};

struct SProperty {
	int id,ownerId;
	cords location_pos;
	vector<cords> tiles_in_property;
	SProperty() {}
	SProperty(cords locaPos) {
        location_pos = locaPos;
	}
	void AddTile(cords tilePos) {
        tiles_in_property.push_back( tilePos );
	}
	cords GetLeftUpperTileCords() { 
		//tilewith lowest y and lowest x
		int currentTile = -1, currentLowestX = -1, currentHighestY = -1;
		for(int id=0;id<tiles_in_property.size();id++) {
			if(id == 0) {
				currentLowestX = tiles_in_property[id].x;
				currentHighestY = tiles_in_property[id].y;
				currentTile = id;
			} else {
				if(tiles_in_property[id].x < currentLowestX && tiles_in_property[id].y < currentHighestY) {
					currentLowestX = tiles_in_property[id].x;
					currentHighestY = tiles_in_property[id].y;
					currentTile = id;
				}
			} 
		}
		return cords(currentLowestX,currentHighestY);
	}
	cords GetRightDownTileCords() { 
		//tilewith highest y and highest x
		int currentTile = -1, currentHighestX = -1, currentLowestY = -1;
		for(int id=0;id<tiles_in_property.size();id++) {
			if(id == 0) {
				currentHighestX = tiles_in_property[id].x;
				currentLowestY = tiles_in_property[id].y;
				currentTile = id;
			} else {
				if(tiles_in_property[id].x > currentHighestX && tiles_in_property[id].y > currentLowestY) {
					currentHighestX = tiles_in_property[id].x;
					currentLowestY = tiles_in_property[id].y;
					currentTile = id;
				}
			} 
		}
		return cords(currentHighestX,currentLowestY);
	}
};

struct SLocalDisaster {
	float starvingChance,massiveStealChance,massiveFireChance;
	SLocalDisaster() {}
	SLocalDisaster(float starving,float stealing,float firing) {
		starvingChance = starving;
		massiveStealChance = stealing;
		massiveFireChance = firing;
	}
};

struct SLocationStatus {
	// chances of calling locationevent in next generate
	SLocalDisaster chances;
	bool starvingEvent,massiveStealEvent,massiveFireEvent;
	void addVeighs(SLocalDisaster veigs) {

	}
};

struct SPersonalConsequences {
	pair<float,int>	woundsChance, /*шанс в %, количество*/
					deathChance,
					profitChance,
					fameChance,
					influenceChance;
	SPersonalConsequences() {}
	SPersonalConsequences(pair<float,int> wc,pair<float,int> dc,pair<float,int> pc,pair<float,int> fc,pair<float,int> ic) {
		woundsChance = wc;
		deathChance = dc;
		profitChance = pc;
		fameChance = fc;
		influenceChance = ic;
	}
	void Clear() {
		//todo:
	}
	void AddPoints(pair<float,int> wc,pair<float,int> dc,pair<float,int> pc,pair<float,int> fc,pair<float,int> ic) {
		woundsChance.first += wc.first;
		deathChance.first += dc.first;
		profitChance.first += pc.first;
		fameChance.first += fc.first;
		influenceChance.first += ic.first;
		woundsChance.second += wc.second;
		deathChance.second += dc.second;
		profitChance.second += pc.second;
		fameChance.second += fc.second;
		influenceChance.second += ic.second;
	}
	void ErasePoints() {
		
	}
};

struct SConsequences {								//	привлекает:
    float   peaceMeetChance/*мирное*/, 		//	рабочих и знать
            threatChance/*враждебное*/, 			//	законников
            dealChance,/*деловое*/		   			//	рабочих и криминалов
            negotiationChance/*конфликтное*/, //   криминалов и знать
            incidentChance;/*независищее от человека?*/
    SConsequences() {}
    SConsequences(float ap, float cp, float np,float pp,float ip) {
        this->Clear();
        this->AddPoints(ap,cp,np,pp,ip);
    }
    void Clear() {
        peaceMeetChance = 0;
        threatChance = 0;
        dealChance = 0;
        negotiationChance = 0;
        incidentChance = 0;
    }
    void AddPoints(float ap,float cp,float np,float pp,float ip) {
        peaceMeetChance += ap;
        threatChance += cp;
        dealChance += np;
        negotiationChance += pp;
        incidentChance = ip;
    }
    void AddPoints(SConsequences obj2) {
        peaceMeetChance += obj2.peaceMeetChance;
        threatChance += obj2.threatChance;
        dealChance += obj2.dealChance;
        negotiationChance += obj2.negotiationChance;
        incidentChance += obj2.incidentChance;
    }
	void ErasePoints(SConsequences obj2) {
        peaceMeetChance -= obj2.peaceMeetChance;
        threatChance -= obj2.threatChance;
        dealChance -= obj2.dealChance;
        negotiationChance -= obj2.negotiationChance;
        incidentChance -= obj2.incidentChance;
	}
    SConsequences operator+(SConsequences obj2) {
        this->peaceMeetChance = obj2.peaceMeetChance;
        this->threatChance = obj2.threatChance;
        this->dealChance = obj2.dealChance;
        this->negotiationChance = obj2.negotiationChance;
        this->incidentChance = obj2.incidentChance;
    }
    int Accume() {
        return peaceMeetChance + threatChance + dealChance + negotiationChance + incidentChance;
    }
};

struct SBackgroundVeigs {
    int peaceMeet,threat,deal,negotiation,incident;
    SBackgroundVeigs() {}
    SBackgroundVeigs(int pm,int th,int dl, int ng, int inc) {
        peaceMeet = pm;
        threat = th;
        deal = dl;
        negotiation = ng;
        incident = inc;
    }
    void Clear() {
        peaceMeet = 0;
        threat = 0;
        deal = 0;
        negotiation = 0;
        incident = 0;
    }
    SBackgroundVeigs operator+(SBackgroundVeigs obj2) {
        this->peaceMeet = obj2.peaceMeet;
        this->deal = obj2.deal;
        this->negotiation = obj2.negotiation;
        this->incident = obj2.incident;
    }
};

inline int getProc(int val,int wholeVal)
{
    float buf = to_float(val) / (to_float(wholeVal) / 100.f);
    int rez = to_int(buf);
    //cout << "GETPROC REZULT: " << rez << endl;
    return rez;
}

inline vector<int> getProc(SConsequences baseVeigs)
{
    vector<int>proc(5);
     proc[0] = getProc(baseVeigs.peaceMeetChance,baseVeigs.Accume());
     proc[1] = getProc(baseVeigs.threatChance,baseVeigs.Accume());
     proc[2] = getProc(baseVeigs.dealChance,baseVeigs.Accume());
     proc[3] = getProc(baseVeigs.negotiationChance,baseVeigs.Accume());
     proc[4] = getProc(baseVeigs.incidentChance,baseVeigs.Accume());
     return proc;
}


#endif
