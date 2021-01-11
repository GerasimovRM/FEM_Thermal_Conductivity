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

    void Print();

    static void PrintElements(std::vector<FiniteElement>);

};  

