//#pragma once

#include <string>
#include <vector>
#include <stdexcept>
#include "ParamedicCommander.hpp"


  
   void ParamedicCommander::recover(){
       _points=200;
   }

   void ParamedicCommander::act(Soldier* soldier){
       soldier->recover(); 
   }

   void ParamedicCommander::reduce(Soldier* soldier){}



