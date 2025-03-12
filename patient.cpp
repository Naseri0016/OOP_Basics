#include <iostream>
#include <exception>
#include <fstream>
#include <vector>
#include <string>
#include "patient.hpp"
using namespace std;

string PATIENT::filename = "patients.txt";
vector<PATIENT> PATIENT::patients; 
string PATIENT::xorEncryptDecrypt(const std::string& data) {
    char key = 'X'; 
    std::string result = data;
    for (size_t i = 0; i < data.size(); ++i) {
        result[i] ^= key;
    }
    return result;
}

PATIENT::PATIENT() {
    float temp;
    cout << "Please enter the patient name" << endl;
    string name;
    cin >> name;
    this->name = name;

    cout << "Please enter the patient blood pressure" << endl;
    cin >> temp;
    try {
        set_blood_per(temp);
    }
    catch (invalid_argument& e) {
        cout << e.what() << endl;
    }

    cout << "Please enter the patient heart rate" << endl;
    cin >> temp;
    try {
        set_heart_rate(temp);
    }
    catch (invalid_argument& e) {
        cout << e.what() << endl;
    }

    cout << "Please enter the patient temperature" << endl;
    cin >> temp;
    try {
        set_Body_Temperature(temp);
    }
    catch (invalid_argument& e) {
        cout << e.what() << endl;
    }

    cout << "Please enter the patient Respiratory Rate" << endl;
    cin >> temp;
    try {
        set_Respiratory_Rate(temp);
    }
    catch (invalid_argument& e) {
        cout << e.what() << endl;
    }
}

PATIENT::PATIENT(string name, float bloodPressure, float heartRate, float respiratoryRate, float bodytemp)
    : name(name), bloodper(bloodPressure), haertra(heartRate), resra(respiratoryRate), bodytemp(bodytemp) {
}

void PATIENT::set_Body_Temperature(float temper) {
    if (temper >= 36.0 && temper <= 37.5) {
        bodytemp = temper;
    } else {
        throw invalid_argument("The given temperature is invalid");
    }
}

void PATIENT::set_heart_rate(float a) {
    if (a >= 60 && a <= 100) {
        haertra = a;
    } else {
        throw invalid_argument("The given heart rate is invalid");
    }
}

void PATIENT::set_blood_per(float a) {
    if (a >= 80 && a <= 120) {
        bloodper = a;
    } else {
        throw invalid_argument("The given blood pressure is invalid");
    }
}

void PATIENT::set_Respiratory_Rate(float a) {
    if (a >= 12 && a <= 25) {
        resra = a;
    } else {
        throw invalid_argument("The given respiratory rate is invalid");
    }
}

PATIENT::~PATIENT() {
}

void PATIENT::savePatientsToFile() {
    ofstream file(filename, ios_base::app);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    for (const auto& p : patients) {
        if (file.is_open()) {
            string encryptedData = xorEncryptDecrypt(p.getName()) + " "
                 + xorEncryptDecrypt(to_string(p.getBloodper())) + " "
                 + xorEncryptDecrypt(to_string(p.getHaertra())) + " "
                 + xorEncryptDecrypt(to_string(p.getResra())) + " "
                 + xorEncryptDecrypt(to_string(p.getBodytemp()));
            file << encryptedData << endl;
        } else {
            cerr << "Error: File not open" << endl;
        }
    }
    
    patients.clear();
    file.close();
}

void PATIENT::loadPatientsFromFile() {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string name, encryptedName;
    float bloodPressure, heartRate, respiratoryRate, bodytemp;
    string encryptedBloodPressure, encryptedHeartRate, encryptedRespiratoryRate, encryptedBodytemp;

    while (file >> encryptedName >> encryptedBloodPressure >> encryptedHeartRate >> encryptedRespiratoryRate >> encryptedBodytemp) {
        name = xorEncryptDecrypt(encryptedName);
        bloodPressure = stof(xorEncryptDecrypt(encryptedBloodPressure));
        heartRate = stof(xorEncryptDecrypt(encryptedHeartRate));
        respiratoryRate = stof(xorEncryptDecrypt(encryptedRespiratoryRate));
        bodytemp = stof(xorEncryptDecrypt(encryptedBodytemp));

        patients.push_back(PATIENT(name, bloodPressure, heartRate, respiratoryRate, bodytemp));
    }

    for (const auto& p : patients) {
        cout << "Patient Name: " << p.getName() << endl;
        cout << "Blood Pressure: " << p.getBloodper() << endl;
        cout << "Heart Rate: " << p.getHaertra() << endl;
        cout << "Respiratory Rate: " << p.getResra() << endl;
        cout << "Body Temperature: " << p.getBodytemp() << endl;
        cout << "---------------------------" << endl;
    }

    file.close();
}

void PATIENT::made(int count) {
    for (int i = 0; i < count; ++i) {
        patients.push_back(PATIENT());
    }
    // ذخیره بیماران به فایل بعد از ساخت آنها
    savePatientsToFile();
}
