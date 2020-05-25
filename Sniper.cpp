//#pragma once

#include <string>
#include <vector>
#include <stdexcept>
#include "Sniper.hpp"


   
   void Sniper::act(Soldier* soldier){
       reduce(soldier);
   }

   void Sniper::reduce(Soldier* soldier){
       soldier->_points-=50;
   }

   void Sniper::recover(){
       _points=100;
   }

