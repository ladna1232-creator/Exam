#pragma once
#include "Engineer.h"

class Programmer : public Engineer 
{
private:
    double earlyCodeBonus;

public:
    Programmer(int id, const std::string& name, double hourlyRate);
    ~Programmer();

    void setEarlyCodeBonus(double bonus);
    double calcProAdditions() override;
    void calc() override;
    std::string getPosition() const override;
};