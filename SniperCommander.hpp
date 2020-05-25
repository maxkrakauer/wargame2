#pragma once
#include "Sniper.hpp"


class SniperCommander: public Sniper{

    public:
    SniperCommander(int player): Sniper(player){
        _soltype=snipercom;
        _points=120;
    }

   void attack(Soldier* soldier);

   void reduce(Soldier* soldier);

   void recover();

    
};