#include "doctest.h"
#include "Board.hpp"
#include <string>
#include <string.h>
using namespace std;
#include <iostream>
#include <complex>
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include <cassert>
using namespace WarGame;


string nuller(Soldier* soldier){
  if (soldier==NULL)
  return "null";
  else return "soldier";
}



TEST_CASE(""){
   
   
  
  Board board(4,4);

  assert(!board.has_soldiers(1));

  board[{0,1}] = new FootSoldier(1);
  CHECK(to_string(board[{0,1}]->_points)==string("100"));
  board[{1,0}] = new FootSoldier(1);
  CHECK(to_string(board[{1,0}]->_points)==string("100"));
	board[{1,1}] = new FootCommander(1);
  CHECK(to_string(board[{1,1}]->_points)==string("150"));
  assert(board.has_soldiers(1));

  assert(!board.has_soldiers(2));
   
  board[{3,2}] = new FootSoldier(2);
  CHECK(to_string(board[{3,2}]->_points)==string("100"));
  board[{2,3}] = new FootSoldier(2);
  CHECK(to_string(board[{2,3}]->_points)==string("100"));
	board[{2,2}] = new FootCommander(2);
  CHECK(to_string(board[{2,2}]->_points)==string("150"));
  assert(board.has_soldiers(2));
  
  
  CHECK(nuller(board[{1,1}])=="soldier");
  CHECK(nuller(board[{0,1}])=="soldier");
  CHECK(nuller(board[{1,0}])=="soldier");
  CHECK(nuller(board[{3,2}])=="soldier");
  CHECK(nuller(board[{2,3}])=="soldier");
  CHECK(nuller(board[{2,2}])=="soldier");

  CHECK(nuller(board[{0,0}])=="null");
  CHECK(nuller(board[{2,0}])=="null");
  CHECK(nuller(board[{0,2}])=="null");
  CHECK(nuller(board[{0,3}])=="null");
  CHECK(nuller(board[{3,0}])=="null");
  CHECK(nuller(board[{1,2}])=="null");
  CHECK(nuller(board[{1,3}])=="null");
  CHECK(nuller(board[{2,1}])=="null");
  CHECK(nuller(board[{3,1}])=="null");
  CHECK(nuller(board[{0,0}])=="null");
  CHECK(nuller(board[{3,3}])=="null");
  
  board.move(1, {1,1}, Board::MoveDIR::Up);
  CHECK(nuller(board[{1,1}])=="null");
  CHECK(nuller(board[{2,1}])=="soldier");
  CHECK(to_string(board[{2,2}]->_points)==string("130"));

  board.move(2, {3,2}, Board::MoveDIR::Left);
  CHECK(to_string(board[{2,1}]->_points)==string("140"));

  board.move(2,{2,2}, Board::MoveDIR::Down);
  board.move(2,{1,2}, Board::MoveDIR::Down);
  CHECK(to_string(board[{2,1}]->_points)==string("130"));
  CHECK(to_string(board[{0,1}]->_points)==string("80"));
  

  cout<<"all good so far"<<endl;

	





}

  





/*
   
   double d=solve(2*x==2);
   string s=to_string(d);
   CHECK(s==string("1.0"));

   CHECK(to_string(solve(2*x==2))==string("1.0"));
   CHECK(to_string(solve(2*(x^2)==8))==string("2.0") || 
   to_string(solve(2*(x^2)==8))==string("-2.0"));

   */

