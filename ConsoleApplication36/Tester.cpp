#include "Tester.h"

Tester::Tester(int id, const std::string& name, double hourlyRate)
    : Engineer(id, name, hourlyRate), bugsFound(0) {
}

Tester::~Tester() {}

void Tester::setBugsFound(int bugs)
{
    bugsFound = bugs;
}

double Tester::calcProAdditions()
{
    return bugsFound * 100;
}

void Tester::calc()
{
    Engineer::calc();
}

std::string Tester::getPosition() const
{
    return "Tester";
}