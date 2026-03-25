#pragma once
#include "Personal.h"
#include "Interfaces.h"
#include "Project.h"

class Engineer : public Personal, public ProjectBudget 
{
protected:
    Project* project;

public:
    Engineer(int id, const std::string& name, double hourlyRate);
    virtual ~Engineer();

    void setProject(Project* proj);
    Project* getProject() const;

    double calcBudgetPart(double part, int budget) override;
    virtual double calcProAdditions() override = 0;
    void calc() override;
};