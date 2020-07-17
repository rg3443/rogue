#ifndef CBASEMODELOBJECT_H_INCLUDED
#define CBASEMODELOBJECT_H_INCLUDED


#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
//#include <thread>
//#include <mutex>
using namespace std;
#include "../pcgGlobal.h"

class CBaseModelObject {
public:
    CBaseModelObject() {}
    void init();
    
    bool is_exist() { return exist; }
    void set_exist(bool exist) { this->exist = exist; }
protected:
    // is object currectly init and ready to use
    bool exist;
};

#endif // CBASEMODELOBJECT_H_INCLUDED
