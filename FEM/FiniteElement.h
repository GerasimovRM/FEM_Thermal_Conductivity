#include <vector>

#include "Node.h"
#include "GlobalData.h"

#pragma once
class FiniteElement
{
public:
    std::vector<Node> nodes;
    int element_id;

    std::vector<std::vector<double>> local_A;
    std::vector<std::vector<double>> local_B;
    std::vector<double> local_f;

    std::vector<std::vector<double>> calculate_local_A();
    std::vector<std::vector<double>> calculate_local_B();
    std::vector<double> calculate_local_f();
    void Print();

    static void PrintElements(std::vector<FiniteElement>);

};  

