#include<iostream>
#include<exception>
#include"character.hpp"
using namespace std;

 CHARACTER::CHARACTER(){
    name="worker";
    health=100;
    power=0;
    skills=" ";
}
CHARACTER::CHARACTER(string name){
    this->name=name;
    cout<<"please enter the haelth level for "<<name<<endl;
    float health;
    cin>>health;
    try{
        set_health(health);
    }
    catch(invalid_argument &e){
        cout<<e.what()<<endl;
    }
    cout<<"please enter the power level for "<<name<<endl;
    int power;
    cin>>power;
    try{
        set_power(power);
    }
    catch(invalid_argument &e){
        cout<<e.what()<<endl;
    }
    cout<<"please enter the skill for "<<name<<endl;
    string skill;
    cin>>skill;
    skills=skill;
}
void CHARACTER::set_health(float h){
    if(h<=100 && h>=0){
        health=h;
    }
    else{
        throw invalid_argument("The amount given for health is encorrect ");
    }
    
}
void CHARACTER::set_power(int a){
    if(a<100 && a>0){
        power=a;
    }
    else{
        throw invalid_argument("The amount given for power is encorrect ");
    }
}
