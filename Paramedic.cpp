//#pragma once

#include <string>
#include <vector>
#include <stdexcept>
#include "Paramedic.hpp"
#include <iostream>
using namespace std;


  
   void Paramedic::recover(){
       cout<<"Paramedic::recover(); row is "<<_row<<", col is "<<_col;
       _points=100;
   }

   void Paramedic::reduce(Soldier* soldier){}

   bool Paramedic::act(std::vector<std::vector<Soldier*>> &board){
       cout<<"Paramedic::act(std::vector<std::vector<Soldier*>> &board); row is "<<_row<<", col is "<<_col;
       if(board[_row][_col]==nullptr){
           throw "contains null soldier";
       } 
       int player=board[_row][_col]->_player;
       bool chosen=false;
       for(int r=_row-1; r<_row+2; r++)
       for(int c=_col-1; c<_col+2; c++){
           if(r>-1 && c>-1 && r<board.size() && c<board[0].size() &&
           board[r][c]!=nullptr && board[r][c]->_player==player &&
           (r!=_row || c!=_col) && (r==_row || c==_col)){
               board[r][c]->recover();
               chosen=true;
           }
   }
   return chosen;
   }

   

