#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include<iostream>
class CHARACTER{ 
    std::string name;
    std::string skills;
    float health;
    int power;
    public:
    CHARACTER();//برای افراد معمولی بازی
    CHARACTER(std::string name);
    void set_health(float);
    void set_power(int);
};
#endif