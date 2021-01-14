#include <vector>
#include "FiniteElement.h"

#pragma once
class Grid
{
public:
    std::vector<FiniteElement> elements;
    std::vector<std::vector<double>> global_C;
    std::vector<std::vector<double>> global_K;
    std::vector<double> global_f;

    Grid(std::vector<FiniteElement> elements);
    void calculate_global_C();
    void calculate_global_K();
    void calculate_global_f(std::vector<int>);
};

