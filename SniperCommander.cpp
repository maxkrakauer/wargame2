

//#pragma once

#include <string>
#include <vector>
#include <stdexcept>
#include "SniperCommander.hpp"



   
   bool SniperCommander::act(std::vector<std::vector<Soldier*>> &board){
       cout<<"SniperCommander::act(std::vector<std::vector<Soldier*>> &board); row is"<<_row<<"col is "<<_col<<endl;
       Sniper::act(board);
       int rows=board.size();
       int cols=board[0].size();

       for(int r=0; r<rows; r++)
       for(int c=0; c<cols; c++){
           if(board[r][c]!=nullptr && 
           board[r][c]->_soltype==Soldier::soltype::sniper &&
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

   void SniperCommander::reduce(Soldier* &soldier){
       cout<<"SniperCommander::reduce(Soldier* soldier); row is "<<_row<<", col is "<<_col<<endl;
       soldier->_points-=100;
       if(soldier->_points<=0){
           cout<<"soldier in row "<<_row<<", col "<<_col<<" is killing soldier in row "<<soldier->_row<<", col "<<soldier->_col<<endl;
           delete(soldier);
           soldier=nullptr;
       }
   }

   void SniperCommander::recover(){
       cout<<"SniperCommander::recover(); row is "<<_row<<"col is "<<_col<<endl;
       _points=120;
   }

   


