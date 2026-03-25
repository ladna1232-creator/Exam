#pragma once
#include <vector>
#include <string>
#include "Employee.h"
using namespace std;
class StaffFactory {
public:
    static vector<Employee*> makeStaff(const std::string& filename);
    static void saveStaff(const std::vector<Employee*>& staff, const std::string& filename);
};