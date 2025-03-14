#include <iostream>
#include "sky.hpp"
using namespace std;

void SKY::set_coordinates() {
    int x, y;
    int res, temp;
    string color;

    while (true) {
        cout << "Please enter the star coordinates (X and Y)!!" << endl;
        cin >> x >> y;

        if (n.set_x(x) && n.set_y(y)) {
            cout << "Please enter the resolution and color:" << endl;
            cin >> res >> color;

            n.set_coordinates(x, y);
            n.set_reso_and_coler(res, color);
        } else {
            cout << "Please enter valid values! Valid X: 0-19, Valid Y: 0-9" << endl;
        }

        cout << "Do you want to continue? If yes, enter 1:" << endl;
        cin >> temp;

        if (temp != 1) {
            break;
        }
    }
}
