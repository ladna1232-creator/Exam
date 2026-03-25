#include "Programmer.h"

Programmer::Programmer(int id, const std::string& name, double hourlyRate)
    : Engineer(id, name, hourlyRate), earlyCodeBonus(0) 
{
}

Programmer::~Programmer() {}

void Programmer::setEarlyCodeBonus(double bonus)
{
    earlyCodeBonus = bonus;
}

double Programmer::calcProAdditions()
{
    return earlyCodeBonus;
}

void Programmer::calc()
{
    Engineer::calc();
}

std::string Programmer::getPosition() const
{
    return "Programmer";
}