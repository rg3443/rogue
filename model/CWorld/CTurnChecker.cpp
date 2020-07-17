#include "CTurnChecker.h"

void CTurnChecker::Init(CPersonList * personList, CPropertyList * propertyList, SLocationMap locationMap)
{
	this->personList = personList;
	this->propertyList = propertyList;
	this->locationMap = locationMap;
}

void CTurnChecker::CheckTurn()
{
	//personList->CheckAlive();//rework
	//propertyList->CheckOwners();//rework
	//пройтись по персонам найти мертвых
	//если персона мертва передать проперти другой персоне на той же локации с наибольш влиянием
	for(int perid=0;perid<personList->size();perid++) {
		CPerson* currentPerson = personList->get_person(perid);
		if(currentPerson->GetDeath() > 0 && currentPerson->GetWounds() > 4) {
			cout << "personDead" << endl;
			int pposx = currentPerson->GetCurrLocX();
			int pposy = currentPerson->GetCurrLocY();
			SProperty* personProperty = propertyList->GetPropertyByOwnerId(currentPerson->GetId());
			if(personProperty != nullptr) {
				cout << "and have property" << endl;
				int highestInf = 0,choosenPersonId = -1;
				//vector<CPerson*> lpersonList = locationMap.locations[pposy][pposx]->GetAllPersons();
				cout << "location x" << pposx << "|y" << pposy << "|have " << locationMap.locations[pposy][pposx]->GetPersonAmmount() << " persons" << endl;
				for(int lperid=0;lperid<locationMap.locations[pposy][pposx]->GetPersonAmmount();lperid++) {
					CPerson* newOwnerPerson = locationMap.locations[pposy][pposx]->GetPerson(lperid);
					if(newOwnerPerson->GetDeath() != 0 && newOwnerPerson->GetInfluence() > highestInf) {
						cout << "old highest inf=" << highestInf << "|new highest inf=" << newOwnerPerson->GetInfluence() << endl;
						choosenPersonId = newOwnerPerson->GetId();
						highestInf = newOwnerPerson->GetInfluence();
					}
				}
				//если подходящей персоны нет, то передать первой в списке
				if(choosenPersonId != -1) {
					personProperty->ownerId = choosenPersonId;
				} else {
					personProperty->ownerId = locationMap.locations[pposy][pposx]->GetPerson(0)->GetId();
				}
				
				cout << "property id" << personProperty->id << "new owner is person with id" << choosenPersonId << endl;
			} else {
				cout << "and have no property" << endl;
			}
			locationMap.locations[pposy][pposx]->ErasePersonByGlobalId(currentPerson->GetId());
			cout << "and succsesfully erased from location x" << pposx << "|y" << pposy << " person list" << endl;
		} else {
			if(currentPerson->GetWounds() != 0) {
				currentPerson->SetWounds(currentPerson->GetWounds()-1);
			}
		}
	}
	
}