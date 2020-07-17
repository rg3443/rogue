#include "CPerson.h"

void CPerson::Init(int id,string fname,string sname,int rolecode1,int rolecode2,CBackground * backcode) 
{
        person_id = id;
        first_name = fname;
        second_name = sname;
        person_role_code[0] = rolecode1;
        person_role_code[1] = rolecode2;
        background_code = backcode;

        //todo:
        money = rand() % 500;
        fame = 0;
        influence = 0;
        death = 0;
        wounds = 0;
}

void CPerson::AddProperty(SProperty* new_property)
{
    propertys_owned.push_back(new_property);
}
