#pragma once

#include "Soldier.hpp"


class Sniper: public Soldier{

   public: 
   Sniper(int player):Soldier(player){
      _soltype=sniper;
      _points=100;
   }

   bool act(std::vector<std::vector<Soldier*>> &board);

   void reduce(Soldier* &soldier);

   void recover();

   std::pair<int,int> chooseEnemy(std::vector<std::vector<Soldier*>> &board);

};