#pragma once

#include "FootSoldier.hpp"


class FootCommander: public FootSoldier{

  

   public: 
   FootCommander(int player):FootSoldier(player){
      _soltype=footcom;
      _points=150;
   }

   bool act(std::vector<std::vector<Soldier*>> &board);

   void reduce(Soldier* &soldier);

   void recover();

   
};