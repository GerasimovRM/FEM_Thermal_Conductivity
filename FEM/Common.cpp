#include <iostream>

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

double** Common::matrix_product(double** firstMatrix, int rowFirst, int columnFirst, double** secondMatrix, int rowSecond, int columnSecond)
{
	double** result = new double* [rowFirst];
	for (int i = 0; i < rowFirst; ++i)
	{
		result[i] = new double[columnSecond];
		for (int j = 0; j < columnSecond; ++j)
			result[i][j] = 0.;
	}

	int i, j, k;

	for (i = 0; i < rowFirst; ++i)
		for (j = 0; j < columnSecond; ++j)
			for (k = 0; k < columnFirst; ++k)
				result[i][j] += firstMatrix[i][k] * secondMatrix[k][j];

    return result;
}

double** Common::matrix_transpose(double** matrix, int n, int m)
{
    double** result = new double* [m];
    for (int i = 0; i < m; ++i)
    {
        result[i] = new double[n];
        for (int j = 0; j < n; ++j)
            result[i][j] = matrix[j][i];
    }
    return result;
}

void Common::matrix_print(double** matrix, int n, int m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            std::cout << matrix[i][j] << ' ';
        std::cout << std::endl;
    }
}