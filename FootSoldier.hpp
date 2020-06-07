#pragma once

#include "Soldier.hpp"


class FootSoldier: public Soldier{

  
   public: 
   FootSoldier(int player):Soldier(player){
      _soltype=footer;
      _points=100;
   }

   bool act(std::vector<std::vector<Soldier*>> &board);

   void reduce(Soldier* &soldier);

   void recover();

   std::pair<int,int> chooseEnemy(std::vector<std::vector<Soldier*>> &board);

};