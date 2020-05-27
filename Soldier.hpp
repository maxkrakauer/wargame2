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

        public:
        Soldier(){}

        Soldier(int player){
            _player=player;
            _soltype=soldier;
        }

        public:

        virtual bool act(Soldier* soldier){
            cout<<"virtual bool act(Soldier* soldier)"<<endl;
            return false;};

        virtual void reduce(Soldier* soldier){};

        virtual void recover(){};

        

       
    };
