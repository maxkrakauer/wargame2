#pragma once

#include "Soldier.hpp"


class Paramedic: public Soldier{

   public: 
   Paramedic(int player):Soldier(player){
      _soltype=paramedic;
      _points=100;
   }

   

   void reduce(Soldier* soldier);

   void act(Soldier* soldier);

   void recover();

};