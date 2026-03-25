#pragma once
#include <string>

struct Project 
{
    std::string name;
    int budget;

    Project() : name(""), budget(0) {}
    Project(const std::string& n, int b) : name(n), budget(b) {}
};