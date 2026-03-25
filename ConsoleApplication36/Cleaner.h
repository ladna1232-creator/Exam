#pragma once
#include "Personal.h"

class Cleaner : public Personal 
{
public:
    Cleaner(int id, const std::string& name, double hourlyRate);
    ~Cleaner();

    void calc() override;
    std::string getPosition() const override;
};