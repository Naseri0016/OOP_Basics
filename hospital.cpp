#include <iostream>
#include "hospital.hpp"
#include "patient.hpp"
using namespace std;

HOSPITAL::HOSPITAL(string name) {
    this->name = name;
    string command;

    cout << "If you want to see patient information, enter 'see more', and if you want to add a patient, enter 'add'" << endl;
    cin >> command;

    if (command == "add") {
        cout << "How many patients do you have?" << endl;
        int count;
        cin>>count;
        PATIENT::made(count);
    } else if (command == "see") {
        cout << "Loading patients from file..." << endl;
        PATIENT::loadPatientsFromFile();

    }
}
