//#pragma once

#include <string>
#include <vector>
#include <stdexcept>
#include "FootSoldier.hpp"


   

   void FootSoldier::reduce(Soldier* &soldier){
       cout<<"FootSoldier::reduce(Soldier* soldier)"<<endl;
       soldier->_points-=10;
       if(soldier->_points<=0){
           cout<<"soldier in row "<<_row<<", col "<<_col<<" is killing soldier in row "<<soldier->_row<<", col "<<soldier->_col<<endl;
           delete(soldier);
           soldier=nullptr;
       }
   }

   void FootSoldier::recover(){
       cout<<"FootSoldier::recover()"<<" row is "<<_row<<", col is "<<_col<<endl;
       _points=100;
   }

   std::pair<int,int> FootSoldier::chooseEnemy(std::vector<std::vector<Soldier*>> &board){
       if(_row<0 || _col<0 || _row>=board.size() || _col>=board[0].size())
       throw "out of bounds";
       int row=-1;
       int col=-1;
       int player=board[_row][_col]->_player;
       bool chosen=false;
       for(int r=_row-1; r<_row+2 &&!chosen; r++)
       for(int c=_col-1; c<_col+2 &&!chosen; c++){
           if(r>-1 && c>-1 && r<board.size() && c<board[0].size() &&
           board[r][c]!=nullptr && board[r][c]->_player!=player &&
           (r!=_row || c!=_col) && (r==_row || c==_col)){
               row=r;
               col=c;
               chosen=true;
           } //inner fol loop
       } //outer for loop
       return {row,col};
   } //end of choose enemy function


    bool FootSoldier::act(std::vector<std::vector<Soldier*>> &board){
       std::pair<int, int>enemy = chooseEnemy(board);
       cout<<"enemy chosen is: "<<enemy.first<<", "<<enemy.second<<endl;
       if(enemy.first>-1 && enemy.second>-1){
       reduce(board[enemy.first][enemy.second]);
       return true;
       }
       return false;
   }

