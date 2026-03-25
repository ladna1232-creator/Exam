#include "Personal.h"

Personal::Personal(int id, const std::string& name, double hourlyRate)
    : Employee(id, name), hourlyRate(hourlyRate) {
}

Personal::~Personal() {}

double Personal::getHourlyRate() const 
{
    return hourlyRate;
}

double Personal::calcBase(double hourlyRate, double workTime)
{
    return hourlyRate * workTime;
}

double Personal::calcBonus(double workTime) 
{
    return 0;
}