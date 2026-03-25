#include "Engineer.h"

Engineer::Engineer(int id, const std::string& name, double hourlyRate)
    : Personal(id, name, hourlyRate), project(nullptr) {
}

Engineer::~Engineer() {}

void Engineer::setProject(Project* proj) 
{
    project = proj;
}

Project* Engineer::getProject() const
{
    return project;
}

double Engineer::calcBudgetPart(double part, int budget) 
{
    return budget * part;
}

void Engineer::calc() {
    double base = calcBase(hourlyRate, worktime);
    double bonus = calcBonus(worktime);
    double proAdditions = calcProAdditions();

    if (project != nullptr) 
    {
        double budgetPart = calcBudgetPart(0.1, project->budget);
        payment = base + bonus + proAdditions + budgetPart;
    }
    else 
    {
        payment = base + bonus + proAdditions;
    }
}