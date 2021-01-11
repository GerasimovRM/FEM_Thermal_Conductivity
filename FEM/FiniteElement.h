#include <vector>
#include "Node.h"
#include "GlobalData.h"

#pragma once
class FiniteElement
{
    std::vector<Node> nodes;
    int id_element;

    std::vector<std::vector<double>> local_A;
    std::vector<std::vector<double>> local_B;
    std::vector<double> local_f;

};  

