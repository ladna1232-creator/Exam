#include "Employee.h"
#include <iostream>

using namespace std;

Employee::Employee(int id, const string& name)
    : id(id), name(name), worktime(0), payment(0) 
{
}

Employee::~Employee() {}

int Employee::getId() const 
{
    return id;
}

string Employee::getName() const 
{
    return name;
}

double Employee::getWorktime() const 
{
    return worktime;
}

double Employee::getPayment() const 
{
    return payment;
}

void Employee::setWorkTime(double time)
{
    worktime = time;
}

void Employee::printInfo() const 
{
    cout << id << "\t"
        << name << "\t"
        << getPosition() << "\t"
        << worktime << "\t"
        << payment << endl;
}