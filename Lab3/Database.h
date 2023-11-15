#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <string>
#include "Car.h"
#include <fstream>
#include <sstream>

using namespace std;

const int MaxCars = 100;
const int FirstCarCode = 1;

class Database
{
public:
    Database();
    Car& AddCar(int BrandCode, int RegNum, int BodyNum, int EngineNum, string ReleaseDate, int Mileage,
                int DriverCode, string Maintenance, int MechanicCode, string Specials);
    Car& GetCar(int CarCode);
    int GetQuantity();
    std::string DisplayAll();
    std::string DisplayCurrent();
    std::string DisplayFormer();
    void WriteToFile(const std::string& FileName);
    void ReadFromFile(const std::string& FileName);
protected:
    Car CarsDatabase[MaxCars];
    int NextSlot;
    int NextCarCode;
};

#endif // DATABASE_H
