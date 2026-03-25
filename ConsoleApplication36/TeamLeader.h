#pragma once
#include "Engineer.h"
#include "Interfaces.h"

class TeamLeader : public Engineer, public Heading 
{
private:
    int programmersCount;

public:
    TeamLeader(int id, const std::string& name, double hourlyRate);
    ~TeamLeader();

    void setProgrammersCount(int count);
    double calcHeads(int subordinates) override;
    double calcProAdditions();
    void calc() override;
    std::string getPosition() const override;
};