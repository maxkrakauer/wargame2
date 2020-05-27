

//#pragma once

#include <string>
#include <vector>
#include <stdexcept>
#include "FootCommander.hpp"



   
   bool FootCommander::act(Soldier* soldier){
       if(soldier!=NULL && _player!=soldier->_player){
       reduce(soldier);
       printf("bool FootCommander::act(Soldier* soldier){\n");
       return true;
       }
       return false;
   }

   void FootCommander::reduce(Soldier* soldier){
       soldier->_points-=20;
   }

   void FootCommander::recover(){
       _points=150;
   }

