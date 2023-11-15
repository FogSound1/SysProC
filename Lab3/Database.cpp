#include <iostream>
#include <stdexcept>
#include <string>
#include "Database.h"
using namespace std;

Database::Database()
{
    NextSlot = 0;
    NextCarCode = FirstCarCode;
}

Car& Database::AddCar(int BrandCode, int RegNum, int BodyNum, int EngineNum, string ReleaseDate, int Mileage, int DriverCode, string Maintenance, int MechanicCode, string Specials)
{
    if (NextSlot >= MaxCars)
    {
        cerr << "There is no more room to add the new Car!" << endl;
        throw exception();
    }
    Car& car = CarsDatabase[NextSlot++];
    car.SetBrandCode(BrandCode);
    car.SetRegNum(RegNum);
    car.SetBodyNum(BodyNum);
    car.SetEngineNum(EngineNum);
    car.SetReleaseDate(ReleaseDate);
    car.SetMileage(Mileage);
    car.SetDriverCode(DriverCode);
    car.SetMaintenance(Maintenance);
    car.SetMechanicCode(MechanicCode);
    car.SetSpecials(Specials);
    car.SetCarCode(NextCarCode++);
    car.Enable();

    return car;
}

Car& Database::GetCar(int CarCode)
{
    for (int i = 0; i < NextSlot; i++)
    {
        if (CarsDatabase[i].GetCarCode() == CarCode)
        {
            return CarsDatabase[i];
        }
    }
    cerr << "No car with this car code " << CarCode << endl;
    throw exception();
}

int Database::GetQuantity()
{
    return NextCarCode - 1;
}

std::string Database::DisplayAll()
{
    std::string Temp = "";
    for (int i = 0; i < NextSlot; i++)
    {
        Temp += "Car's code: " + std::to_string(CarsDatabase[i].GetCarCode()) + "\n"
            + "Car's brand code: " + std::to_string(CarsDatabase[i].GetBrandCode()) + "\n"
                    + "Car's registration number: " + std::to_string(CarsDatabase[i].GetRegNum()) + "\n"
                    + "Car's body number: " + std::to_string(CarsDatabase[i].GetBodyNum()) + "\n"
                    + "Car's engine numebr: " + std::to_string(CarsDatabase[i].GetEngineNum()) + "\n"
                    + "Car's release date: " + CarsDatabase[i].GetReleaseDate() + "\n"
                    + "Car's mileage: " + std::to_string(CarsDatabase[i].GetMileage()) + "\n"
                    + "Car's driver code: " + std::to_string(CarsDatabase[i].GetDriverCode()) + "\n"
                    + "Car's last maintenance date: " + CarsDatabase[i].GetMaintenance() + "\n"
                    + "Car's mechanic code: " + std::to_string(CarsDatabase[i].GetMechanicCode())+ "\n"
                    + "Car's specials: " + CarsDatabase[i].GetSpecials() + "\n"
                    + (CarsDatabase[i].GetStatus() ? "Current car" : "Former car") + "\n"
                    + "Car's quality: " + std::to_string(CarsDatabase[i].GetCarQuality()) +"\n\n\n\n";
    }
    return Temp;
}

std::string Database::DisplayCurrent()
{
    std::string Temp = "";
    for (int i = 0; i < NextSlot; i++)
    {
        if (CarsDatabase[i].GetStatus())
        {
            Temp += "Car's code: " + std::to_string(CarsDatabase[i].GetCarCode()) + "\n"
                    + "Car's brand code: " + std::to_string(CarsDatabase[i].GetBrandCode()) + "\n"
                    + "Car's registration number: " + std::to_string(CarsDatabase[i].GetRegNum()) + "\n"
                    + "Car's body number: " + std::to_string(CarsDatabase[i].GetBodyNum()) + "\n"
                    + "Car's engine numebr: " + std::to_string(CarsDatabase[i].GetEngineNum()) + "\n"
                    + "Car's release date: " + CarsDatabase[i].GetReleaseDate() + "\n"
                    + "Car's mileage: " + std::to_string(CarsDatabase[i].GetMileage()) + "\n"
                    + "Car's driver code: " + std::to_string(CarsDatabase[i].GetDriverCode()) + "\n"
                    + "Car's last maintenance date: " + CarsDatabase[i].GetMaintenance() + "\n"
                    + "Car's mechanic code: " + std::to_string(CarsDatabase[i].GetMechanicCode())+ "\n"
                    + "Car's specials: " + CarsDatabase[i].GetSpecials() + "\n"
                    + (CarsDatabase[i].GetStatus() ? "Current car" : "Former car") + "\n"
                    + "Car's quality: " + std::to_string(CarsDatabase[i].GetCarQuality()) +"\n\n\n\n";
        }
    }
    return Temp;
}

std::string Database::DisplayFormer()
{
    std::string Temp = "";
    for (int i = 0; i < NextSlot; i++)
    {
        if (!CarsDatabase[i].GetStatus())
        {
            Temp += "Car's code: " + std::to_string(CarsDatabase[i].GetCarCode()) + "\n"
                    + "Car's brand code: " + std::to_string(CarsDatabase[i].GetBrandCode()) + "\n"
                    + "Car's registration number: " + std::to_string(CarsDatabase[i].GetRegNum()) + "\n"
                    + "Car's body number: " + std::to_string(CarsDatabase[i].GetBodyNum()) + "\n"
                    + "Car's engine numebr: " + std::to_string(CarsDatabase[i].GetEngineNum()) + "\n"
                    + "Car's release date: " + CarsDatabase[i].GetReleaseDate() + "\n"
                    + "Car's mileage: " + std::to_string(CarsDatabase[i].GetMileage()) + "\n"
                    + "Car's driver code: " + std::to_string(CarsDatabase[i].GetDriverCode()) + "\n"
                    + "Car's last maintenance date: " + CarsDatabase[i].GetMaintenance() + "\n"
                    + "Car's mechanic code: " + std::to_string(CarsDatabase[i].GetMechanicCode())+ "\n"
                    + "Car's specials: " + CarsDatabase[i].GetSpecials() + "\n"
                    + (CarsDatabase[i].GetStatus() ? "Current car" : "Former car") + "\n"
                    + "Car's quality: " + std::to_string(CarsDatabase[i].GetCarQuality()) +"\n\n\n\n";
        }
    }
    return Temp;
}

void Database::WriteToFile(const std::string& FileName)
{
    ofstream outFile(FileName);
    if (!outFile.is_open()) {
        cerr << "Error opening file: " << FileName << endl;
        return;
    }

    for (int i = 0; i < NextSlot; ++i) {
        outFile << CarsDatabase[i].Serialize() << endl;
    }

    outFile.close();
}

void Database::ReadFromFile(const std::string& FileName)
{
    ifstream inFile(FileName);
    if (!inFile.is_open()) {
        cerr << "Error opening file: " << FileName << endl;
        return;
    }

    // Reset database
    NextSlot = 0;
    NextCarCode = FirstCarCode;

    std::string line;
    while (getline(inFile, line)) {
        // Assuming the Car class has a static Deserialize function
        CarsDatabase[NextSlot++] = Car::Deserialize(line);
    }

    inFile.close();
}
