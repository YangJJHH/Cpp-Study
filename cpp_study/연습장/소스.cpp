#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
//¿¬½ÀÀå
using namespace std;
bool compare(int a, int b)
{
    return a > b;
}
int main()
{
    vector<int> numbers = { 12,111,2,4,5,7 };
    int answer = 0;
    sort(numbers.begin(), numbers.end(),compare);
    answer = numbers[0] * numbers[1];
    cout << answer;
    int n = 5;
    vector<int> answer(numbers.begin()+1,numbers.end());
    return 0;
}
