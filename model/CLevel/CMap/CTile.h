#ifndef CTILE_H_INCLUDED
#define CTILE_H_INCLUDED

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

class CTile : public CBaseModelObject {
public:
    CTile() {}
    void init(int ground_type,int object_type);
    void check_object_type();
    void check_ground_type();

    void set_ground_type(int ground_type) { this->ground_type = ground_type; }
    void set_object_type(int object_type) { this->object_type = object_type; }
    void set_bussed(bool bussed) { this->bussed = bussed; }
    void set_can_be_bussed(bool can_be_bussed) { this->can_be_bussed = can_be_bussed; }
    int get_ground_type() { return ground_type; }
    int get_object_type() { return object_type; }
    bool is_bussed() { return bussed; }
    bool is_can_be_bussed() { return can_be_bussed; }
protected:
    int ground_type,object_type;
    bool bussed, can_be_bussed; // ..by creature
};

#endif // CTILE_H_INCLUDED
