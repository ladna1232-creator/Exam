#pragma once
#include <string>
using namespace std;

class Employee 
{
protected:
    int id;
    string name;
    double worktime;
    double payment;

public:
    Employee(int id, const string& name);
    virtual ~Employee();

    int getId() const;
    string getName() const;
    double getWorktime() const;
    double getPayment() const;

    void setWorkTime(double time);
    virtual void calc() = 0;
    virtual void printInfo() const;
    virtual string getPosition() const = 0;
};