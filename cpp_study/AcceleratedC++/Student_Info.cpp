#include "Student_Info.h"

using std::istream;
using std::vector;

istream& read_hw(istream& in, vector<double>& hw)
{
    if (in)
    {
        hw.clear();
        double x;
        while (in >> x)
        {
            hw.push_back(x);
        }
        in.clear();
    }
    return in;
}
istream& read(istream& in, StudentInfo& s)
{
    in >> s.name >> s.midterm >> s.final;
    read_hw(in, s.homework);
    return in;
}
bool compare(const StudentInfo& s1, const StudentInfo& s2)
{
    return s1.name < s2.name;
}