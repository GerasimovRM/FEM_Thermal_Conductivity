#include <string>
#include <vector>

#include "Node.h"
#include "FiniteElement.h"

#pragma once
class DataLoader
{
public:
    void load_nodes_and_elements(std::string, std::vector<Node>&, std::vector<FiniteElement>&);
};

