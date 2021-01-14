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
            std::cout << matrix[i][j] << "\t";
        std::cout << std::endl;
    }
}

void Common::vector_print(std::vector<std::vector<double>> vec)
{
    for (auto v : vec)
    {
        // std::cout << v.size() << std::endl;
        for (auto elem : v)
            std::cout << elem << "\t";
        std::cout << std::endl;
    }
    std::cout << std::endl; std::cout << std::endl;
}

double* Common::gauss(double** a, double* y, int n)
{
    double* x, max;
    int k, index;
    const double eps = 0.00001;  // точность
    x = new double[n];
    k = 0;
    while (k < n)
    {
        // Поиск строки с максимальным a[i][k]
        max = abs(a[k][k]);
        index = k;
        for (int i = k + 1; i < n; i++)
        {
            if (abs(a[i][k]) > max)
            {
                max = abs(a[i][k]);
                index = i;
            }
        }
        // Перестановка строк
        if (max < eps)
        {
            // нет ненулевых диагональных элементов
            std::cout << "Решение получить невозможно из-за нулевого столбца ";
            std::cout << index << " матрицы A" << std::endl;
            return NULL;
        }
        for (int j = 0; j < n; j++)
        {
            double temp = a[k][j];
            a[k][j] = a[index][j];
            a[index][j] = temp;
        }
        double temp = y[k];
        y[k] = y[index];
        y[index] = temp;
        // Нормализация уравнений
        for (int i = k; i < n; i++)
        {
            double temp = a[i][k];
            if (abs(temp) < eps) continue; // для нулевого коэффициента пропустить
            for (int j = 0; j < n; j++)
                a[i][j] = a[i][j] / temp;
            y[i] = y[i] / temp;
            if (i == k)  continue; // уравнение не вычитать само из себя
            for (int j = 0; j < n; j++)
                a[i][j] = a[i][j] - a[k][j];
            y[i] = y[i] - y[k];
        }
        k++;
    }
    // обратная подстановка
    for (k = n - 1; k >= 0; k--)
    {
        x[k] = y[k];
        for (int i = 0; i < k; i++)
            y[i] = y[i] - a[i][k] * x[k];
    }
    return x;
}