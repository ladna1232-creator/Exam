#include "TeamLeader.h"

using namespace std;

TeamLeader::TeamLeader(int id, const string& name, double hourlyRate)
    : Engineer(id, name, hourlyRate), programmersCount(0) 
{
}

TeamLeader::~TeamLeader() {}

void TeamLeader::setProgrammersCount(int count)
{
    programmersCount = count;
}

double TeamLeader::calcHeads(int subordinates)
{
    return subordinates * 500;
}

double TeamLeader::calcProAdditions()
{
    return 0; 
}

void TeamLeader::calc()
{
    double base = calcBase(hourlyRate, worktime);
    double headsBonus = calcHeads(programmersCount);
    double proAdditions = calcProAdditions();

    if (project != nullptr) 
    {
        double budgetPart = calcBudgetPart(0.15, project->budget);
        payment = base + headsBonus + proAdditions + budgetPart;
    }
    else {
        payment = base + headsBonus + proAdditions;
    }
}

string TeamLeader::getPosition() const
{
    return "TeamLeader";
}