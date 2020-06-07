#pragma once

#include "Paramedic.hpp"


class ParamedicCommander: public Paramedic{

   public: 
   ParamedicCommander(int player):Paramedic(player){
      _soltype=paracom;
      _points=200;
   }

   void reduce(Soldier* soldier);

   bool act(std::vector<std::vector<Soldier*>> &board);

   void recover();

};