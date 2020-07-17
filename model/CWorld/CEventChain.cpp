#include "CEventChain.h"
#include "Sup/TrueRandom/ctruerandom.h"

CEventChain::~CEventChain()
{
	personCounter = -1;
}

void CEventChain::Create(string name,CEvent event,SLocationStatus * localEvent,CLocation * currentLocation)
{
    this->name = name;
    currentEvent = event;
    currentLocationEvent = localEvent;
    this->currentLocation = currentLocation;
}

void CEventChain::AddMember(CPerson* newMember)
{
	/*
	int prevCounter = personCounter;
	personCounter++;
	bool personPassed = false;
	SCondition personCondition = currentEvent.GetSlot(personCounter)->personCondition;
	if(personCondition.needFame != -99) {
		if(newMember->GetFame() < personCondition.needFame) {
			personPassed = false;
			personCounter--;
		} else {
			personPassed = true;
		}
	}
	if(personCondition.needInfluence != -99 && personCounter > prevCounter) {
		if(newMember->GetInfluence() < personCondition.needInfluence) {
			personPassed = false;
		} else {
			personPassed = true;
		}
	}
	if(personCondition.needMoney != -99 && personCounter > prevCounter) {
		if(newMember->GetMoney() < personCondition.needMoney) {
			personPassed = false;
		} else {
			personPassed = true;
		}
	}
	if(personCondition.needWounds != -99 && personCounter > prevCounter) {
		if(newMember->GetWounds() < personCondition.needWounds) {
			personPassed = false;
		} else {
			personPassed = true;
		}
	}
	*/
	bool personPassed = true;
	if(personPassed) {
		memberList.push_back( newMember );
		int personRolecode[2] = { newMember->GetRolecode(0),newMember->GetRolecode(1) };
		CBackground * personBackcode = newMember->GetBackground();
		currentEvent.AddPersonData(personRolecode[0],personRolecode[1],personBackcode);
	}
}

void CEventChain::CalculateResults()/*managing persons items*/
{
    //todo: как суко оно выберает какойму мемберу перечислить статусы слота
    //todo: |так оно и было|сука все почему-то накапливается, как будто обрабатывается только одна персона, возможно тупой ранд щзасовывает одну и туже по несколько раз, из-за чего мемберы содержат копии одного и того же персоны
	for(int memberId=0;memberId<memberList.size();memberId++)
	{
        SSlot* eventActorSlot = currentEvent.GetSlot(memberId); //слотов столько же сколько и акторов | неит!!!!! слот может вмещать кол-во подобных участников
        //  ДЛЯ КАЖДОГО СЛОТА СВОЙ FOR
        SPersonalConsequences personalConseq = eventActorSlot->personalConsequences;
		//wound calc
		CTrueRand rnddevice(0,100);
        if(rnddevice.rand() < personalConseq.woundsChance.first) {
           // cout << "BEFORE:" << memberList[memberId]->GetWounds() << endl;
            memberList[memberId]->SetWounds(memberList[memberId]->GetWounds() + personalConseq.woundsChance.second);
           // cout << "AFTER:" << memberList[memberId]->GetWounds() << endl;
		}
        if(rnddevice.rand() < personalConseq.deathChance.first) {
            memberList[memberId]->SetDeath(memberList[memberId]->GetDeath() + personalConseq.deathChance.second);
		}
        if(rnddevice.rand() < personalConseq.profitChance.first) {
            memberList[memberId]->SetMoney(memberList[memberId]->GetMoney() + personalConseq.profitChance.second);
		}
        if(rnddevice.rand() < personalConseq.fameChance.first) {
            memberList[memberId]->SetFame(memberList[memberId]->GetFame() + personalConseq.fameChance.second);
		}
        if(rnddevice.rand() < personalConseq.influenceChance.first) {
            memberList[memberId]->SetInfluence(memberList[memberId]->GetInfluence() + personalConseq.influenceChance.second);
		}

        //
        if(currentEvent.GetType() == PROPERTY_MANAGMENT) {
            //SPropertyRules* currentPropertyRules = currentEvent.GetPropertyRule();
            //int memberId = currentEvent.GetMemberIdBySlotForEventChain(eventActorSlot->slotName);
            //todo: сделать так чтобы у персоны тоже подязывалась/отвязывалась проперти
            //if(memberId == 1) { // 0 - allways is oldOwner; 1 - allways is newOwner;
                SProperty* prop = currentLocation->GetRandomFreeProperty();
                if(prop != nullptr)
                prop->ownerId = memberList[1]->GetId();
                //cout << "prop with id " << prop->id << " has new owner with id " << memberList[memberId]->GetId() << endl;
            //}
        }
	}
}

SConsequences* CEventChain::GetExitResult()
{
    return currentEvent.GetSituationPoints();
}

void CEventChain::_console_show()
{

}
