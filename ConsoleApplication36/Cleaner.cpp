#include "Cleaner.h"

Cleaner::Cleaner(int id, const std::string& name, double hourlyRate)
    : Personal(id, name, hourlyRate) {
}

Cleaner::~Cleaner() {}

void Cleaner::calc() 
{
    payment = calcBase(hourlyRate, worktime) + calcBonus(worktime);
}

std::string Cleaner::getPosition() const 
{
    return "Cleaner";
}