#include "CTile.h"

void CTile::init(int ground_type,int object_type)
{
    this->ground_type = ground_type;
    this->object_type = object_type;
    check_object_type();
    check_ground_type();
}

void CTile::check_object_type()
{
    switch(object_type)
    {
    case NOTHING:
        bussed = false;
        can_be_bussed = true;
    break;
    case WALL_SPECIAL:
        bussed = true;
        can_be_bussed = false;
    break;
    }
}

void CTile::check_ground_type()
{
    switch(ground_type)
    {
    case NOTHING:
        bussed = true;
        can_be_bussed = false;
    break;
    }
}
