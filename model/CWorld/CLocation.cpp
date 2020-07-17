#include "CLocation.h"
#include "../../Sup/Logs/cLog.h"

void CLocation::Init(int x_,int y_,int type)
{
    locationSituation.Clear();
	tileField.resize(100);
	x = x_;
	y = y_;
	locationType = type;
	switch(type)
	{
    case WILDS://0
        wildEnemyAmmount = 30;
    break;
    case VILLAGE:
        wildEnemyAmmount = 15;
    break;
    case CITY:
        wildEnemyAmmount = 5;
    break;
	}

    for(int iy=0;iy<tileField.size();iy++)
    {
		tileField[iy].resize(100);
        for(int ix=0;ix<tileField[iy].size();ix++)
        {
            tileField[iy][ix].init(STONE,NOTHING);
        }
    }
    const int PROPERTY_AMMOUNT = 20;
    int startX = 30, startY = 30;
    int propCount=0;
    int propRow=0;
    bool propFillingDone = false;
    for(int id=0;id<PROPERTY_AMMOUNT;id++)
    {
        SProperty newProperty(cords(x,y));
        for(int tileIDY=startY;tileIDY<(startY+10);tileIDY++)
        {
            for(int tileIDX=startX;tileIDX<(startX+10);tileIDX++)
            {
                newProperty.AddTile(cords(tileIDX,tileIDY));
            }
        }
        startX += 10;
        propCount++;
        if(propCount > 4) {
            propCount = 0;
            propRow++;
            startX = 30;
            startY += 20;
        }
        if(propRow > 4) {
            propFillingDone = true;
        }
        avablePropertyList.push_back( newProperty );
        if(propFillingDone) break;
    }

}

void CLocation::AddPerson(CPerson *newPerson)
{
    persona.push_back(newPerson);
    locationSituation.AddPoints(newPerson->GetBackground()->GetSitVeigs());
}

void CLocation::ErasePerson(int personId)
{
    try {
        if(personId > persona.size()) throw "ERROR:(001) PERSON ID IS GREATER THAN LOCATION PERSON SIZE!\n";
        locationSituation.ErasePoints(persona[personId]->GetBackground()->GetSitVeigs());
        persona.erase(persona.begin() + personId);
        cout << "person with id#" << persona[personId]->GetId() << " was erased\n";

    }
    catch(const char* eror) { printf(eror); }
}

void CLocation::RecalculateSituation()
{
    locationSituation.Clear();
    for(int i=0;i<persona.size();i++)
    {
        locationSituation.AddPoints(persona[i]->GetBackground()->GetSitVeigs());
    }
}

void CLocation::ErasePersonByGlobalId(int globalId)
{
   // cout << "LOCATION DATA :" << this->x << "|" << this->y << endl;
   // cout << "PERSON ID LIST :" << endl;
   //cout << "searching id" << globalId << endl;
    for(int lpid=0;lpid<persona.size();lpid++) {
        //todo:kakogoto huya personi imeut nevernie curpos's | chtoto ne tak so strukturoy gde hranyatsja loki
        //cout << "\tperson |lid#" << lpid << "|gid#" << persona[lpid]->GetId() << endl;
        if(persona[lpid]->GetId() == globalId) {
            this->ErasePerson(lpid);
        }
    }
}

void CLocation::ErasePerson(CPerson *personToErase)
{
    for(int lpid=0;lpid<persona.size();lpid++) {
        if(persona[lpid] == personToErase) {
            this->ErasePerson(lpid);
			
            cout << "found persona" << endl;
        } else {
            cout << "person not found" << endl;
        }
    }
}

void CLocation::ErasePerson(string personName)
{

}

#include "Sup/TrueRandom/ctruerandom.h"
SProperty* CLocation::GetRandomFreeProperty()
{
    //making free property list
    vector<SProperty*> freeProperty;
    for(int propid=0;propid<avablePropertyList.size();propid++) {
        if(avablePropertyList[propid].ownerId == -1) {
            freeProperty.push_back(&avablePropertyList[propid]);
        }
    }
    if(freeProperty.size() == 0) {
        return nullptr;
    }
    //choose random from list
    CTrueRand device(0,freeProperty.size());
    return freeProperty[device.rand()];
}


void CLocation::_console_show()
{
    Logys loger;
    loger.open("PopulationInformation.txt",0);

    //printf("X:%d|Y:%d|TYPE:%d\n",x,y,0);
    string stype;
    switch(this->locationType)
    {
    case WILDS:
        stype = "WILDS";
    break;
    case VILLAGE:
        stype = "VILLAGE";
    break;
    case CITY:
        stype = "CITY";
    break;
    }
    string locBaseInfo = "X:" + to_string(x) + "|Y:" + to_string(y) + "|TYPE:" + stype + "|POPULATION:" + to_string(persona.size()) + "\n";
    loger.fast_write(locBaseInfo.c_str());
    for(int perid=0;perid<persona.size();perid++)
    {
        int gPerid = persona[perid]->GetId();
        string sname = persona[perid]->GetSname();
        string fname = persona[perid]->GetFname();
        string background = persona[perid]->GetBackground()->get_name();
        string wholeString1 = "\tLOCAL ID:" + to_string(perid) + "|GLOBAL ID:" + to_string(gPerid);
        string wholeString2 = "\n\t\tFIRST NAME:" + fname + "\n\t\tSECOND NAME:" + sname;
        string wholeString3 = "\n\t\t\tBACKGROUND:" + background + "\n";
        loger.fast_write(wholeString1.c_str());
        loger.fast_write(wholeString2.c_str());
        loger.fast_write(wholeString3.c_str());
        //printf("\tLOCAL ID:%d|GLOBAL ID:%d\n\tFIRST NAME:%s\n\tSECOND NAME:%s\n",perid,gPerid,fname.c_str(),sname.c_str());
    }
    loger.close();
}

void CLocation::_console_show(int countSave)
{
    Logys loger;
    string path = "PopulationInformation" + to_string(countSave) + ".txt";
    loger.open(path.c_str(),0);

    //printf("X:%d|Y:%d|TYPE:%d\n",x,y,0);
    string stype;
    switch(this->locationType)
    {
    case WILDS:
        stype = "WILDS";
    break;
    case VILLAGE:
        stype = "VILLAGE";
    break;
    case CITY:
        stype = "CITY";
    break;
    }
    string locBaseInfo = "X:" + to_string(x) + "|Y:" + to_string(y) + "|TYPE:" + stype + "|POPULATION:" + to_string(persona.size()) + "\n";
    loger.fast_write(locBaseInfo.c_str());
    for(int perid=0;perid<persona.size();perid++)
    {
        int gPerid = persona[perid]->GetId();
        string sname = persona[perid]->GetSname();
        string fname = persona[perid]->GetFname();
        string background = persona[perid]->GetBackground()->get_name();
        string wholeString1 = "\tLOCAL ID:" + to_string(perid) + "|GLOBAL ID:" + to_string(gPerid);
        string wholeString2 = "\n\t\tFIRST NAME:" + fname + "\n\t\tSECOND NAME:" + sname;
        string wholeString3 = "\n\t\t\tBACKGROUND:" + background + "\n";
        loger.fast_write(wholeString1.c_str());
        loger.fast_write(wholeString2.c_str());
        loger.fast_write(wholeString3.c_str());
        //printf("\tLOCAL ID:%d|GLOBAL ID:%d\n\tFIRST NAME:%s\n\tSECOND NAME:%s\n",perid,gPerid,fname.c_str(),sname.c_str());
    }
    loger.close();
}
