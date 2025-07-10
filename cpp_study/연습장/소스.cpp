#include <ios>
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
//������
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


int arr[8] = { 7,1,3,4,2,10,19,20 };
int temp[8];

void Quick_Sort(int start, int end)
{
    if (start + 1 >= end) return;

    int pivot = arr[start];
    int l = start + 1;
    int r = end - 1;

    while (true)
    {
        while (l <= r && arr[l] <= pivot) l++; // pivot���� ū���� ���ö�����
        while (l <= r && arr[r] >= pivot) r--; // pivot���� �������� ���Ë�����
        if (l > r) break; // r�� l���� ���ʿ� ������
        
        std::swap(arr[l], arr[r]); // ���� ���Ҹ� ã���� �ڸ��ٲٱ� 
    }
    std::swap(arr[start], arr[r]);
    Quick_Sort(start, r);
    Quick_Sort(r+1, end);
}


int main()
{
    // ���� ����
    
    int n = 8;
    Quick_Sort(0, n);
    
    for (auto ele : arr)
        cout << ele << ' ';

    return 0;
}
