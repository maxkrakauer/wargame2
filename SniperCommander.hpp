#pragma once
#include "Sniper.hpp"


class SniperCommander: public Sniper{

    public:
    SniperCommander(int player): Sniper(player){
        _soltype=snipercom;
        _points=120;
    }

  
   bool act(std::vector<std::vector<Soldier*>> &board);

   void reduce(Soldier* &soldier);

   void recover();

   //std::pair<int,int> chooseEnemy(std::vector<std::vector<Soldier*>> &board);

    
};