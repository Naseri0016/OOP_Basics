#ifndef PATIENT_HPP
#define PATIENT_HPP

#include <string>
#include <vector>

class PATIENT {
public:
    static std::string filename;
    static std::vector<PATIENT> patients;

    // سازنده‌ها
    PATIENT();
    PATIENT(std::string name, float bloodPressure, float heartRate, float respiratoryRate, float bodytemp);
    ~PATIENT();

    // تابع‌های تنظیم مقادیر
    void set_Body_Temperature(float temper);
    void set_heart_rate(float a);
    void set_blood_per(float a);
    void set_Respiratory_Rate(float a); 

  
    static std::string xorEncryptDecrypt(const std::string& data);

 
    static void savePatientsToFile();
    static void loadPatientsFromFile();
    static void made(int count);

   
    std::string getName() const { return name; }
    float getBloodper() const { return bloodper; }
    float getHaertra() const { return haertra; }
    float getResra() const { return resra; }
    float getBodytemp() const { return bodytemp; }

private:
    std::string name;
    float bloodper;
    float haertra;
    float resra;
    float bodytemp;
};

#endif 
