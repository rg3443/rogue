#include "CBackgroundsList.h"

void CBackgroundsList::Init()
{
	//backgroundList.resize(3);
	//backgroundList[0].set_name("Butcher");
	//backgroundList[1].set_name("Jailbreaker");
	//backgroundList[2].set_name("Crushed Lord");
	this->add_background("Adventurous Noble"); this->add_sit_veig(SConsequences(15,5,0,10,10));
	this->add_background("Apprentice"); this->add_sit_veig(SConsequences(15,5,0,10,0));
	this->add_background("Assassin"); this->add_sit_veig(SConsequences(-10,0,-10,5,10));
	this->add_background("Barbarian"); this->add_sit_veig(SConsequences(-10,10,-10,10,0));
	this->add_background("Bastard "); this->add_sit_veig(SConsequences(5,5,10,5,0));
	this->add_background("Beast Slayer"); this->add_sit_veig(SConsequences(-5,-5,5,10,0));
	this->add_background("Beggar"); this->add_sit_veig(SConsequences(15,5,0,10,0));
    this->add_background("Proffesional Archer"); this->add_sit_veig(SConsequences(5,0,15,0,0));
	this->add_background("Brawler"); this->add_sit_veig(SConsequences(0,10,0,5,0));
	this->add_background("Butcher"); this->add_sit_veig(SConsequences(0,0,10,-10,0));
	this->add_background("Caravan Hand"); this->add_sit_veig(SConsequences(0,-15,10,-15,0));
	this->add_background("Cultist"); this->add_sit_veig(SConsequences(10,10,0,5,10));
	this->add_background("Cripple"); this->add_sit_veig(SConsequences(0,0,0,0,0));
	this->add_background("Crusader"); this->add_sit_veig(SConsequences(0,-25,0,5,-10));
	this->add_background("Daytaler"); this->add_sit_veig(SConsequences(0,0,0,0,0));
	this->add_background("Deserter"); this->add_sit_veig(SConsequences(0,5,0,5,0));
	this->add_background("Disowned Noble"); this->add_sit_veig(SConsequences(20,10,10,10,10));
	this->add_background("Eunuch"); this->add_sit_veig(SConsequences(25,0,0,0,0));
	this->add_background("Farmhand"); this->add_sit_veig(SConsequences(5,-5,5,5,0));
	this->add_background("Fisherman"); this->add_sit_veig(SConsequences(5,5,5,5,0));
	this->add_background("Flagellant"); this->add_sit_veig(SConsequences(0,0,0,0,0));
	this->add_background("Gambler"); this->add_sit_veig(SConsequences(15,0,0,15,0));
	this->add_background("Gravedigger"); this->add_sit_veig(SConsequences(-5,0,0,-5,0));
	this->add_background("Graverobber"); this->add_sit_veig(SConsequences(-10,10,0,10,15));
	this->add_background("Hedge Knight"); this->add_sit_veig(SConsequences(0,-25,0,-25,0));
	this->add_background("Historian"); this->add_sit_veig(SConsequences(10,0,5,0,0));
	this->add_background("Houndmaster"); this->add_sit_veig(SConsequences(0,0,0,0,0));
	this->add_background("Hunter"); this->add_sit_veig(SConsequences(0,5,10,-5,0));
	this->add_background("Juggler"); this->add_sit_veig(SConsequences(10,-10,0,5,0));
	this->add_background("Killer on the run"); this->add_sit_veig(SConsequences(-10,30,0,10,0));
    this->add_background("Kings Guard"); this->add_sit_veig(SConsequences(0,-15,0,-15,-15));
	this->add_background("Lumberjack"); this->add_sit_veig(SConsequences(10,-5,5,0,0));
	this->add_background("Messenger"); this->add_sit_veig(SConsequences(0,0,10,5,0));
	this->add_background("Militia"); this->add_sit_veig(SConsequences(0,-10,0,-10,0));
	this->add_background("Miller"); this->add_sit_veig(SConsequences(5,0,10,0,0));
	this->add_background("Miner"); this->add_sit_veig(SConsequences(5,0,5,0,10));
	this->add_background("Minstrel"); this->add_sit_veig(SConsequences(25,0,0,5,0));
	this->add_background("Monk"); this->add_sit_veig(SConsequences(5,-5,0,-10,0));
	this->add_background("Poacher"); this->add_sit_veig(SConsequences(0,5,10,20,0));
	this->add_background("Refugee"); this->add_sit_veig(SConsequences(5,5,5,5,5));
	this->add_background("Retired Soldier"); this->add_sit_veig(SConsequences(0,-5,0,-5,0));
	this->add_background("Thief"); this->add_sit_veig(SConsequences(0,30,-30,10,10));
	this->add_background("Tailor"); this->add_sit_veig(SConsequences(5,0,15,5,0));
	this->add_background("Vagabond"); this->add_sit_veig(SConsequences(0,0,0,0,0));
	this->add_background("Witchhunter"); this->add_sit_veig(SConsequences(0,5,0,10,0));
	this->add_background("Trader"); this->add_sit_veig(SConsequences(0,10,30,10,10));
	this->add_background("Legalist"); this->add_sit_veig(SConsequences(0,0,10,-30,-30)); // zakonnic
    this->add_background("Property Manager"); this->add_sit_veig(SConsequences(10,0,10,20,0));
}

CBackground* CBackgroundsList::get_background(string name)
{
	for(int id=0;id<backgroundList.size();id++)
	{
        cout << "sravnim " << name << " s " << backgroundList[id]->get_name() << endl;
		if(backgroundList[id]->get_name() == name) return backgroundList[id];
	}
}

void CBackgroundsList::add_sit_veig(SConsequences veigs)
{
    backgroundList[backgroundList.size()-1]->add_sit_veigs(veigs);
}

void CBackgroundsList::add_background(string backstr)
{
    ammountCounter++;
    CBackground * buf = new CBackground(backstr);
    buf->set_id(ammountCounter);
    backgroundList.push_back(buf);

}
