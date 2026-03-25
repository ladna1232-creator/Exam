#include "Factory.h"
#include "Cleaner.h"
#include "Driver.h"
#include "Programmer.h"
#include "Tester.h"
#include "TeamLeader.h"
#include "Manager.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

vector<Employee*> StaffFactory::makeStaff(const string& filename)
{
    vector<Employee*> staff;
    ifstream file(filename);

    if (!file.is_open()) 
    {
        cout << "Cannot open file: " << filename << endl;
        return staff;
    }

    string line;
    while (getline(file, line)) 
    {
        stringstream ss(line);
        int id;
        string name, position;
        double salary;
        string projectName;

        ss >> id >> name >> position >> salary;

        Employee* emp = nullptr;

        if (position == "Cleaner") 
        {
            emp = new Cleaner(id, name, salary);
        }
        else if (position == "Driver") 
        {
            emp = new Driver(id, name, salary);
        }
        else if (position == "Programmer") 
        {
            emp = new Programmer(id, name, salary);
            if (ss >> projectName) 
            {

            }
        }
        else if (position == "Tester") 
        {
            emp = new Tester(id, name, salary);
            if (ss >> projectName) 
            {

            }
        }
        else if (position == "TeamLeader") 
        {
            emp = new TeamLeader(id, name, salary);
            if (ss >> projectName) 
            {

            }
        }
        else if (position == "ProjectManager") 
        {
            emp = new ProjectManager(id, name);
            if (ss >> projectName) 
            {
                Project proj(projectName, 100000);
                static_cast<ProjectManager*>(emp)->setProject(proj);
            }
        }
        else if (position == "SeniorManager") 
        {
            emp = new SeniorManager(id, name);
        }

        if (emp) 
        {
            staff.push_back(emp);
        }
    }

    file.close();
    return staff;
}

void StaffFactory::saveStaff(const vector<Employee*>& staff, const string& filename)
{
    ofstream file(filename);

    if (!file.is_open()) 
    {
        cout << "Cannot save to file: " << filename << endl;
        return;
    }

    for (auto emp : staff) 
    {
        file << emp->getId() << " "
            << emp->getName() << " "
            << emp->getPosition() << " ";

        Personal* personal = dynamic_cast<Personal*>(emp);
        if (personal) 
        {
            file << personal->getHourlyRate();
        }
        else 
        {
            file << 0;
        }

        Engineer* engineer = dynamic_cast<Engineer*>(emp);
        if (engineer && engineer->getProject()) {
            file << " " << engineer->getProject()->name;
        }

        file << endl;
    }

    file.close();
}