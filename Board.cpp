//#pragma once

#include <string>
#include <vector>
#include <stdexcept>
#include "Board.hpp"
#include "Soldier.hpp"
#include <time.h>
#include <iostream>

using namespace std;

namespace WarGame{


    Soldier*& Board::operator[](std::pair<int,int> location){
        if(location.first<0 || location.first>board.size() ||
        location.second<0 || location.second>board[0].size())
        throw "out of bounds";
        //Soldier* soldier;
        //board[location.first][location.second]=soldier;
        return board[location.first][location.second];
    }
    
    
    Soldier* Board::operator[](std::pair<int,int> location) const{
        if(location.first<0 || location.first>board.size() ||
        location.second<0 || location.second>board[0].size())
        throw "out of bounds";
        return board[location.first][location.second];
    }



    void Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction){

        cout<<"start of move"<<endl;
   
        if(source.first<0 || source.first>=board.size() ||
        source.second<0 || source.second>=board[0].size())
        throw "out of bounds";


        std::pair<int,int> location;
        location.first=source.first;
        location.second=source.second;
        //cout<<"location's row is: "<<location.first<<", location's column is: "<<location.second<<endl;
        if(direction==Up){
            location.first=source.first+1;
            //cout<<"direction is Up"<<endl;
        }
        else if(direction==Down){
            location.first=source.first-1;
            //cout<<"direction is Down"<<endl;
        }
        else if(direction==Right){
            location.second=source.second+1;
            //cout<<"direction is Right"<<endl;
        }
        else if(direction==Left){
            location.second=source.second-1;
            //cout<<"direction is Left"<<endl;
        }

        if(location.first<0 || location.first>=board.size() ||
        location.second<0 || location.second>=board[0].size())
        throw "out of bounds";

        

        int f=location.first;
        int s=location.second;
        Soldier* temp;
        temp=this->board[source.first][source.second];
        //cout<<board[f][s]->_player<<endl;
        if(temp==nullptr){ 
            cout<<"temp==nullptr"<<endl;
            throw "source is null";
        }

        if(temp->_player!=player_number)
        throw "wrong player";

        board[f][s]=temp;
        board[source.first][source.second]=nullptr;
        board[f][s]->setLocation(f,s);
        
        temp->act(board);

        cout<<""<<endl;
        for(int i=board.size()-1; i>-1; i--){
        for(int j=0; j<board[0].size(); j++){
            if(board[i][j]==nullptr)
            cout<<"{"<<i<<","<<j<<"}: null soldier  ";
            else
            cout<<"{"<<i<<","<<j<<"}, points: "<<board[i][j]->_points<<"  ";
        }
        cout<<""<<endl;
        }
        cout<<""<<endl;

    }

    
    bool Board::has_soldiers(uint player_number) const{
        bool hasSoldiers=false;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                Soldier* sol = this->board[i][j];
                if(sol!=nullptr && sol->_player==player_number){
                    hasSoldiers=true;
                    break;
                }
            }
        }
        return hasSoldiers;
    }

    string nuller (Soldier* soldier){
        if(soldier==NULL)
        return "";
        else return " ";
    }


}