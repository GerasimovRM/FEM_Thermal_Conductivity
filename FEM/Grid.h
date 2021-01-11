#include <vector>
#include "FiniteElement.h"

#pragma once
class Grid
{
public:
    std::vector<FiniteElement> elements;
    std::vector<std::vector<double>> global_A;
    std::vector<std::vector<double>> global_B;
    std::vector<double> global_f;

    Grid(std::vector<FiniteElement> elements);
    void calculate_global_A();
    void calculate_global_B();
    void calculate_global_f();
};

