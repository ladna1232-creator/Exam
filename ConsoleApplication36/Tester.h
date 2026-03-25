#pragma once
#include "Engineer.h"

class Tester : public Engineer 
{
private:
    int bugsFound;

public:
    Tester(int id, const std::string& name, double hourlyRate);
    ~Tester();

    void setBugsFound(int bugs);
    double calcProAdditions() override;
    void calc() override;
    std::string getPosition() const override;
};