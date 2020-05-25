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

        //cout<<"start of move"<<endl;
   
        if(source.first<0 || source.first>board.size() ||
        source.second<0 || source.second>board[0].size())
        throw "out of bounds";


        int f=source.first;
        int s=source.second;
        Soldier* temp;
        temp=this->board[f][s];
        //cout<<board[f][s]->_player<<endl;
        if(temp==nullptr ||
         this->board[f][s]->_player!=player_number){ 
            throw "wrong player";
        }


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

        if(location.first<0 || location.first>board.size() ||
        location.second<0 || location.second>board[0].size())
        throw "out of bounds";
        //cout<<"location's row is: "<<location.first<<", location's column is: "<<location.second<<endl;
        Soldier* soldier = this->board[location.first][location.second];
        //cout<<"before soldier==null"<<endl;
        if(soldier!=NULL)
        throw "soldier there";


        this->board[location.first][location.second]=this->board[source.first][source.second];
        this->board[source.first][source.second]=NULL;

        
        int other_player;
        if(player_number==1)
        other_player=2;
        else
        {
            other_player=1;
        }
        

        int dir;
        srand(time(NULL));
       
        std::pair<int,int> place;

        bool chosen=false;

        bool one=false;
        bool two=false;
        bool three=false;
        bool four=false;

        bool allChosen=false;


        while(chosen==false && allChosen==false){
        
        dir=(rand() % 4) + 1;
        
        if(dir==1)
        one=true;
        else if(dir==2)
        two=true;
        else if(dir==3)
        three=true;
        else if(dir==4)
        four=true;
    

        //cout<<"dir is: "<<dir<<endl;
        //cout<<"before dir==1"<<endl;

        if(dir==1 && location.first+1<board.size() && 
        this->board[location.first+1][location.second]!=nullptr && 
        this->board[location.first+1][location.second]->_player==other_player)
        {
            place.first=location.first+1;
            place.second=location.second;
            this->board[location.first][location.second]->act(this->board[place.first][place.second]);
            if(this->board[place.first][place.second]->_points<=0){
                this->board[place.first][place.second]=nullptr; 
            }
            chosen=true;
            cout<<"atacking upward"<<endl;
        }


        else if(dir==2 && location.first-1<board.size() && 
        this->board[location.first-1][location.second]!=nullptr && 
        this->board[location.first-1][location.second]->_player==other_player)
        {
            place.first=location.first-1;
            place.second=location.second;
            this->board[location.first][location.second]->act(this->board[place.first][place.second]);
              if(this->board[place.first][place.second]->_points<=0){
                this->board[place.first][place.second]=nullptr; 
            }
            chosen=true;
            cout<<"atacking downward"<<endl;
        }


        else if(dir==3 && location.second+1<board[0].size() && 
        this->board[location.first][location.second+1]!=nullptr && 
        //this[{location.first, location.second+1}]->_player==other_player)
        this->board[location.first][location.second+1]->_player==other_player)
        {
            place.first=location.first;
            place.second=location.second+1;
            this->board[location.first][location.second]->act(this->board[place.first][place.second]);
            if(this->board[place.first][place.second]->_points<=0){
                this->board[place.first][place.second]=nullptr; 
            }
            chosen=true;
            cout<<"atacking to the right"<<endl;
        }


        else if(dir==4 && location.second-1<board[0].size() && 
        this->board[location.first][location.second-1]!=nullptr && 
        this->board[location.first][location.second-1]->_player==other_player)
        {
            place.first=location.first;
            place.second=location.second-1;
            this->board[location.first][location.second]->act(this->board[place.first][place.second]);
            if(this->board[place.first][place.second]->_points<=0){
                this->board[place.first][place.second]=nullptr; 
            }
            chosen=true;
            cout<<"atacking to the left"<<endl;
        }


        if(one && two && three && four)
        allChosen=true;

        //dir=(rand() % 4) + 1;

        
        }

        //cout<<"before soldier = this->board[location.first][location.second];"<<endl;

        soldier = this->board[location.first][location.second];

        //cout<<"after soldier = this->board[location.first][location.second];"<<endl;

        if(soldier!=NULL && (soldier->_soltype==Soldier::soltype::footcom ||
        soldier->_soltype==Soldier::soltype::paracom || 
        soldier->_soltype==Soldier::soltype::snipercom)){
            //cout<<"soldier->_soltype==Soldier::soltype::footcom"<<endl;

            for(int i=0; i<board.size(); i++)
            for(int j=0; j<board[0].size(); j++){
                location.first=i;
                location.second=j;
                if(this->board[location.first][location.second]!=nullptr && 
                this->board[location.first][location.second]->_player==player_number &&
                (
                    (soldier->_soltype==Soldier::soltype::footcom && 
                board[i][j]->_soltype==Soldier::soltype::footer) ||
                    (soldier->_soltype==Soldier::soltype::snipercom && 
                board[i][j]->_soltype==Soldier::soltype::sniper) ||
                    (soldier->_soltype==Soldier::soltype::paracom && 
                board[i][j]->_soltype==Soldier::soltype::paramedic) 
                )
                ){




        chosen=false;

        

        bool one=false;
        bool two=false;
        bool three=false;
        bool four=false;

        allChosen=false;

        

        while(chosen==false && allChosen==false){

        dir=(rand() % 4) + 1;
        
        if(dir==1)
        one=true;
        else if(dir==2)
        two=true;
        else if(dir==3)
        three=true;
        else if(dir==4)
        four=true;



        dir=rand() % 4 + 1;

        if(dir==1 && location.first+1<board.size() && 
        this->board[location.first+1][location.second]!=nullptr && 
        this->board[location.first+1][location.second]->_player==other_player)
        {
            place.first=location.first+1;
            place.second=location.second;
            this->board[location.first][location.second]->act(this->board[place.first][place.second]);
            if(this->board[place.first][place.second]->_points<=0){
                this->board[place.first][place.second]=nullptr; 
            }
            chosen=true;
            cout<<"private attacking upward"<<endl;
        }


        if(dir==2 && location.first-1<board.size() && 
        this->board[location.first-1][location.second]!=nullptr && 
        this->board[location.first-1][location.second]->_player==other_player)
        {
            place.first=location.first-1;
            place.second=location.second;
            this->board[location.first][location.second]->act(this->board[place.first][place.second]);
            if(this->board[place.first][place.second]->_points<=0){
                this->board[place.first][place.second]=nullptr; 
            }
            chosen=true;
            cout<<"private attacking downward"<<endl;
        }


        else if(dir==3 && location.second+1<board[0].size() && 
        this->board[location.first][location.second+1]!=nullptr && 
        this->board[location.first][location.second+1]->_player==other_player)
        {
            place.first=location.first;
            place.second=location.second+1;
            this->board[location.first][location.second]->act(this->board[place.first][place.second]);
            if(this->board[place.first][place.second]->_points<=0){
                this->board[place.first][place.second]=nullptr; 
            }
            chosen=true;
            cout<<"private atacking to the right"<<endl;
        }


        else if(dir==4 && location.second-1<board[0].size() && 
        this->board[location.first][location.second-1]!=nullptr && 
        this->board[location.first][location.second-1]->_player==other_player)
        {
            place.first=location.first;
            place.second=location.second-1;
            this->board[location.first][location.second]->act(this->board[place.first][place.second]);
            if(this->board[place.first][place.second]->_points<=0){
                this->board[place.first][place.second]=nullptr; 
            }
            chosen=true;
            cout<<"private atacking to the left"<<endl;
        }


        if(one && two && three && four)
        allChosen=true;

        dir=(rand() % 4) + 1;

        
        }




                }
            }

        }

        cout<<"end of move"<<endl;



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