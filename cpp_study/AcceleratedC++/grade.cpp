#include "grade.h"
#include "median.h"
#include <stdexcept>
using namespace std;
double grade(double midterm, double final, double homework)
{
    return 0.3 * midterm + 0.4 * final + 0.4 * homework;
}
double grade(double midterm, double final, const vector<double>& hw)
{
    if (hw.size() == 0)
    {
        throw domain_error("NO HomeWork!!");
    }
    return grade(midterm, final, median(hw));
}
double grade(const StudentInfo& s)
{
    return grade(s.midterm, s.final, s.homework);
}