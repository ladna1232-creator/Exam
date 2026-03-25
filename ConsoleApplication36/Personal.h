#pragma once
#include "Employee.h"
#include "Interfaces.h"

class Personal : public Employee, public WorkBaseTime 
{
protected:
    double hourlyRate;

public:
    Personal(int id, const std::string& name, double hourlyRate);
    virtual ~Personal();

    double getHourlyRate() const;
    double calcBase(double hourlyRate, double workTime) override;
    double calcBonus(double workTime) override;
};