#pragma once
#include <iostream>
using namespace std;
   
    class Soldier{

        public:
        enum soltype {soldier, footcom, footer, 
        sniper, snipercom, paramedic, paracom};

        
        public:
        int _player;
        soltype _soltype;
        int _points;
        int _row, _col;

        public:
        Soldier(){}

        Soldier(int player){
            _player=player;
            _soltype=soldier;
            _row=-1;
            _col=-1;
        }

        public:

        void setLocation(int r, int c){
            _row=r;
            _col=c;
        }

        virtual bool act(std::vector<std::vector<Soldier*>> &board){
            cout<<"virtual bool act()"<<endl;
            return false;};

        virtual void reduce(Soldier* &soldier){};

        virtual void recover(){};

        
    };
