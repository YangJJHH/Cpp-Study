#ifndef GUARD_grade_h
#define GUARD_grade_h
#include <vector>
#include "Student_Info.h"
double grade(double midterm, double final, double homework);
double grade(double midterm, double final, const std::vector<double>& hw);
double grade(const StudentInfo& s);
#endif
