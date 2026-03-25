#include <iostream>
#include <vector>
#include <string>
#include "Factory.h"
#include "Cleaner.h"
#include "Driver.h"
#include "Programmer.h"
#include "Tester.h"
#include "TeamLeader.h"
#include "Manager.h"

using namespace std;

vector<Project> projects;

void showMenu() {
    cout << "\n===== Staff Management System =====" << endl;
    cout << "1. Show all employees" << endl;
    cout << "2. Show employees by project" << endl;
    cout << "3. Search by position" << endl;
    cout << "4. Search by name" << endl;
    cout << "5. Search by salary (greater than)" << endl;
    cout << "6. Search by salary (less than)" << endl;
    cout << "7. Create new project" << endl;
    cout << "8. Add employee to project" << endl;
    cout << "9. Transfer employee to another project" << endl;
    cout << "10. Save and exit" << endl;
    cout << "Choice: ";
}

int main() {
    vector<Employee*> staff;

    staff.push_back(new Cleaner(1, "Ivanova Maria", 150));
    staff.push_back(new Driver(2, "Petrov Ivan", 200));
    staff.push_back(new Programmer(3, "Sidorov Alexey", 300));
    staff.push_back(new Tester(4, "Kuznetsova Olga", 250));
    staff.push_back(new TeamLeader(5, "Smirnov Dmitry", 350));

    Project proj1("Alpha", 100000);
    Project proj2("Beta", 150000);
    projects.push_back(proj1);
    projects.push_back(proj2);

    static_cast<Programmer*>(staff[2])->setProject(&projects[0]);
    static_cast<Tester*>(staff[3])->setProject(&projects[0]);
    static_cast<TeamLeader*>(staff[4])->setProject(&projects[1]);

    static_cast<Programmer*>(staff[2])->setEarlyCodeBonus(5000);
    static_cast<Tester*>(staff[3])->setBugsFound(15);
    static_cast<TeamLeader*>(staff[4])->setProgrammersCount(3);

    for (auto emp : staff) {
        emp->setWorkTime(160);
        emp->calc();
    }

    cout << "Loaded " << staff.size() << " employees." << endl;

    int choice;
    do {
        showMenu();
        cin >> choice;

        if (choice == 1) 
        {
            cout << "ID\tName\t\tPosition\tWorkTime\tPayment" << endl;
            cout << " " << endl;
            for (auto emp : staff) 
            {
                emp->printInfo();
            }
        }
        else if (choice == 2) 
        {
            string name;
            cout << "Project name: ";
            cin >> name;
            cout << "ID\tName\t\tPosition\tWorkTime\tPayment" << endl;
            cout << " " << endl;
            for (auto emp : staff) {
                Engineer* e = dynamic_cast<Engineer*>(emp);
                if (e && e->getProject() && e->getProject()->name == name)
                    emp->printInfo();
            }
        }
        else if (choice == 3) 
        {
            string pos;
            cout << "Position: ";
            cin >> pos;
            cout << "ID\tName\t\tPosition\tWorkTime\tPayment" << endl;
            cout << " " << endl;
            for (auto emp : staff)
                if (emp->getPosition() == pos) emp->printInfo();
        }
        else if (choice == 4) 
        {
            string name;
            cout << "Name: ";
            cin >> name;
            cout << "ID\tName\t\tPosition\tWorkTime\tPayment" << endl;
            cout << " " << endl;
            for (auto emp : staff)
                if (emp->getName().find(name) != string::npos) emp->printInfo();
        }
        else if (choice == 5 || choice == 6) 
        {
            double amount;
            cout << "Amount: ";
            cin >> amount;
            cout << "ID\tName\t\tPosition\tWorkTime\tPayment" << endl;
            cout << " " << endl;
            for (auto emp : staff) 
            {
                if ((choice == 5 && emp->getPayment() > amount) ||
                    (choice == 6 && emp->getPayment() < amount))
                    emp->printInfo();
            }
        }
        else if (choice == 7) 
        {
            string name;
            int budget;
            cout << "Project name: ";
            cin >> name;
            cout << "Budget: ";
            cin >> budget;
            projects.push_back(Project(name, budget));
            cout << "Project created!" << endl;
        }
        else if (choice == 8 || choice == 9) 
        {
            int id;
            string projName;
            cout << "Employee ID: ";
            cin >> id;
            cout << "Project name: ";
            cin >> projName;

            Employee* emp = nullptr;
            for (auto e : staff) if (e->getId() == id) { emp = e; break; }

            if (!emp) 
            {
                cout << "Employee not found!" << endl;
                continue;
            }

            Project* proj = nullptr;
            for (auto& p : projects) if (p.name == projName) { proj = &p; break; }

            if (!proj)
            {
                cout << "Project not found!" << endl;
                continue;
            }

            Engineer* eng = dynamic_cast<Engineer*>(emp);
            if (eng) 
            {
                eng->setProject(proj);
                cout << (choice == 8 ? "Added!" : "Transferred!") << endl;
                for (auto e : staff) e->calc();
            }
            else 
            {
                cout << "This employee cannot be assigned to a project!" << endl;
            }
        }

    } while (choice != 10);

    StaffFactory::saveStaff(staff, "staff.txt");
    cout << "Data saved. Exiting..." << endl;

    for (auto emp : staff) delete emp;

    return 0;
}