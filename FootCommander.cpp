//#pragma once

#include <string>
#include <vector>
#include <stdexcept>
#include "FootCommander.hpp"



   void FootCommander::reduce(Soldier* &soldier){
       cout<<"FootCommander::reduce(Soldier* soldier)"<<endl;
       soldier->_points-=20;
       if(soldier->_points<=0){
           cout<<"soldier in row "<<_row<<", col "<<_col<<" is killing soldier in row "<<soldier->_row<<", col "<<soldier->_col<<endl;
           delete(soldier);
           soldier=nullptr;
       }
   }

   void FootCommander::recover(){
       cout<<"FootCommander::recover(); row is "<<_row<<", col is "<<_col<<endl;
       _points=150;
   }



    bool FootCommander::act(std::vector<std::vector<Soldier*>> &board){
       cout<<"FootCommander::act(std::vector<std::vector<Soldier*>> &board); row is "<<_row<<", col is "<<_col<<endl;
       std::pair<int, int>enemy = chooseEnemy(board);
       if(enemy.first>-1 && enemy.second>-1){
       reduce(board[enemy.first][enemy.second]);

       int rows=board.size();
       int cols=board[0].size();

       for(int r=0; r<rows; r++)
       for(int c=0; c<cols; c++){
           if(board[r][c]!=nullptr && 
           board[r][c]->_soltype==Soldier::soltype::footer &&
           board[r][c]->_player==_player){
               board[r][c]->act(board);
           }
       }
       return true;
       }
       return false;
   }



