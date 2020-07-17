#include "CClan.h"

void CClan::init(int clan_id,int clan_type, string clan_name)
{
	this->clan_id = clan_id;
	this->clan_type = clan_type;
	this->clan_name = clan_name;

}

void CClan::consoleShowMembers()
{
	//cout << "CLAN ID#" << clan_id << " MEMBERS LIST" << endl;
	for(int personId=0;personId<members.size();personId++)
	{
		int personGlobalId = members[personId]->GetId();
		string firstName = members[personId]->GetFname();
		string secondName = members[personId]->GetSname();
		//cout << "\tMEMBER #" << personId << endl;
		//cout << "\t\tNAME:" << firstName << "\n\t\tSNAME:" << secondName << "\n\t\tGLOBAL ID:" << personGlobalId << endl;
	}
}
