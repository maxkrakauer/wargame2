//#pragma once

#include <string>
#include <vector>
#include <stdexcept>
#include "Sniper.hpp"
#include <iostream>
using namespace std;


   
   bool Sniper::act(Soldier* soldier){
       if(soldier!=NULL && _player!=soldier->_player){
       reduce(soldier);
       printf(" bool Sniper::act(Soldier* soldier)");
       return true;
       }
       return false;
   }

   void Sniper::reduce(Soldier* soldier){
       soldier->_points-=50;
   }

   void Sniper::recover(){
       _points=100;
   }

