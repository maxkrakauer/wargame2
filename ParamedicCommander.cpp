//#pragma once

#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include "ParamedicCommander.hpp"
using namespace std;

  
   void ParamedicCommander::recover(){
       cout<<"ParamedicCommander::recover(); row is "<<_row<<", col is"<<_col<<endl;
       _points=200;
   }

   bool ParamedicCommander::act(std::vector<std::vector<Soldier*>> &board){
       cout<<"ParamedicCommander::act(std::vector<std::vector<Soldier*>> &board); row is "<<_row<<", col is "<<_col<<endl;
       Paramedic::act(board);
       int rows=board.size();
       int cols=board[0].size();

       for(int r=0; r<rows; r++)
       for(int c=0; c<cols; c++){
           if(board[r][c]!=nullptr && 
           board[r][c]->_soltype==Soldier::soltype::paramedic &&
           board[r][c]->_player==_player){
              board[r][c]->act(board); 
              /*
              since the object that board[r][c] points to is a paramedic object, 
              and act is a virtual function, paramedic's act will be called, not soldier's.
              */
           }
       }
       return true;   
   }

   void ParamedicCommander::reduce(Soldier* soldier){}



