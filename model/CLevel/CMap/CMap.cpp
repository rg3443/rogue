#include "CMap.h"

void CMap::init(int leveltype_id,int w, int h)
{
    level_type = leveltype_id;
    tile_field.resize(h);
    for(int i=0;i<tile_field.size();i++)
    {
        tile_field[i].resize(w);
    }
    gener_tiles();
}

void CMap::gener_tiles()
{
    for(int iy=0;iy<tile_field.size();iy++)
    {
        for(int ix=0;ix<tile_field[iy].size();ix++)
        {
            tile_field[iy][ix]->init(STONE,NOTHING);
        }
    }
}

void CMap::fill_with_location(CLocation * location)
{
    for(int iy=0;iy<tile_field.size();iy++)
    {
        for(int ix=0;ix<tile_field[iy].size();ix++)
        {
			CTile * tile = location->GetTile(ix,iy);
            tile_field[iy][ix] = tile;
        }
    }
}

void CMap::set_tile(int x,int y,int grtype, int obtype,bool passable, bool bussy)
{
    tile_field[y][x]->set_ground_type(grtype);
    tile_field[y][x]->set_object_type(obtype);
    tile_field[y][x]->set_can_be_bussed(passable);
    tile_field[y][x]->set_bussed(bussy);
}
