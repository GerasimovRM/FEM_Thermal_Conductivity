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

    void calculate_local_C(bool = false);
    void calculate_local_K(bool = false);
    void calculate_local_f(bool = false);
    double calculate_volume();
    bool FiniteElementWithNode(int);
    void Print();

    static void PrintElements(std::vector<FiniteElement>);

};  

