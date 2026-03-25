#include "Driver.h"

Driver::Driver(int id, const std::string& name, double hourlyRate)
    : Personal(id, name, hourlyRate) 
{
}

Driver::~Driver() {}

double Driver::calcNouse(double nightHours) 
{
    return hourlyRate * nightHours * 0.5;
}

double Driver::calcN(double nightHours) 
{
    return calcNouse(nightHours);
}

void Driver::calc() {
    double base = calcBase(hourlyRate, worktime);
    double nightBonus = calcN(worktime * 0.3);
    payment = base + nightBonus;
}

std::string Driver::getPosition() const 
{
    return "Driver";
}