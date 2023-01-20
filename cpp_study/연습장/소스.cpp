#include <string>
#include <vector>
#include <iostream>

using namespace std;
int main()
{
    string my_string = "avbs as";
    my_string.erase(remove(my_string.begin(), my_string.end(), ' '), my_string.end());
    cout << my_string;
    return 0;
}