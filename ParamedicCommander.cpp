//#pragma once

#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include "ParamedicCommander.hpp"
using namespace std;

  
   void ParamedicCommander::recover(){
       _points=200;
   }

   bool ParamedicCommander::act(Soldier* soldier){
       
       if(soldier!= NULL && _player==soldier->_player){
       soldier->recover(); 
       printf("bool ParamedicCommander::act(Soldier* soldier)");
       }
       return false;
   }

   void ParamedicCommander::reduce(Soldier* soldier){}



