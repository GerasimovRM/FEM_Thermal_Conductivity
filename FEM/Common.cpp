#include "Common.h"

double* Common::vector_to_array(std::vector<double> vec)
{
    double* dest = new double[vec.size()];
    std::copy(vec.begin(), vec.end(), dest);
    return dest;
}

double** Common::vector_to_array(std::vector<std::vector<double>> vec)
{
    double** dest = new double* [vec.size()];
    for (int i = 0; i < vec.size(); ++i)
    {
        dest[i] = new double [vec[i].size()];
        std::copy(vec[i].begin(), vec[i].end(), dest[i]);
    }
    return dest;
}

std::vector<double> Common::array_to_vector(double* arr, int n)
{
    return std::vector<double>(arr, arr + n);
}

std::vector<std::vector<double>> Common::array_to_vector(double** arr, int n, int m)
{
    std::vector<std::vector<double>> vec(n);
    for (int i = 0; i < n; ++i)
    {
        vec[i] = std::vector<double>(arr[i], arr[i] + m);
    }
    return vec;
}