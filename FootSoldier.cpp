//#pragma once

#include <string>
#include <vector>
#include <stdexcept>
#include "FootSoldier.hpp"


   
   void FootSoldier::act(Soldier* soldier){
       reduce(soldier);
   }

   void FootSoldier::reduce(Soldier* soldier){
       soldier->_points-=10;
   }

   void FootSoldier::recover(){
       _points=100;
   }

