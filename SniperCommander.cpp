

//#pragma once

#include <string>
#include <vector>
#include <stdexcept>
#include "SniperCommander.hpp"



   
   void SniperCommander::attack(Soldier* soldier){
       reduce(soldier);
   }

   void SniperCommander::reduce(Soldier* soldier){
       soldier->_points-=100;
   }

   void SniperCommander::recover(){
       _points=120;
   }

