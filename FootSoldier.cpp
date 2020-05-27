//#pragma once

#include <string>
#include <vector>
#include <stdexcept>
#include "FootSoldier.hpp"


   
   bool FootSoldier::act(Soldier* soldier){
       if(soldier!=NULL && _player!=soldier->_player){
       reduce(soldier);
       printf(" bool FootSoldier::act(Soldier* soldier){\n");
       return true;
       }
       return false;
   }

   void FootSoldier::reduce(Soldier* soldier){
       soldier->_points-=10;
   }

   void FootSoldier::recover(){
       _points=100;
   }

