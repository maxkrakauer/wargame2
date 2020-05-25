#pragma once
#include "FootSoldier.hpp"


class FootCommander: public FootSoldier{

    public:
    FootCommander(int player): FootSoldier(player){
        _soltype=footcom;
        _points=150;
    }

   void act(Soldier* soldier);

   void reduce(Soldier* soldier);

   void recover();

    
};