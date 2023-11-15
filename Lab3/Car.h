#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <sstream>
using namespace std;

const int DefaultClass = 1;

class Car
{
public:
    Car();
    void Promote(int RaiseQuality = 1);
    void Demote(int DecreaseQuality = 1);
    void Enable();
    void Disable();

    void SetBrandCode(int BrandCodeI);
    int GetBrandCode();
    void SetRegNum(int RegNumI);
    int GetRegNum();
    void SetBodyNum(int BodyNumI);
    int GetBodyNum();
    void SetEngineNum(int EngineNumI);
    int GetEngineNum();
    void SetReleaseDate(string ReleaseDateI);
    string GetReleaseDate();
    void SetMileage(int MileageI);
    int GetMileage();
    void SetDriverCode(int DriverCodeI);
    int GetDriverCode();
    void SetMaintenance(string MaintenanceI);
    string GetMaintenance();
    void SetMechanicCode(int MechanicCodeI);
    int GetMechanicCode();
    void SetSpecials(string SpecialsI);
    string GetSpecials();
    void SetCarQuality(int CarQualityI);
    int GetCarQuality();
    void SetCarCode(int CarCodeI);
    int GetCarCode();
    bool GetStatus();
    std::string Serialize() const;
    static Car Deserialize(const std::string& data);
private:
    int BrandCode;
    int RegNum;
    int BodyNum;
    int EngineNum;
    string ReleaseDate;
    int Mileage;
    int DriverCode;
    string Maintenance;
    int MechanicCode;
    string Specials;
    int CarCode;
    int CarQuality;
    bool IsActive;
};

#endif // CAR_H
