#include "CEventRandomiser.h"
#include "Sup/TrueRandom/ctruerandom.h"
/*
corda CEventRandomiser::GetNextEventId(CEventList * eventList,CLocation * location,CBackgroundsList * backList)
{
    int eventType;
    SConsequences baseVeigs;
    baseVeigs.Clear();
    for(int personId=0;personId<location->GetPersonAmmount();personId++)
    {
        baseVeigs = baseVeigs + location->GetPerson(personId)->GetBackground()->GetSitVeigs();
    }
    SConsequences localSituation = *location->GetLocationSituation();
    baseVeigs = baseVeigs + localSituation;
	
    CTrueRand randomDevice(0,100); int rndEventType = randomDevice.rand();
    int meetChance = getProc(baseVeigs.peaceMeetChance,baseVeigs.Accume());
    int threatChance = getProc(baseVeigs.threatChance,baseVeigs.Accume());
    int dealChance = getProc(baseVeigs.dealChance,baseVeigs.Accume());
    int negotChance = getProc(baseVeigs.negotiationChance,baseVeigs.Accume());
    int incidentChance = getProc(baseVeigs.incidentChance,baseVeigs.Accume());

    //cout << "CEVEnt list\n";
    if(rndEventType > (baseVeigs.Accume()-incidentChance)) {
        eventType = I NCIDENT;
    } else if(rndEventType > (baseVeigs.Accume()-incidentChance-negotChance) && rndEventType < (baseVeigs.Accume()-incidentChance)) {
        eventType = NEGOTIATION;
    } else if(rndEventType > (baseVeigs.Accume()-incidentChance-negotChance-dealChance) && rndEventType < (baseVeigs.Accume()-incidentChance-negotChance)) {
        eventType = DEAL;
    } else if(rndEventType > meetChance && rndEventType < (baseVeigs.Accume()-incidentChance-negotChance-dealChance)) {
        eventType = THREAT;
    } else if(rndEventType < meetChance) {
        eventType = PEACEFULL_MEETING;
    }
    if(eventType > 4) { eventType = 0; }
    //cout << eventType <<  "!!!!" << endl;
	CTrueRand randomDevice2(0,eventList->GetTypeSize(eventType));
    int randEventID = randomDevice2.rand();
    //cout << "ITS A ERANDOMIZER:: " << eventType << "|" << randEventID << endl;
    corda result = { eventType,randEventID };
    return result;
    /*
        currPeaceMeetChance : ++( nationalismPoints ) : --( aggressionPoints,concernPoints )
        currThreatChance : ++ ( povertyPoints,aggressionPoints ) : --( nationalismPoints )
        currDealChance : ++ ( nationalismPoints ) : --( povertyPoints,concernPoints )
        currNegotiationChance : ++ ( aggressionPoints,nationalismPoints ) : --( concernPoints )
        currIncidentChance : ++ ( ) : --( )
    */

//}

CEvent* CEventRandomiser::GetNextEventId(CEventList * eventList,CLocation * location,CBackgroundsList * backList)
{
	vector<int> personBackcodeList;
	vector<CPerson*> personList = location->GetAllPersons();
	//	making list of backcode triggers
	for(int persid=0;persid<personList.size();persid++)
	{
		personBackcodeList.push_back( personList[persid]->GetBackground()->get_id() );
	}
    //	making list of possibe events
    vector<CEvent*> possibleEventList;
	for(int typid=0;typid<eventList->GetTypesSize();typid++)
	{
        // СДЕСЯ КАКАЯТО ЖОПА, прокрутка кончается на 0/4 хотя размер типов 5, и стопается на 4м в списке типа, хотя размер того спика 7
        // возможно где-то происходит аут в баундс(хех), по сути то, здесь просто все бэктригеры  ивентов сравниваются с бэками персон на локации
        // и при нахождении соответствия кидаются в список возможных событий, что могло поййти не так????
        // действия : проверить все учавствующие геты, проверить как состовляются учавствующие списки
        // ++++
        // обнаружилось что все id бэков равны 0 | done
        /* пугающие строки, разве (да все рпвильно, бэков 48 штук)
            Great fair|0|2|backid#10
            43==43
            event choosed
         */
        //cout << "event type size " << eventList->GetTypesSize() << "|events size " << eventList->GetTypeSize(typid) << endl;
		for(int eventid=0;eventid<eventList->GetTypeSize(typid);eventid++)
		{
            //cout << "backids size " << personBackcodeList.size() << endl;
			for(int backid=0;backid<personBackcodeList.size();backid++) 
            {
                CEvent* possibleEvent = eventList->GetEvent(typid,eventid);
                //cout << possibleEvent->GetName() << "|" << typid << "|" << eventid  <<"|backid#"<<backid<< endl;
                for(int trigerid=0;trigerid<possibleEvent->GetBackcodeTrigerSize();trigerid++) {
                    if(possibleEvent->GetBackcodeTriger(trigerid)->GetTriger()->get_id() == personBackcodeList[backid])
                    {
                        //cout << possibleEvent->GetBackcodeTriger(trigerid)->GetTriger()->get_id()<< "=="<<personBackcodeList[backid]<<endl;
                        possibleEventList.push_back( possibleEvent );
                        //cout << "event choosed" << endl;
                        //cout << "possibleEventList size now is " << possibleEventList.size() << endl;
                    }
				}
			}
		}
	}
    //cout << "event randomize" << endl;
	//	choosing next event type by location situation
	int eventType;
    SConsequences baseVeigs;
    baseVeigs.Clear();
    for(int personId=0;personId<location->GetPersonAmmount();personId++)
    {
        baseVeigs = baseVeigs + location->GetPerson(personId)->GetBackground()->GetSitVeigs();
    }
    SConsequences localSituation = *location->GetLocationSituation();
    baseVeigs = baseVeigs + localSituation;    
	CTrueRand randomDevice(0,100); 
	int rndEventType = randomDevice.rand();
    int meetChance = getProc(baseVeigs.peaceMeetChance,baseVeigs.Accume());
    int threatChance = getProc(baseVeigs.threatChance,baseVeigs.Accume());
    int dealChance = getProc(baseVeigs.dealChance,baseVeigs.Accume());
    int negotChance = getProc(baseVeigs.negotiationChance,baseVeigs.Accume());
    int incidentChance = getProc(baseVeigs.incidentChance,baseVeigs.Accume());
    if(rndEventType > (baseVeigs.Accume()-incidentChance)) {
        eventType = INCIDENT;
    } else if(rndEventType > (baseVeigs.Accume()-incidentChance-negotChance) && rndEventType < (baseVeigs.Accume()-incidentChance)) {
        eventType = NEGOTIATION;
    } else if(rndEventType > (baseVeigs.Accume()-incidentChance-negotChance-dealChance) && rndEventType < (baseVeigs.Accume()-incidentChance-negotChance)) {
        eventType = DEAL;
    } else if(rndEventType > meetChance && rndEventType < (baseVeigs.Accume()-incidentChance-negotChance-dealChance)) {
        eventType = THREAT;
    } else if(rndEventType < meetChance) {
        eventType = PEACEFULL_MEETING;
    }
    //cout << "randomize in progres" << endl;
    //cout << "possible events list size is " << possibleEventList.size() << endl;

	if(possibleEventList.size() == 0) return nullptr;
	
	//	making final list of possible events
	vector<CEvent*> finalPossibleEventList;
	for(int eventid=0;eventid<possibleEventList.size();eventid++)
	{
		if(possibleEventList[eventid]->GetType() == eventType) {
            //cout << "DDDD" << eventid << endl;
			finalPossibleEventList.push_back( possibleEventList[eventid] );
		}
	}
    //cout << "finalPossibleEventList done" << endl;
   //cout << finalPossibleEventList.size() << endl;
    if(finalPossibleEventList.size() == 0) {
        if(possibleEventList.size() != 0) {//??? ANOTHER LIST
			//	choosing random event from final list
			CTrueRand rndDevice(0,possibleEventList.size());
            return possibleEventList[rndDevice.rand()];
        }
    }
	//	choosing random event from final list
    CTrueRand rndDevice2(0,finalPossibleEventList.size());
    return finalPossibleEventList[rndDevice2.rand()];
	
	//	putting person initiater to event????? were???? must in event chain->new parametr //todo:
}
