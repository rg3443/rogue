#include "CEvent.h"

void CEvent::Init(string name,int type,SConsequences sS)
{
    this->actorsAmmount = 0;
    this->name = name;
    this->type = type;
    startingSituation = sS;
}

void CEvent::AddDescription(string description)
{
    this->description = description;
}

void CEvent::AddBackcodeRule(CBackground * backcode, SConsequences rule)
{
    CBackcodeRule newRule( backcode,rule );
    backcodeRuleList.push_back( newRule );
}

void CEvent::AddPropertyRule(SPropertyRules newRule)
{
	propertyRule = newRule;
}

void CEvent::AddBackcodeTriger(CBackcodeTriger backcodeTriger)
{
    CBackcodeTriger newTriger(backcodeTriger.GetTriger(),backcodeTriger.GetVeig());
    backcodeTrigerList.push_back( newTriger );
}

void CEvent::AddActorSlot(string slotTypeName,int actorsAmmount,SCondition personCondition,SPersonalConsequences personConseq)
{
    this->actorsAmmount += actorsAmmount;
    //cout << this->actorsAmmount << endl;
    actorSlot.push_back( SSlot(slotTypeName,actorsAmmount,personCondition) );
	actorSlot[actorSlot.size()-1].AddPersonalConseq(personConseq);
}

SSlot* CEvent::GetSlot(int actorId)
{
	//todo:
	int serched = 0;
	for(int i=0;i<actorSlot.size();i++) {
		if(actorSlot[i].actorAmmount < actorId-serched) {
			serched += actorSlot[i].actorAmmount;
		} else {
			//cout << actorSlot[i].slotName << endl;
			return &actorSlot[i];
		}
	}
}

int CEvent::GetMemberIdBySlotForEventChain(string slotName)
{
	int memberIdCounter = 0;
	for(int i=0;i<actorSlot.size();i++) {
		if(actorSlot[i].slotName == slotName) {
			return memberIdCounter;
		}
		memberIdCounter++;
	}
}

void CEvent::AddPersonData(int rolecode1,int rolecode2,CBackground * backcode)
{
    switch(this->type)
    {
        //изменение нач последствий
    case PEACEFULL_MEETING:
        if(rolecode1 == LAWFULL) {
            startingSituation.AddPoints(SConsequences(-5,0,10,-5,0));
        } else if(rolecode1 == NEUTRALSLOT1) {
            startingSituation.AddPoints(SConsequences(0,-5,5,0,0));
        } else if(rolecode1 == CHAOTIC) {
            startingSituation.AddPoints(SConsequences(5,10,-5,0,0));
        }
        if(rolecode2 == GOOD) {
            startingSituation.AddPoints(SConsequences(-10,-5,-5,0,0));
        } else if(rolecode2 == NEUTRALSLOT2) {
            startingSituation.AddPoints(SConsequences(0,0,5,0,0));
        } else if(rolecode2 == EVIL) {
            startingSituation.AddPoints(SConsequences(10,10,-5,5,0));
        }
    break;
    case THREAT:
        if(rolecode1 == LAWFULL) {
            startingSituation.AddPoints(SConsequences(-10,10,0,-5,0));
        } else if(rolecode1 == NEUTRALSLOT1) {
            startingSituation.AddPoints(SConsequences(5,5,0,0,0));
        } else if(rolecode1 == CHAOTIC) {
            startingSituation.AddPoints(SConsequences(10,10,-5,5,0));
        }
        if(rolecode2 == GOOD) {
            startingSituation.AddPoints(SConsequences(-15,-5,-5,-5,0));
        } else if(rolecode2 == NEUTRALSLOT2) {
            startingSituation.AddPoints(SConsequences(5,5,5,0,0));
        } else if(rolecode2 == EVIL) {
            startingSituation.AddPoints(SConsequences(10,10,-10,5,0));
        }
    break;
    case DEAL:
        if(rolecode1 == LAWFULL) {
            startingSituation.AddPoints(SConsequences(-10,-10,10,-10,0));
        } else if(rolecode1 == NEUTRALSLOT1) {
            startingSituation.AddPoints(SConsequences(-5,-5,5,-5,0));
        } else if(rolecode1 == CHAOTIC) {
            startingSituation.AddPoints(SConsequences(10,10,20,5,0));
        }
        if(rolecode2 == GOOD) {
            startingSituation.AddPoints(SConsequences(-15,-5,-5,-10,0));
        } else if(rolecode2 == NEUTRALSLOT2) {
            startingSituation.AddPoints(SConsequences(5,5,5,0,0));
        } else if(rolecode2 == EVIL) {
            startingSituation.AddPoints(SConsequences(10,10,10,10,0));
        }

    break;
    case NEGOTIATION:
        if(rolecode1 == LAWFULL) {
            startingSituation.AddPoints(SConsequences(20,10,10,0,0));
        } else if(rolecode1 == NEUTRALSLOT1) {
            startingSituation.AddPoints(SConsequences(-5,-5,-5,0,0));
        } else if(rolecode1 == CHAOTIC) {
            startingSituation.AddPoints(SConsequences(10,15,20,0,0));
        }
        if(rolecode2 == GOOD) {
            startingSituation.AddPoints(SConsequences(-15,-5,-5,-5,0));
        } else if(rolecode2 == NEUTRALSLOT2) {
            startingSituation.AddPoints(SConsequences(5,5,5,0,0));
        } else if(rolecode2 == EVIL) {
            startingSituation.AddPoints(SConsequences(20,10,-10,5,0));
        }
    break;
    }
	
    for(int ruleId=0;ruleId<backcodeRuleList.size();ruleId++)
    {
        if(backcodeRuleList[ruleId].GetBackcode() == backcode) {
            startingSituation.AddPoints( backcodeRuleList[ruleId].GetRule() );
        }
    }
	
	

}
