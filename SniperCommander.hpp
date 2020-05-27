#pragma once
#include "Sniper.hpp"


class SniperCommander: public Sniper{

    public:
    SniperCommander(int player): Sniper(player){
        _soltype=snipercom;
        _points=120;
    }

   bool act(Soldier* soldier);

   void reduce(Soldier* soldier);

   void recover();

    
};