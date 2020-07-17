#include "CEventList.h"
#include "windows.h"

void CEventList::Init(CBackgroundsList* backcodeList)
{
    this->backcodeList = backcodeList;
    //EVENT_AMMOUNT = 6;
    EVENT_TYPE_AMMOUNT = 6;
    eventList.resize(EVENT_TYPE_AMMOUNT);
    cout << "here1\n";
    this->AddEvent("Road crash",INCIDENT,SConsequences( 15,5,0,30,0 ));
	cout << "here2\n";
        this->AddBackcodeTriger("Road crash",CBackcodeTriger(backcodeList->get_background("Assassin"),10));
        this->AddActorsSlot("Road crash","Traveler",3,SCondition(-99,-99,-99,-99),
			SPersonalConsequences(pair<float,int>(35,2),pair<float,int>(10,1),pair<float,int>(0,0),pair<float,int>(0,0),pair<float,int>(0,0)));
        this->AddActorsSlot("Road crash","Assasin",1,SCondition(-99,-99,-99,-99),
			SPersonalConsequences(pair<float,int>(0,0),pair<float,int>(0,0),pair<float,int>(100,1000),pair<float,int>(50,20),pair<float,int>(0,0)));

    this->AddEvent("Road thugs attack",THREAT,SConsequences( 35,10,10,0,0 ));
        this->AddBackcodeTriger("Road thugs attack",CBackcodeTriger(backcodeList->get_background("Graverobber"),10));
        this->AddActorsSlot("Road thugs attack","Thug",2,SCondition(-99,-99,-99,-99),
			SPersonalConsequences(pair<float,int>(50,2),pair<float,int>(25,1),pair<float,int>(50,200),pair<float,int>(15,5),pair<float,int>(5,5)));
        this->AddActorsSlot("Road thugs attack","Deffender",2,SCondition(-99,-99,100,-99),
			SPersonalConsequences(pair<float,int>(50,2),pair<float,int>(25,1),pair<float,int>(50,-200),pair<float,int>(0,0),pair<float,int>(0,0)));

    this->AddEvent("Big Man is coming",NEGOTIATION,SConsequences( -10,-20,30,-15,0 ));
        this->AddBackcodeTriger("Big Man is coming",CBackcodeTriger(backcodeList->get_background("Adventurous Noble"),10));
        this->AddActorsSlot("Big Man is coming","Bigman",1,SCondition(-99,-99,350,-99),
			SPersonalConsequences(pair<float,int>(0,0),pair<float,int>(0,0),pair<float,int>(100,-350),pair<float,int>(100,30),pair<float,int>(50,30)));
        this->AddActorsSlot("Big Man is coming","Security",2,SCondition(-99,-99,-99,-99),
			SPersonalConsequences(pair<float,int>(10,1),pair<float,int>(5,1),pair<float,int>(100,150),pair<float,int>(0,0),pair<float,int>(0,0)));
        this->AddActorsSlot("Big Man is coming","Peasant",8,SCondition(-99,-99,-99,-99),
			SPersonalConsequences(pair<float,int>(0,0),pair<float,int>(0,0),pair<float,int>(15,25),pair<float,int>(10,10),pair<float,int>(0,0)));

    this->AddEvent("Prominent priest is coming",NEGOTIATION,SConsequences( -15,0,20,-5,0 ));
        this->AddBackcodeTriger("Prominent priest is coming",CBackcodeTriger(backcodeList->get_background("Monk"),10));
        this->AddActorsSlot("Prominent priest is coming","Prominent priest",1,SCondition(10,-99,-99,-99),
			SPersonalConsequences(pair<float,int>(0,0),pair<float,int>(0,0),pair<float,int>(100,100),pair<float,int>(30,10),pair<float,int>(70,20)));
        this->AddActorsSlot("Prominent priest is coming","Meeter",6,SCondition(-99,-99,-99,-99),
			SPersonalConsequences(pair<float,int>(0,0),pair<float,int>(0,0),pair<float,int>(100,-15),pair<float,int>(5,5),pair<float,int>(0,0)));

    this->AddEvent("A traveling merchant",DEAL,SConsequences( 5,-5,0,-15,0 ));
        this->AddBackcodeTriger("A traveling merchant",CBackcodeTriger(backcodeList->get_background("Trader"),10));
        this->AddActorsSlot("A traveling merchant","Merchant",1,SCondition(-99,-99,-99,-99),
			SPersonalConsequences(pair<float,int>(5,2),pair<float,int>(5,1),pair<float,int>(50,150),pair<float,int>(0,0),pair<float,int>(0,0)));
        this->AddActorsSlot("A traveling merchant","Caravan Hand",1,SCondition(-99,-99,-99,-99),
			SPersonalConsequences(pair<float,int>(15,2),pair<float,int>(10,1),pair<float,int>(50,50),pair<float,int>(0,0),pair<float,int>(0,0)));
        this->AddActorsSlot("A traveling merchant","Buyer",2,SCondition(-99,-99,50,-99),
			SPersonalConsequences(pair<float,int>(15,2),pair<float,int>(10,1),pair<float,int>(50,-100),pair<float,int>(0,0),pair<float,int>(0,0)));

    this->AddEvent("Feasting in Tavern",PEACEFULL_MEETING,SConsequences( 10,-15,0,10,0 ));
       this->AddBackcodeTriger("Feasting in Tavern",CBackcodeTriger(backcodeList->get_background("Farmhand"),10));
        this->AddActorsSlot("Feasting in Tavern","Traveler",5,SCondition(-99,-99,-15,-99),
			SPersonalConsequences(pair<float,int>(35,1),pair<float,int>(5,1),pair<float,int>(85,-15),pair<float,int>(15,5),pair<float,int>(0,0)));
		
	this->AddEvent("Village brawling",PEACEFULL_MEETING,SConsequences(-10,0,5,5,0));
       this->AddBackcodeTriger("Village brawling",CBackcodeTriger(backcodeList->get_background("Brawler"),10));
        this->AddActorsSlot("Village brawling","Competor",2,SCondition(-99,-99,-99,-99),
			SPersonalConsequences(pair<float,int>(50,1),pair<float,int>(5,1),pair<float,int>(100,50),pair<float,int>(50,10),pair<float,int>(0,0)));
        this->AddActorsSlot("Village brawling","Spectator",6,SCondition(-99,-99,10,-99),
			SPersonalConsequences(pair<float,int>(0,0),pair<float,int>(0,0),pair<float,int>(100,-10),pair<float,int>(0,0),pair<float,int>(0,0)));
		
	this->AddEvent("Great fair",PEACEFULL_MEETING,SConsequences(10,-10,20,10,5));
       this->AddBackcodeTriger("Great fair",CBackcodeTriger(backcodeList->get_background("Vagabond"),10));
        this->AddActorsSlot("Great fair","Trader",4,SCondition(-99,-99,-99,-99),
			SPersonalConsequences(pair<float,int>(0,0),pair<float,int>(0,0),pair<float,int>(25,100),pair<float,int>(0,0),pair<float,int>(0,0)));
        this->AddActorsSlot("Great fair","Buyer",10,SCondition(-99,-99,25,-99),
			SPersonalConsequences(pair<float,int>(0,0),pair<float,int>(0,0),pair<float,int>(50,-25),pair<float,int>(0,0),pair<float,int>(0,0)));
        this->AddActorsSlot("Great fair","Watchman",2,SCondition(-99,-99,-99,-99),
			SPersonalConsequences(pair<float,int>(10,1),pair<float,int>(0,0),pair<float,int>(100,20),pair<float,int>(0,0),pair<float,int>(0,0)));

    this->AddEvent("Barbarian pray",PEACEFULL_MEETING,SConsequences(-10,10,0,20,-20));
        this->AddBackcodeTriger("Barbarian pray",CBackcodeTriger(backcodeList->get_background("Barbarian"),10));
        this->AddBackcodeTriger("Barbarian pray",CBackcodeTriger(backcodeList->get_background("Cultist"),10));
        this->AddActorsSlot("Barbarian pray","Prayer",2,SCondition(-99,-99,-99,-99),
            SPersonalConsequences(pair<float,int>(15,1),pair<float,int>(0,0),pair<float,int>(0,0),pair<float,int>(70,10),pair<float,int>(15,15)));

    this->AddEvent("Execution",THREAT,SConsequences(0,30,-10,-10,-5));
        this->AddBackcodeTriger("Execution",CBackcodeTriger(backcodeList->get_background("Legalist"),10));
        this->AddBackcodeTriger("Execution",CBackcodeTriger(backcodeList->get_background("Killer on the run"),10));
        this->AddActorsSlot("Execution","Executioner",1,SCondition(-99,-99,-99,-99),
            SPersonalConsequences(pair<float,int>(0,0),pair<float,int>(0,0),pair<float,int>(100,50),pair<float,int>(70,10),pair<float,int>(0,0)));
        this->AddActorsSlot("Execution","Judjer",1,SCondition(-99,10,-99,-99),
            SPersonalConsequences(pair<float,int>(5,1),pair<float,int>(0,0),pair<float,int>(100,-50),pair<float,int>(50,5),pair<float,int>(80,5)));
        this->AddActorsSlot("Execution","Convicted",1,SCondition(-99,-99,-99,-99),
            SPersonalConsequences(pair<float,int>(0,0),pair<float,int>(99,1),pair<float,int>(0,0),pair<float,int>(100,200),pair<float,int>(0,0)));
        this->AddActorsSlot("Execution","Spectator",6,SCondition(-99,-99,-99,-99),
            SPersonalConsequences(pair<float,int>(5,1),pair<float,int>(0,0),pair<float,int>(0,0),pair<float,int>(0,0),pair<float,int>(0,0)));

    this->AddEvent("Duel",THREAT,SConsequences(0,-30,0,-30,0));
        this->AddBackcodeTriger("Duel",CBackcodeTriger(backcodeList->get_background("Adventurous Noble"),10));
        this->AddActorsSlot("Duel","Duelist",2,SCondition(-99,-99,-99,-99),
            SPersonalConsequences(pair<float,int>(70,1),pair<float,int>(30,1),pair<float,int>(0,0),pair<float,int>(50,20),pair<float,int>(5,5)));
			
	this->AddEvent("Famouse man makes speach",PEACEFULL_MEETING,SConsequences(0,15,15,15,0));
        this->AddBackcodeTriger("Famouse man makes speach",CBackcodeTriger(backcodeList->get_background("Adventurous Noble"),10));
        //this->AddBackcodeTriger("Famouse man makes speach",CBackcodeTriger(backcodeList->get_background("Legalist"),10));
        //this->AddBackcodeTriger("Famouse man makes speach",CBackcodeTriger(backcodeList->get_background("Trader"),10));
        this->AddActorsSlot("Famouse man makes speach","Duelist",2,SCondition(-99,-99,-99,-99),
            SPersonalConsequences(pair<float,int>(0,0),pair<float,int>(0,0),pair<float,int>(0,0),pair<float,int>(50,25),pair<float,int>(70,10)));
			
	this->AddEvent("Village dancing battle",PEACEFULL_MEETING,SConsequences(20,-20,0,-5,5));
        this->AddBackcodeTriger("Stealing money",CBackcodeTriger(backcodeList->get_background("Minstrel"),10));
        this->AddActorsSlot("Village dancing battle","Bard",1,SCondition(-99,-99,-99,-99),
            SPersonalConsequences(pair<float,int>(0,0),pair<float,int>(0,0),pair<float,int>(80,50),pair<float,int>(50,25),pair<float,int>(0,0)));
        this->AddActorsSlot("Village dancing battle","Dancer",6,SCondition(-99,-99,-99,-99),
            SPersonalConsequences(pair<float,int>(10,1),pair<float,int>(0,0),pair<float,int>(15,50),pair<float,int>(15,10),pair<float,int>(0,0)));
			
	this->AddEvent("Stealing money",THREAT,SConsequences(0,0,-10,15,0));
        this->AddBackcodeTriger("Stealing money",CBackcodeTriger(backcodeList->get_background("Thief"),10));
        this->AddActorsSlot("Stealing money","Thief",1,SCondition(-99,-99,-99,-99),
            SPersonalConsequences(pair<float,int>(33,2),pair<float,int>(0,0),pair<float,int>(55,100),pair<float,int>(50,5),pair<float,int>(0,0)));
        this->AddActorsSlot("Stealing money","Target",1,SCondition(-99,-99,-99,-99),
            SPersonalConsequences(pair<float,int>(33,1),pair<float,int>(0,0),pair<float,int>(55,-100),pair<float,int>(0,0),pair<float,int>(0,0)));
			
	this->AddEvent("Selling goods",PEACEFULL_MEETING,SConsequences(0,0,15,5,0));
        this->AddBackcodeTriger("Selling goods",CBackcodeTriger(backcodeList->get_background("Farmhand"),10));
        this->AddActorsSlot("Selling goods","Worker",1,SCondition(-99,-99,-99,-99),
            SPersonalConsequences(pair<float,int>(0,0),pair<float,int>(0,0),pair<float,int>(50,50),pair<float,int>(0,0),pair<float,int>(0,0)));
        this->AddActorsSlot("Selling goods","Buyer",1,SCondition(-99,-99,50,-99),
            SPersonalConsequences(pair<float,int>(0,0),pair<float,int>(0,0),pair<float,int>(50,-50),pair<float,int>(0,0),pair<float,int>(15,5)));

    this->AddEvent("This is my land!",PROPERTY_MANAGMENT,SConsequences(0,0,0,0,0));
        this->AddBackcodeTriger("This is my land!",CBackcodeTriger(backcodeList->get_background("Property Manager"),10));
        this->AddActorsSlot("This is my land!","Property owner",1,SCondition(-99,-99,-99,-99),
            SPersonalConsequences(pair<float,int>(0,0),pair<float,int>(0,0),pair<float,int>(0,0),pair<float,int>(0,0),pair<float,int>(0,0)));
        this->AddActorsSlot("This is my land!","Property buyer",1,SCondition(-99,-99,-99,-99),
            SPersonalConsequences(pair<float,int>(0,0),pair<float,int>(0,0),pair<float,int>(0,0),pair<float,int>(0,0),pair<float,int>(0,0)));
        this->AddPropertyRule("This is my land!",SPropertyRules("Property owner","Property buyer"));

		/*	
	this->AddEvent("Brave man starts crime handling",THREAT,SConsequences(0,0,-50,15,0));
        this->AddBackcodeTriger("Brave man starts crime handling",CBackcodeTriger(backcodeList->get_background("Crusader"),10));
        this->AddBackcodeTriger("Brave man starts crime handling",CBackcodeTriger(backcodeList->get_background("Disowned Noble"),10));
        this->AddBackcodeTriger("Brave man starts crime handling",CBackcodeTriger(backcodeList->get_background("Hedge Knight"),10));
        this->AddActorsSlot("Brave man starts crime handling","New Legalist",1,SCondition(-99,20,-99,-99),
            SPersonalConsequences(pair<float,int>(50,2),pair<float,int>(15,1),pair<float,int>(100,500),pair<float,int>(100,50),pair<float,int>(100,50)));
        this->AddActorsSlot("Brave man starts crime handling","New Orderwatchers",6,SCondition(-99,-99,-99,-99),
            SPersonalConsequences(pair<float,int>(60,1),pair<float,int>(20,1),pair<float,int>(0,0),pair<float,int>(80,20),pair<float,int>(25,25)));
        this->AddActorsSlot("Brave man starts crime handling","Criminals",4,SCondition(-99,-99,-99,-99),
            SPersonalConsequences(pair<float,int>(90,2),pair<float,int>(50,1),pair<float,int>(100,-100),pair<float,int>(0,0),pair<float,int>(50,-25)));

	*/
	


        for(int i=0;i<eventList.size();i++)
        {
            for(int d=0;d<eventList[i].size();d++)
            {
                cout << "|" << eventList[i][d].GetName() << endl;
                for(int actorid=0;actorid<eventList[i][d].GetBackcodeRuleSize();actorid++)
                {
                    cout << "\t|actor :" << eventList[i][d].GetBackcodeRule(actorid)->GetBackcode()->get_name() << endl;
                }
            }
        }

/*

        eventList[0].Init("Road crash",INCIDENT,SConsequences( 15,5,0,30,0 ),4);
            eventList[0].AddBackcodeTriger(CBackcodeTriger(backcodeList->get_background("Assasin"),10));
            eventList[0].AddActorSlot("Travelers",3);
            eventList[0].AddActorSlot("Assasin",1);

        eventList[1].Init("Road thugs attack",THREAT,SConsequences( 35,10,10,0,0 ),7);
            eventList[1].AddActorSlot("Thugs",2);
            eventList[1].AddActorSlot("Deffenders",2);

        eventList[2].Init("Big Man is coming",NEGOTIATION,SConsequences( -10,-20,30,-15,0 ),WHOLE_POPULATION);
            eventList[2].AddBackcodeTriger(CBackcodeTriger(backcodeList->get_background("Adventurous Noble"),10));
            eventList[2].AddActorSlot("Bigman",1);
            eventList[2].AddActorSlot("Security",2);
            eventList[2].AddActorSlot("Peasants",8);

        eventList[3].Init("Prominent priest is coming",NEGOTIATION,SConsequences( -15,0,20,-5,0 ),WHOLE_POPULATION);
            eventList[3].AddBackcodeTriger(CBackcodeTriger(backcodeList->get_background("Monk"),10));
            eventList[3].AddActorSlot("Prominent priest",1);
            eventList[3].AddActorSlot("Meeters",6);

        eventList[4].Init("A traveling merchant",DEAL,SConsequences( 5,-5,0,-15,0 ),3);
            eventList[4].AddActorSlot("Merchant",1);
            eventList[4].AddActorSlot("Caravan Hand",1);
            eventList[4].AddActorSlot("Buyer",1);


        eventList[5].Init("Feasting in Tavern",PEACEFULL_MEETING,SConsequences( 10,-15,0,10,0 ),5);
            eventList[5].AddActorSlot("Travelers",5);

*/
}

CEvent* CEventList::GetEvent(int typeID,int id)
{
    try {
        if(typeID >= eventList.size()) {
            throw "ERROR:(CEventList): EVENT ID IS GREATER THAN EVENTLIST SIZE\n";
        }
        if(id >= eventList[typeID].size()) {
                throw "ERROR:(CEventList): EVENT ID IS GREATER THAN EVENTLIST SIZE\n";
        } else {
                return &eventList[typeID][id];
        }
    }
    catch(const char* eror) { printf(eror); }
}

void CEventList::AddEvent(string name,int type,SConsequences cons)
{
    int id = type;
    eventList[id].push_back(CEvent());
    eventList[id][eventList[id].size()-1].Init(name,type,cons);
}

void CEventList::AddBackcodeTriger(string eventName,CBackcodeTriger triger)
{
    cout << "here21\n";
    for(int i=0;i<EVENT_TYPE_AMMOUNT;i++)
    {
        //cout << eventList.size() << "here22\n";
        if(eventList[i].size() != 0) {
            for(int d=0;d<eventList[i].size();d++)
            {
                if(eventName == eventList[i][d].GetName()) {
                    //cout << eventList[i].size() <<  "here222\n";
                    eventList[i][d].AddBackcodeTriger(CBackcodeTriger(backcodeList->get_background(triger.GetBackcode()->get_name()),triger.GetVeig()));
                }
            }
        }
    }
}

void CEventList::AddActorsSlot(string eventName,string slotName,int slotSize,SCondition condit,SPersonalConsequences personConceq)
{
    //cout << "here3\n";
    for(int i=0;i<eventList.size();i++)
    {
        if(eventList[i].size() != 0) {
            for(int d=0;d<eventList[i].size();d++)
            {
                if(eventName == eventList[i][d].GetName()) {
                    eventList[i][d].AddActorSlot(slotName,slotSize,condit,personConceq);
                }
            }
        }
    }
}

void CEventList::AddPropertyRule(string eventName,SPropertyRules newRule)
{
    for(int i=0;i<eventList.size();i++)
    {
        if(eventList[i].size() != 0) {
            for(int d=0;d<eventList[i].size();d++)
            {
                if(eventName == eventList[i][d].GetName() && eventList[i][d].GetType() == PROPERTY_MANAGMENT) {
                    eventList[i][d].AddPropertyRule(newRule);
                }
            }
        }
    }
}

int CEventList::GetTypeSize(int type)
{
    try {
        if(type > eventList.size() || type < 0) {
            throw "ERROR:(code 2281) OUT OF MASSIV RANGE\n";
        } else {
            //cout << "size " << eventList[type-1000].size() << endl;
            return eventList[type].size();
        }
    }
    catch(const char* eror) { printf(eror);  Sleep(3000); }
}

CEvent* CEventList::GetEvent(corda pairID)
{
    try {
        if(pairID.x > eventList.size() || pairID.x < 0) {
            throw "ERROR:(code 2282) OUT OF MASSIV RANGE\n";
        } else {
           // cout << pairID.x;
            return &eventList[pairID.x][pairID.y];
        }
    }
    catch(const char* eror) { printf(eror);  cout << pairID.x << endl; Sleep(3000); }
}

CEvent* CEventList::GetRandomEventByType(int type)
{
    // [type-1000]
}
