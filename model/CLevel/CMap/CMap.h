#ifndef CMAP_H_INCLUDED
#define CMAP_H_INCLUDED

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
//#include <thread>
//#include <mutex>
using namespace std;
#include "../../CGlobalModel.h"
#include "../../CBaseModelObject.h"
#include "CTile.h"
#include "../../CWorld/CLocation.h"

class CMap : public CBaseModelObject {
public:
    CMap() {}
    void init(int leveltype_id, int w, int h);
    void gener_tiles();
	void fill_with_location(CLocation * location);
    void set_tile(int x, int y,int grtype,int obtype,bool passable,bool bussy);

    int w_size() { return tile_field[0].size(); }
    int h_size() { return tile_field.size(); }
    CTile* get_tile(int x,int y) { return tile_field[y][x]; }
protected:
    int level_type;
    vector< vector<CTile*> > tile_field;

};

#endif // CMAP_H_INCLUDED
