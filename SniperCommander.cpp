

//#pragma once

#include <string>
#include <vector>
#include <stdexcept>
#include "SniperCommander.hpp"



   
   bool SniperCommander::act(Soldier* soldier){
       if(soldier!=NULL && _player!=soldier->_player){
       reduce(soldier);
       printf(" bool SniperCommander::act(Soldier* soldier)");
       return true;
       }
       return false;
   }

   void SniperCommander::reduce(Soldier* soldier){
       soldier->_points-=100;
   }

   void SniperCommander::recover(){
       _points=120;
   }

