#include "doctest.h"
#include "Board.hpp"
#include <string>
#include <string.h>
using namespace std;
#include <iostream>
#include <complex>
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"
#include <cassert>
using namespace WarGame;


string nuller(Soldier* soldier){
  if (soldier==NULL)
  return "null";
  else return "soldier";
}

string booler(bool b){
  if(b)
  return "true";
  else
  {
    return "false";
  }
}



TEST_CASE("3 by 3"){

  Board board(3,3);

  assert(!board.has_soldiers(1));

  board[{0,1}]=new Sniper(1);
  board[{0,0}]=new SniperCommander(1);
  assert(board.has_soldiers(1));

  assert(!board.has_soldiers(2));

  board[{2,1}]=new Paramedic(2);
  board[{2,2}]=new ParamedicCommander(2);
  board[{1,2}]=new FootCommander(2);
  board[{1,1}]=new FootSoldier(2);
  assert(board.has_soldiers(2));
  
  CHECK(nuller(board[{0,0}])=="soldier");
  CHECK(nuller(board[{0,1}])=="soldier");
  CHECK(nuller(board[{2,1}])=="soldier");
  CHECK(nuller(board[{2,2}])=="soldier");
  CHECK(nuller(board[{1,2}])=="soldier");
  CHECK(nuller(board[{1,1}])=="soldier");

  CHECK(nuller(board[{0,2}])=="null");
  CHECK(nuller(board[{1,0}])=="null");
  CHECK(nuller(board[{2,0}])=="null");

  board.move(2,{1,1},Board::MoveDIR::Left);
  //CHECK(to_string(board[{0,0}]->_points)==string("110"));
  CHECK(nuller(board[{1,1}])=="null");
  CHECK(nuller(board[{1,0}])=="soldier");

  board.move(1,{0,1},Board::MoveDIR::Right);
  //CHECK(to_string(board[{2,2}]->_points)==string("150"));
  CHECK(nuller(board[{0,1}])=="null");
  CHECK(nuller(board[{0,2}])=="soldier");

  board.move(1,{0,0},Board::MoveDIR::Right);
  //CHECK(to_string(board[{1,2}]->_points)==string("50"));
  //CHECK(to_string(board[{2,2}]->_points)==string("100"));
  CHECK(nuller(board[{0,0}])=="null");
  CHECK(nuller(board[{0,1}])=="soldier");

  board.move(2,{1,0},Board::MoveDIR::Right);
  //CHECK(to_string(board[{0,1}]->_points)==string("100"));
  CHECK(nuller(board[{1,0}])=="null");
  CHECK(nuller(board[{1,1}])=="soldier");

  board.move(1,{0,1},Board::MoveDIR::Left);
  //CHECK(to_string(board[{2,1}]->_points)==string("50"));
  CHECK(nuller(board[{0,1}])=="null");
  CHECK(nuller(board[{0,0}])=="soldier");
  CHECK(nuller(board[{1,1}])=="null");

  board.move(2,{2,1},Board::MoveDIR::Down);
  //CHECK(to_string(board[{1,2}]->_points)==string("150"));
  CHECK(nuller(board[{2,1}])=="null");
  CHECK(nuller(board[{1,1}])=="soldier");

  board.move(2,{2,2},Board::MoveDIR::Left);
  //CHECK(to_string(board[{1,1}]->_points)==string("100"));
  //CHECK(to_string(board[{2,1}]->_points)==string("200"));
  CHECK(nuller(board[{2,2}])=="null");
  CHECK(nuller(board[{2,1}])=="soldier");

  board.move(1,{0,0},Board::MoveDIR::Up);
  //CHECK(to_string(board[{2,1}]->_points)==string("100"));
  //CHECK(to_string(board[{1,2}]->_points)==string("100"));
  CHECK(nuller(board[{0,0}])=="null");
  CHECK(nuller(board[{1,0}])=="soldier");

  board.move(2,{1,1},Board::MoveDIR::Down);
  CHECK(nuller(board[{1,1}])=="null");
  CHECK(nuller(board[{0,1}])=="soldier");

  board.move(2,{1,2},Board::MoveDIR::Left);
  //CHECK(to_string(board[{1,0}]->_points)==string("80"));
  CHECK(nuller(board[{1,2}])=="null");
  CHECK(nuller(board[{1,1}])=="soldier");

  board.move(1,{1,0},Board::MoveDIR::Up);
  //CHECK(to_string(board[{1,1}]->_points)==string("50"));
  //CHECK(to_string(board[{2,1}]->_points)==string("100"));
  CHECK(nuller(board[{1,0}])=="null");
  CHECK(nuller(board[{2,0}])=="soldier");
  CHECK(nuller(board[{0,1}])=="null");

  //CHECK(to_string(board[{2,0}]->_points)==string("80"));

  board.move(2,{1,1},Board::MoveDIR::Left);
  //CHECK(to_string(board[{2,0}]->_points)==string("60"));
  CHECK(nuller(board[{1,1}])=="null");
  CHECK(nuller(board[{1,0}])=="soldier");

  board.move(2,{1,0},Board::MoveDIR::Right);
  CHECK(nuller(board[{1,0}])=="null");
  CHECK(nuller(board[{1,1}])=="soldier");

  board.move(2,{1,1},Board::MoveDIR::Left);
  //CHECK(to_string(board[{2,0}]->_points)==string("40"));
  CHECK(nuller(board[{1,1}])=="null");
  CHECK(nuller(board[{1,0}])=="soldier");

  board.move(2,{1,0},Board::MoveDIR::Right);
  CHECK(nuller(board[{1,0}])=="null");
  CHECK(nuller(board[{1,1}])=="soldier");

  board.move(2,{1,1},Board::MoveDIR::Left);
  //CHECK(to_string(board[{2,0}]->_points)==string("20"));
  CHECK(nuller(board[{1,1}])=="null");
  CHECK(nuller(board[{1,0}])=="soldier");

  board.move(2,{1,0},Board::MoveDIR::Right);
  CHECK(nuller(board[{1,0}])=="null");
  CHECK(nuller(board[{1,1}])=="soldier");

  board.move(2,{1,1},Board::MoveDIR::Left);
  CHECK(nuller(board[{1,1}])=="null");
  CHECK(nuller(board[{1,0}])=="soldier");

  board.move(2,{1,0},Board::MoveDIR::Right);
  CHECK(nuller(board[{1,0}])=="null");
  CHECK(nuller(board[{1,1}])=="soldier");
  CHECK(nuller(board[{2,0}])=="null");

  board.move(2,{2,1},Board::MoveDIR::Right);
  CHECK(nuller(board[{2,1}])=="null");
  CHECK(nuller(board[{2,2}])=="soldier");
  
  board.move(2,{2,2},Board::MoveDIR::Left);
  //CHECK(to_string(board[{1,1}]->_points)==string("150"));
  CHECK(nuller(board[{2,2}])=="null");
  CHECK(nuller(board[{2,1}])=="soldier");

  board.move(1,{0,2},Board::MoveDIR::Left);
  //CHECK(to_string(board[{1,1}]->_points)==string("100"));
  CHECK(nuller(board[{0,2}])=="null");
  CHECK(nuller(board[{0,1}])=="soldier");

  board.move(1,{0,1},Board::MoveDIR::Left);
  //CHECK(to_string(board[{1,1}]->_points)==string("50"));
  CHECK(nuller(board[{0,1}])=="null");
  CHECK(nuller(board[{0,0}])=="soldier");

  board.move(2,{1,1},Board::MoveDIR::Right);
  CHECK(nuller(board[{1,1}])=="null");
  CHECK(nuller(board[{1,2}])=="soldier");

  board.move(2,{1,2},Board::MoveDIR::Left);
  CHECK(nuller(board[{1,2}])=="null");
  CHECK(nuller(board[{1,1}])=="soldier");

  board.move(2,{2,1},Board::MoveDIR::Left);
  CHECK(nuller(board[{2,1}])=="null");
  CHECK(nuller(board[{2,0}])=="soldier");

  board.move(2,{2,0},Board::MoveDIR::Down);
  CHECK(nuller(board[{2,0}])=="null");
  CHECK(nuller(board[{1,0}])=="soldier");

  //cout<<"paramedic's points are: "<<board[{1,0}]->_points<<endl;
  //cout<<"foot commander's points are: "<<board[{1,1}]->_points<<endl;

  board.move(1,{0,0},Board::MoveDIR::Right);
  CHECK(nuller(board[{0,0}])=="null");
  CHECK(nuller(board[{0,1}])=="soldier");

  //cout<<"sniper's points are: "<<board[{0,1}]->_points<<endl;

  board.move(1,{0,1},Board::MoveDIR::Right);
  //CHECK(to_string(board[{1,1}]->_points)==string("100"));
  CHECK(nuller(board[{0,1}])=="null");
  CHECK(nuller(board[{0,2}])=="soldier");

  board.move(1,{0,2},Board::MoveDIR::Left);
  //CHECK(to_string(board[{1,0}]->_points)==string("50"));
  CHECK(nuller(board[{0,2}])=="null");
  CHECK(nuller(board[{0,1}])=="soldier");

  board.move(1,{0,1},Board::MoveDIR::Left);
  //CHECK(to_string(board[{1,1}]->_points)==string("50"));
  CHECK(nuller(board[{0,1}])=="null");
  CHECK(nuller(board[{0,0}])=="soldier");

  board.move(1,{0,0},Board::MoveDIR::Right);
  CHECK(nuller(board[{1,0}])=="null");
  CHECK(nuller(board[{0,0}])=="null");
  CHECK(nuller(board[{0,1}])=="soldier");

  CHECK(booler(board.has_soldiers(2))=="false");
  CHECK(booler(board.has_soldiers(1))=="true");

}





TEST_CASE("2 by 2"){

  Board board(2,2);

  assert(!board.has_soldiers(1));

  board[{0,1}]=new FootCommander(1);
  board[{0,0}]=new FootCommander(1);
  assert(board.has_soldiers(1));

  assert(!board.has_soldiers(2));

  board[{1,1}]=new Sniper(2);
  
  assert(board.has_soldiers(2));
  
  CHECK(nuller(board[{0,0}])=="soldier");
  CHECK(nuller(board[{0,1}])=="soldier");
  CHECK(nuller(board[{1,1}])=="soldier");

  CHECK(nuller(board[{1,0}])=="null");
 
  board.move(2,{1,1},Board::MoveDIR::Left);
  //CHECK(to_string(board[{0,0}]->_points)==string("100"));
  CHECK(nuller(board[{1,0}])=="soldier");
  CHECK(nuller(board[{1,1}])=="null");

  board.move(2,{1,0},Board::MoveDIR::Right);
  //CHECK(to_string(board[{0,1}]->_points)==string("100"));
  CHECK(nuller(board[{1,1}])=="soldier");
  CHECK(nuller(board[{1,0}])=="null");

  board.move(2,{1,1},Board::MoveDIR::Left);
  //CHECK(to_string(board[{0,0}]->_points)==string("50"));
  CHECK(nuller(board[{1,0}])=="soldier");
  CHECK(nuller(board[{1,1}])=="null");

  board.move(2,{1,0},Board::MoveDIR::Right);
  //CHECK(to_string(board[{0,1}]->_points)==string("50"));
  CHECK(nuller(board[{1,1}])=="soldier");
  CHECK(nuller(board[{1,0}])=="null");


  board.move(1,{0,0},Board::MoveDIR::Up);
  //CHECK(to_string(board[{1,1}]->_points)==string("80"));
  CHECK(nuller(board[{1,0}])=="soldier");
  CHECK(nuller(board[{0,0}])=="null");


  board.move(1,{0,1},Board::MoveDIR::Left);
  CHECK(nuller(board[{0,0}])=="soldier");
  CHECK(nuller(board[{0,1}])=="null");

  board.move(1,{0,0},Board::MoveDIR::Right);
  //CHECK(to_string(board[{1,1}]->_points)==string("60"));
  CHECK(nuller(board[{0,1}])=="soldier");
  CHECK(nuller(board[{0,0}])=="null");

  board.move(1,{0,1},Board::MoveDIR::Left);
  CHECK(nuller(board[{0,0}])=="soldier");
  CHECK(nuller(board[{0,1}])=="null");

  board.move(1,{0,0},Board::MoveDIR::Right);
  //CHECK(to_string(board[{1,1}]->_points)==string("40"));
  CHECK(nuller(board[{0,1}])=="soldier");
  CHECK(nuller(board[{0,0}])=="null");

  board.move(1,{1,0},Board::MoveDIR::Down);
  CHECK(nuller(board[{0,0}])=="soldier");
  CHECK(nuller(board[{1,0}])=="null");

  board.move(2,{1,1},Board::MoveDIR::Left);
  CHECK(nuller(board[{1,0}])=="soldier");
  CHECK(nuller(board[{1,1}])=="null");
  CHECK(nuller(board[{0,0}])=="null");

  board.move(1,{0,1},Board::MoveDIR::Up);
  //CHECK(to_string(board[{1,0}]->_points)==string("20"));
  CHECK(nuller(board[{1,1}])=="soldier");
  CHECK(nuller(board[{0,1}])=="null");

  board.move(2,{1,0},Board::MoveDIR::Down);
  CHECK(nuller(board[{0,0}])=="soldier");
  CHECK(nuller(board[{1,0}])=="null");

  CHECK(booler(board.has_soldiers(1))=="false");
  CHECK(booler(board.has_soldiers(2))=="true");
 
}