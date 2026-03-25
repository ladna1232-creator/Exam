#pragma once

class WorkBaseTime 
{
public:
    virtual double calcBase(double hourlyRate, double workTime) = 0;
    virtual double calcBonus(double workTime) = 0;
    virtual ~WorkBaseTime() {}
};

class ProjectBudget 
{
public:
    virtual double calcBudgetPart(double part, int budget) = 0;
    virtual double calcProAdditions() = 0;
    virtual ~ProjectBudget() {}
};

class Heading 
{
public:
    virtual double calcHeads(int subordinates) = 0;
    virtual ~Heading() {}
};