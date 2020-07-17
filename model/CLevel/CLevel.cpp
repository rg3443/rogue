#include "CLevel.h"

CLevel::CLevel( CLocation * new_current_location,CPlayer * player )
{
   // this->init(player);
    for(int y=0;y<new_current_location->GetH();y++)
    {
        for(int x=0;x<new_current_location->GetW();x++)
        {

        }
    }
}

void CLevel::Init( CPlayer * player,CLocation * location,int comedir)
{
    possibeWildEnemyList.init();
    this->player = player;
    playerPawn.Init(player,comedir);
    currentLocation = location;
    // INIT PERSON PESHKI
    vector<int> actingPersonList = currentLocation->GetActorsId();
    personPawnList.resize( actingPersonList.size() );
    for(int persID=0;persID<actingPersonList.size();persID++)
    {
        personPawnList[persID].Init( currentLocation->GetPerson(actingPersonList[persID]) );
    }
    //  INIT wild ENEMY PESHKI
    int wildEnemyAmm = currentLocation->GetWildEnemyAmmount();
    wenemyPawnList.resize( wildEnemyAmm );
    for(int wenemyID=0;wenemyID<wildEnemyAmm;wenemyID++)
    {
        CEnemy* enemyToSPawn = possibeWildEnemyList.get_rand_enemy_by_locatype(currentLocation->GetLocationType());
        wenemyPawnList[wenemyID].Init(enemyToSPawn); //???????
    }
}

void CLevel::__console_tile_ground_show()
{
    /*
    cout << "TILEGROUND DATA :\n\n";
    for(int y=0;y<map_field.h_size();y++)
    {
        for(int x=0;x<map_field.w_size();x++)
        {
            CTile * tile = map_field.get_tile(x,y);
            switch(tile->get_ground_type())
            {
            case EARTH:
                cout << "E";
            break;
            case STONE:
                cout << "S";
            break;
            case WOOD:
                cout << "W";
            break;
            }
        }
        cout << endl;
    }
    cout << "ENEMYDATA :\n\n";
    for(int y=0;y<map_field.h_size();y++)
    {
        for(int x=0;x<map_field.w_size();x++)
        {
            bool crt_here = false;
            for(int i=0;i<creature_list.enemy_list.size();i++)
            {
                int ex = creature_list.enemy_list[i].get_x();
                int ey = creature_list.enemy_list[i].get_y();
                if(ex == x && ey == y)
                {
                    crt_here = true;
                }
            }
            if(crt_here) cout << "X";
            else cout << "O";
        }
        cout << endl;
    }
    */
}

