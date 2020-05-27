//#pragma once

#include <string>
#include <vector>
#include <stdexcept>
#include "Paramedic.hpp"
#include <iostream>
using namespace std;


  
   void Paramedic::recover(){
       _points=100;
   }

   bool Paramedic::act(Soldier* soldier){
       if(soldier!=NULL && _player==soldier->_player){
       soldier->recover(); 
       printf("bool Paramedic::act(Soldier* soldier)");
       }
       return false;
   }

   void Paramedic::reduce(Soldier* soldier){}

