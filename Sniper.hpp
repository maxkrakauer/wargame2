#pragma once

#include "Soldier.hpp"


class Sniper: public Soldier{

   public: 
   Sniper(int player):Soldier(player){
      _soltype=sniper;
      _points=100;
   }

   void act(Soldier* soldier);

   void reduce(Soldier* soldier);

   void recover();


};