//#pragma once

#include <string>
#include <vector>
#include <stdexcept>
#include "Sniper.hpp"


   
   void Sniper::reduce(Soldier* &soldier){
       cout<<"Sniper::reduce(Soldier* soldier); row is "<<_row<<", col is "<<_col<<endl;
       soldier->_points-=50;
       if(soldier->_points<=0){
           cout<<"soldier in row "<<_row<<", col "<<_col<<" is killing soldier in row "<<soldier->_row<<", col "<<soldier->_col<<endl;
           delete(soldier);
           soldier=nullptr;
       }
   }

   void Sniper::recover(){
       cout<<"Sniper::recover(); row is "<<_row<<", col is "<<_col<<endl;
       _points=100;
   }

   std::pair<int,int> Sniper::chooseEnemy(std::vector<std::vector<Soldier*>> &board){
       if(_row<0 || _col<0 || _row>=board.size() || _col>=board[0].size())
       throw "out of bounds";
       int row=-1;
       int col=-1;
       int player=board[_row][_col]->_player;
       int maxpoints=0;
       for(int r=0; r<board.size(); r++)
       for(int c=0; c<board[0].size(); c++){
           if(r>-1 && c>-1 && r<board.size() && c<board[0].size() &&
           board[r][c]!=nullptr && board[r][c]->_player!=player &&
           board[r][c]->_points>maxpoints){
               row=r;
               col=c;
               maxpoints=board[r][c]->_points;
           } //inner fol loop
       } //outer for loop
       return {row,col};
   } //end of choose enemy function


    bool Sniper::act(std::vector<std::vector<Soldier*>> &board){
       std::pair<int, int>enemy = chooseEnemy(board);
       cout<<"enemy chosen is: "<<enemy.first<<", "<<enemy.second<<endl;
       if(enemy.first>-1 && enemy.second>-1){
       reduce(board[enemy.first][enemy.second]);
       return true;
       }
       return false;
   }



