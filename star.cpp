#include<iostream>
#include"star.hpp"
using namespace std;

STAR::STAR(){
    for(int i=0 ;i<20;++i ){
        for(int j=0 ;j<10 ;++j ){
            sky[i][j]=' ';
        }
    }
}
bool STAR::set_x(int x){
    if(x>=0 && x<20){
        return true;
    }
    else{
        return false;
    }
}
bool STAR::set_y(int y){
    if(y>=0 && y<10){
        return true;
    }
    else{
        return false;
    }
}
void STAR::set_reso_and_coler(int res ,string coler){
    this->coler=coler;
    this->reso =res;
}
void STAR::set_coordinates(int x , int y){
    sky[x][y]='*';
}
void STAR::get_coordinates(){
    for(int i=0 ;i<20;++i ){
        for(int j=0 ;j<10 ;++j ){
            cout<<sky[i][j];
        }
        cout<<endl;
    }
}
STAR::~STAR(){
    get_coordinates();
}



