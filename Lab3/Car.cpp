#include <iostream>
#include <string>
#include "Car.h"
using namespace std;

Car::Car()
{
    BrandCode = 0;
    RegNum = 0;
    BodyNum = 0;
    EngineNum = 0;
    ReleaseDate = "";
    Mileage = 0;
    DriverCode = 0;
    Maintenance = "";
    MechanicCode = 0;
    Specials = "";
    CarCode = 0;
    CarQuality = 0;
    IsActive = false;
}

void Car::Promote(int RaiseQuality)
{
    SetCarQuality(GetCarQuality() + RaiseQuality);
}

void Car::Demote(int DecreaseQuality)
{
    SetCarQuality(GetCarQuality() - DecreaseQuality);
}

void Car::Enable()
{
    IsActive = true;
}

void Car::Disable()
{
    IsActive = false;
}

void Car::SetBrandCode(int BrandCodeI)
{
    BrandCode = BrandCodeI;
}

int Car::GetBrandCode()
{
    return BrandCode;
}

void Car::SetRegNum(int RegNumI)
{
    RegNum = RegNumI;
}

int Car::GetRegNum()
{
    return RegNum;
}

void Car::SetBodyNum(int BodyNumI)
{
    BodyNum = BodyNumI;
}

int Car::GetBodyNum()
{
    return BodyNum;
}

void Car::SetEngineNum(int EngineNumI)
{
    EngineNum = EngineNumI;
}

int Car::GetEngineNum()
{
    return EngineNum;
}

void Car::SetReleaseDate(string ReleaseDateI)
{
    ReleaseDate = ReleaseDateI;
}

string Car::GetReleaseDate()
{
    return ReleaseDate;
}

void Car::SetMileage(int MileageI)
{
    Mileage = MileageI;
}

int Car::GetMileage()
{
    return Mileage;
}

void Car::SetDriverCode(int DriverCodeI)
{
    DriverCode = DriverCodeI;
}

int Car::GetDriverCode()
{
    return DriverCode;
}

void Car::SetMaintenance(string MaintenanceI)
{
    Maintenance = MaintenanceI;
}

string Car::GetMaintenance()
{
    return Maintenance;
}

void Car::SetMechanicCode(int MechanicCodeI)
{
    MechanicCode = MechanicCodeI;
}

int Car::GetMechanicCode()
{
    return MechanicCode;
}

void Car::SetSpecials(string SpecialsI)
{
    Specials = SpecialsI;
}

string Car::GetSpecials()
{
    return Specials;
}

void Car::SetCarQuality(int CarQualityI)
{
    CarQuality = CarQualityI;
}

int Car::GetCarQuality()
{
    return CarQuality;
}

void Car::SetCarCode(int CarCodeI)
{
    CarCode = CarCodeI;
}

int Car::GetCarCode()
{
    return CarCode;
}

bool Car::GetStatus()
{
    return IsActive;
}

std::string Car::Serialize() const
{
    // Convert Car data to a string
    std::ostringstream serializedData;
    serializedData << BrandCode << " "
                   << RegNum << " "
                   << BodyNum << " "
                   << EngineNum << " "
                   << ReleaseDate << " "
                   << Mileage << " "
                   << DriverCode << " "
                   << Maintenance << " "
                   << MechanicCode << " "
                   << Specials << " "
                   << CarCode << " "
                   << CarQuality << " "
                   << (IsActive ? "1" : "0");
    return serializedData.str();
}

Car Car::Deserialize(const std::string& data)
{
    // Convert string data to a Car object
    std::istringstream iss(data);
    Car car;

    iss >> car.BrandCode
        >> car.RegNum
        >> car.BodyNum
        >> car.EngineNum
        >> car.ReleaseDate
        >> car.Mileage
        >> car.DriverCode
        >> car.Maintenance
        >> car.MechanicCode
        >> car.Specials
        >> car.CarCode
        >> car.CarQuality;

    int isActiveInt;
    iss >> isActiveInt;
    car.IsActive = (isActiveInt == 1);

    return car;
}
