#pragma once

#include "Soldier.hpp"


class FootSoldier: public Soldier{

   public: 
   FootSoldier(int player):Soldier(player){
      _soltype=footer;
      _points=100;
   }

   bool act(Soldier* soldier);

   void reduce(Soldier* soldier);

   void recover();

};