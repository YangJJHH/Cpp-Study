#include <ios>
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
//ø¨Ω¿¿Â
using namespace std;
double median(vector<double> vec);
struct StudentInfo
{
    string name;
    double midterm, final;
    vector<double> homework;
};
bool compare(const StudentInfo& s1, const StudentInfo& s2)
{
    return s1.name < s2.name;
}

double grade(double midterm, double final, double homework)
{
    return 0.3 * midterm + 0.4 * final + 0.4 * homework;
}
double grade(double midterm, double final, const vector<double> &hw)
{
    if (hw.size() == 0)
    {
        throw domain_error("NO HomeWork!!");
    }
    return grade(midterm,final,median(hw));
}
double grade(const StudentInfo& s)
{
    return grade(s.midterm,s.final,s.homework);
}
double median(vector<double> vec)
{
    typedef vector<double>::size_type vec_size;
    vec_size size = vec.size();
    if (size == 0)
    {
        throw domain_error("median of an empty vector");
    }
    // Sorting
    sort(vec.begin(), vec.end());

    vec_size mid = size / 2;
    double median;

    median = (size % 2 == 0) ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
    return median;
}
istream& read_hw(istream& in,vector<double>& hw)
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
istream& read(istream& in,StudentInfo& s)
{
    in >> s.name >> s.midterm >> s.final;
    read_hw(in,s.homework);
    return in;
}
int main()
{
    vector<StudentInfo> students;
    StudentInfo record;
    string::size_type maxlen = 0;

    while (read(cin, record))
    {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    sort(students.begin(), students.end(), compare);
    for(const StudentInfo &s : students)
    {
        cout << s.name << string(maxlen + 1 - s.name.size(), ' ');
        try
        {
            //print result
            streamsize prec = cout.precision();
            double final_grade = grade(s);
            cout << setprecision(3)
                << final_grade
                << setprecision(prec);
        }
        catch (domain_error e)
        {
            cout << e.what() << endl;
            return 1;
        }
        cout << endl;

    }
   

    return 0;
}
