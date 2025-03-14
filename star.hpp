#ifndef STAR_HPP
#define STAR_HPP
#include<iostream>
class STAR{
    private:
    std::string coler;
    int x;
    int y;
    int reso ;
    char sky[20][10];
    public:
    STAR();
    bool set_x(int);
    bool set_y(int);
    void set_reso_and_coler(int , std::string);
    void set_coordinates(int , int);
    void get_coordinates();
    ~STAR();
};
#endif