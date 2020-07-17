#include "CPersonList.h"
#include "../../Sup/Logs/cLog.h"
void CPersonList::init(int person_ammount)
{
	random_name_generator.init();
	random_sname_generator.init();
	for(int perid=0;perid<person_ammount;perid++)
	{
        CPerson new_person;

		string person_fname = random_name_generator.get_name();

		string person_sname = random_sname_generator.get_sname();

		int rolecode[2] = { (rand() % 3 + 1000),(rand() % 3 + 1000) };

		//todo: ubrat' eto otsuda, sdelat' vhodnim parametrom, perenesti na hranenie v cworld
        CBackgroundsList backcodeList;
		backcodeList.Init();
		int backcode_id = rand() % backcodeList.size();
        CBackground * background = backcodeList.get_background(backcode_id);

        new_person.Init(perid,person_fname,person_sname,rolecode[0],rolecode[1],background);
		all_persons.push_back(new_person);
/*
		cout << "STATUS: PERSON CREATED!\n";
		cout << "\tFNAME:" << person_fname << endl;
		cout << "\tSNAME:" << person_sname << endl;
		cout << "\tROLECODE:" << rolecode[0] << "|" << rolecode[1] << endl;
		cout << "\tBACKCODE:" << background->get_name() << endl;
		*/
	}
}

//todo:
//doljno poluchat' spisok locaciy i udalat' iz nih trupoff
/*
void CPersonList::CheckAlive(SLocationMap map,SPropertyList * propList)//+CPropertyList propList
{
    for(int pid=0;pid<all_persons.size();pid++)
    {
        if(all_persons[pid].GetWounds() > 4 || all_persons[pid].GetDeath() > 0) {
            dead_persons.push_back(all_persons[pid]);
            //cout << "PERSON DIE! x#" << all_persons[pid].GetCurrLocX() << " y#" << all_persons[pid].GetCurrLocY()<< endl;
            int pposx = all_persons[pid].GetCurrLocX();
            int pposy = all_persons[pid].GetCurrLocY();
            //cout << "PERSON DATA: " << pposx << "|" << pposy << "|tipogid#" << pid << "|realgid" << all_persons[pid].GetId() << endl;
			
			// 1)найти проперти этой персоны 2) передать проперти другой персоне с самым высоким уровнем влияния
			int personId = all_persons[pid].GetId();
            SProperty* property = propList->propList->GetPropertyByOwnerId(personId);
			vector<CPerson*> personList = map.locations[pposy][pposx]->GetAllPersons();
			int highestInf = 0, choosenPersonId;
			for(int perid=0;perid<personList.size();perid++) {
				if(personList[perid]->GetDeath() != 0 && personList[perid]->GetInfluence() > highestInf) {
					choosenPersonId = personList[perid]->GetId();
					highestInf = personList[perid]->GetInfluence();
				}
			}
			property->ownerId = choosenPersonId;
			
            map.locations[pposy][pposx]->ErasePersonByGlobalId(pid);
            //all_persons.erase(all_persons.begin()+pid); //alive list
        } else {
            if(all_persons[pid].GetWounds() != 0)
            all_persons[pid].SetWounds(all_persons[pid].GetWounds()-1);
        }
    }
}
*/

void CPersonList::SaveData(int saveID)
{
    Logys savelog;
    string path = "PersonListSave" + to_string(saveID) + ".txt";
    savelog.open(path.c_str(),0);
    for(int i=0;i<all_persons.size();i++)
    {
        string gid = "#" + to_string(i) + "\n";
        string fname = all_persons[i].GetFname() + "\n";
        string sname = all_persons[i].GetSname() + "\n";
        string rolecode1 = to_string(all_persons[i].GetRolecode(0)) + "\n";
        string rolecode2 = to_string(all_persons[i].GetRolecode(1)) + "\n";
        //int backcode =
        //vector<int> spisoksobstvennosti
        string locX = to_string(all_persons[i].GetCurrLocX()) + "\n";
        string locY = to_string(all_persons[i].GetCurrLocY()) + "\n";

        savelog.fast_write(gid.c_str());
        savelog.fast_write(fname.c_str());
        savelog.fast_write(sname.c_str());
        savelog.fast_write(rolecode1.c_str());
        savelog.fast_write(rolecode2.c_str());
        savelog.fast_write(locX.c_str());
        savelog.fast_write(locY.c_str());

    }
}

CPerson* CPersonList::get_person_by_global_id(int global_id)
{
    for(int i=0;i<all_persons.size();i++) {
       // cout << "sravnim " << all_persons[i].GetId() << " s " << global_id << endl;
        if(all_persons[i].GetId() == global_id)
            return &all_persons[i];
    }
}
