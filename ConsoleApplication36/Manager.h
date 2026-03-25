#pragma once
#include "Employee.h"
#include "Interfaces.h"
#include "Project.h"

class ProjectManager : public Employee, public ProjectBudget, public Heading 
{
private:
    Project projects[1];
    int projectCount;

public:
    ProjectManager(int id, const std::string& name);
    ~ProjectManager();

    void setProject(const Project& proj);
    double calcHeads(int subordinates) override;
    double calcBudgetPart(double part, int budget) override;
    double calcProAdditions() override;
    void calc() override;
    std::string getPosition() const override;
};

class SeniorManager : public Employee, public Heading 
{
private:
    Project* projects;
    int projectCount;

public:
    SeniorManager(int id, const std::string& name);
    ~SeniorManager();

    void addProject(const Project& proj);
    double calcHeads(int subordinates) override;
    void calc() override;
    std::string getPosition() const override;
};