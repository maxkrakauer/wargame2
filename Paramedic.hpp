#pragma once

#include "Soldier.hpp"


class Paramedic: public Soldier{

   public: 
   Paramedic(int player):Soldier(player){
      _soltype=paramedic;
      _points=100;
   }

   public:
   
   void reduce(Soldier* soldier);

   bool act(std::vector<std::vector<Soldier*>> &board);

   void recover();

};