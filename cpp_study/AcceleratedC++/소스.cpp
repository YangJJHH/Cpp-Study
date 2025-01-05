#include <ios>
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <list>
#include <algorithm>
#include <stdexcept>
#include <cctype>
#include <map>
#include "median.h"
#include "Student_Info.h"
#include "grade.h"
//연습장
using namespace std;

// 템플릿
template<class In , class X>
In findo(In begin, In end, const X& x)
{
    while (begin != end && *begin != x)
    {
        ++begin;
    }
    return begin;
}
template<class T>
T median(vector<T> v)
{
    typedef typename vector<T>::size_type vec_sz;
    vec_sz size = v.size();

    if (size == 0)
    {
        throw domain_error("empty size");
    }
    sort(v.begin(), v.end());

    vec_sz mid = size / 2;

    return size % 2 == 0 ? (v[mid] + v[mid + 1]) / 2 : v[mid];
}
template<class Out>



bool fgrade(const StudentInfo &s)
{
    return grade(s) < 60;
}
vector<StudentInfo> extract_fails(vector<StudentInfo>& students)
{
    vector<StudentInfo> pass, fail;

    vector<StudentInfo>::iterator iter = students.begin();
    while (iter != students.end())
    {
        if (fgrade(*iter))
        {
            fail.push_back((*iter));
            iter = students.erase(iter);
        }
        else
        {
            iter++;
        }
    }
    return fail;
}
list<StudentInfo> extract_fails(list<StudentInfo>& students)
{
    list<StudentInfo> pass, fail;

    list<StudentInfo>::iterator iter = students.begin();
    while (iter != students.end())
    {
        if (fgrade(*iter))
        {
            fail.push_back((*iter));
            iter = students.erase(iter);
        }
        else
        {
            iter++;
        }
    }
    return fail;
}
vector<string> split(const string &s)
{
    vector<string> ret;
    typedef string::size_type str_size;
    str_size i = 0;
    while (i != s.size())
    {
        //선행 공백 무시
        while (i != s.size() && isspace(s[i]))
        {
            i++;
        }
        // 공백 이후 문자에 대해 처리
        str_size j = i;
        // 현재 문자부터 다음 공백까지의 문자에 해당하는 인덱스 구하기
        while (j != s.size()&& !isspace(s[j]))
        {
            j++;
        }
        ret.push_back(s.substr(i,j-i));
        i = j;
    }
    return ret;
}
string::size_type width(const vector<string>& s)
{
    string::size_type max_len = 0;
    for (auto& ele : s)
    {
        max_len = max(max_len, ele.size());
    }
    return max_len;
}
vector<string> frame(const vector<string> &s)
{
    vector<string> ret;
    string::size_type max_len = width(s);
    string border(max_len+4, '*');
    ret.push_back(border);
    for (auto &ele : s)
    {
        string::size_type count = max_len - ele.size();
        ret.push_back("* "+ele+string(count,' ') +" *");
    }
    ret.push_back(border);
    ret.insert(ret.begin(),s.begin(),s.end());
    return ret;
}
bool not_url_char(char c)
{
    static const string url_ch = "~;/?:@+&$-_.+!*',()";
    return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}
string::const_iterator url_beg(string::const_iterator b, string::const_iterator e)
{
    static const string token = "://";
    typedef string::const_iterator iter;

    iter i = b;
    while ((i = search(i,e, token.begin(), token.end())) != e)
    {
        if (i != b && i + token.size() != e)
        {
            iter beg = i;
            while (beg != b && isalpha(beg[-1]))
            {
                beg--;
            }
            if (beg != i && !not_url_char(i[token.size()]))
                return beg;
        }
        i += token.size();
    }
    return e;
}
string::const_iterator url_end(string::const_iterator b, string::const_iterator e)
{
    return find_if(b, e, not_url_char);
}
vector<string> find_urls(const string& s)
{
    vector<string> ret;
    typedef string::const_iterator iter;
    iter b = s.begin();
    iter e = s.end();

    while (b != e)
    {
        b = url_beg(b,e);
        if (b != e)
        {
            iter after = url_end(b, e);
            ret.push_back(string(b,after));
            b = after;
        }
    }

    return ret;
}
map<string, vector<int> > xref(istream& in, vector<string> find_words(const string& a) = split)
{
    map<string, vector<int> > ret;
    string line;
    int line_number = 0;

    while (getline(in,  line))
    {
        ++line_number;

        vector<string> words = find_words(line);

        for (vector<string>::const_iterator iter = words.begin(); iter != words.end(); ++iter)
        {
            ret[(*iter)].push_back(line_number);
        }
    }
    return ret;
}


int Ex()
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
    for (const StudentInfo& s : students)
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
int main()
{
    map<string, vector<int> > ret = xref(cin);
    for (map<string, vector<int> >::const_iterator iter = ret.begin(); iter != ret.end(); ++iter)
    {
        cout <<"word : " << iter->first;
        for (vector<int>::const_iterator iter2 = (iter->second).begin(); iter2 != (iter->second).end(); ++iter2)
        {
            cout << " " << *iter2;
        }
        cout << endl;
    }
    vector<int> test;
    int a = 3;
    findo(test.begin(), test.end(), 3);
    return 0;
}
