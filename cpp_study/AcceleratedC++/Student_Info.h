#ifndef GUARD_Student_Inf
#define GUARD_Student_Inf

#include <iostream>
#include <string>
#include <vector>

struct StudentInfo
{
    std::string name;
    double midterm, final;
    std::vector<double> homework;
};

bool compare(const StudentInfo& s1, const StudentInfo& s2);
std::istream& read_hw(std::istream& in, std::vector<double>& hw);
std::istream& read(std::istream& in, StudentInfo& s);

#endif
