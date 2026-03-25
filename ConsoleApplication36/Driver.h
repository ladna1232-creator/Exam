#pragma once
#include "Personal.h"

class Driver : public Personal 
{
public:
    Driver(int id, const std::string& name, double hourlyRate);
    ~Driver();

    double calcN(double nightHours);
    void calc() override;
    std::string getPosition() const override;

private:
    double calcNouse(double nightHours);
};