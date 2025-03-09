#include<iostream>
#include "gps.hpp"
using namespace std;

Gps::Gps() {
    std::cout << "How many coordinates do you want to enter?" << std::endl;
    std::cin >> a;
    ptr = new int*[a];
    for (int i = 0; i < a; i++) {
        ptr[i] = new int[2];
    }
    int x, y;
    for (int i = 0; i < a; i++) {
        cout << "Please enter the coordinates" << endl;
        cout << "<";
        cin >> x >> y;
        if (x > -180 && x < 180 && y > -90 && y < 90) {
            ptr[i][0] = x;
            ptr[i][1] = y;
        }
    }
}

Gps::~Gps() {
    std::cout << "Last coordinates: " << ptr[a-1][0] << " " << ptr[a-1][1] << std::endl;
    for (int i = 0; i < a; ++i) {
        delete[] ptr[i];
    }
    delete[] ptr;
}
