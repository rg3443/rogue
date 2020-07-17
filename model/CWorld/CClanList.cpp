#include "CClanList.h"

void CClanList::init(int clan_ammount)
{
	clan_generator.init();
	
	all_clans.resize(clan_ammount);
	for(int clan_id=0;clan_id < all_clans.size(); clan_id++)
	{
		int clan_type = clan_generator.get_clan_type();
		string clan_name = clan_generator.get_clan_name();
		all_clans[clan_id].init(clan_id,clan_type,clan_name);
		cout << "STATUS: CLAN CREATED!" << endl;
		cout << "\tCLAN ID : " << clan_id << endl;
		cout << "\tCLAN NAME : " << clan_name << endl;
		cout << "\tCLAN TYPECODE : " << clan_type << endl;
		
	}
}
