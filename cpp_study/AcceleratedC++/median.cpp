#include <stdexcept>
#include <vector>
#include <algorithm>

using namespace std;

double median(std::vector<double> vec)
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