//#pragma once

#include <string>
#include <vector>
#include <stdexcept>
#include "Paramedic.hpp"


  
   void Paramedic::recover(){
       _points=100;
   }

   void Paramedic::act(Soldier* soldier){
       soldier->recover(); 
   }

   void Paramedic::reduce(Soldier* soldier){}

