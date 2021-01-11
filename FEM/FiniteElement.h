#include <vector>

#include "Node.h"
#include "GlobalData.h"

#pragma once
class FiniteElement
{
public:
    std::vector<Node> nodes;
    int element_id;

    double** local_C = NULL;
    double** local_K = NULL;
    double* local_f = NULL;

    double** calculate_local_C();
    double** calculate_local_K();
    double* calculate_local_f();
    double calculate_volume();
    void Print();

    static void PrintElements(std::vector<FiniteElement>);

};  

