#include <vector>

#pragma once
class Common
{
public:
    static double* vector_to_array(std::vector<double>);
    static double** vector_to_array(std::vector<std::vector<double>>);
    static std::vector<double> array_to_vector(double*, int);
    static std::vector<std::vector<double>> array_to_vector(double**, int, int);
    static double** matrix_product(double**, int, int, double**, int, int);
    static double* matrix_product(double**, int, int, double*, int);
    static double** matrix_transpose(double**, int, int);
    static void matrix_print(double**, int, int);
    static void vector_print(std::vector<std::vector<double>>);
    static void vector_print(std::vector<double>);
    static double* gauss(double**, double*, int);
    static double* array_plus_array(double*, double*, int);
    static double* array_minus_array(double*, double*, int);
    static double* array_product_number(double*, int, double);
    static void array_print(double*, int);
};

