#include "Manager.h"

ProjectManager::ProjectManager(int id, const std::string& name)
    : Employee(id, name), projectCount(0) {
}

ProjectManager::~ProjectManager() {}

void ProjectManager::setProject(const Project& proj) 
{
    if (projectCount < 1) 
    {
        projects[projectCount] = proj;
        projectCount++;
    }
}

double ProjectManager::calcHeads(int subordinates) 
{
    return subordinates * 300;
}

double ProjectManager::calcBudgetPart(double part, int budget) 
{
    return budget * part;
}

double ProjectManager::calcProAdditions() 
{
    return 0;
}

void ProjectManager::calc() 
{
    double totalPayment = 0;
    for (int i = 0; i < projectCount; i++) 
    {
        totalPayment += calcBudgetPart(0.2, projects[i].budget);
    }
    payment = totalPayment;
}

std::string ProjectManager::getPosition() const 
{
    return "ProjectManager";
}

SeniorManager::SeniorManager(int id, const std::string& name)
    : Employee(id, name), projects(nullptr), projectCount(0) {
}

SeniorManager::~SeniorManager() 
{
    delete[] projects;
}

void SeniorManager::addProject(const Project& proj)
{
    Project* newProjects = new Project[projectCount + 1];
    for (int i = 0; i < projectCount; i++)
    {
        newProjects[i] = projects[i];
    }
    newProjects[projectCount] = proj;
    delete[] projects;
    projects = newProjects;
    projectCount++;
}

double SeniorManager::calcHeads(int subordinates)
{
    return subordinates * 400;
}

void SeniorManager::calc()
{
    double totalPayment = 0;
    for (int i = 0; i < projectCount; i++)
    {
        totalPayment += projects[i].budget * 0.1;
    }
    payment = totalPayment;
}

std::string SeniorManager::getPosition() const
{
    return "SeniorManager";
}