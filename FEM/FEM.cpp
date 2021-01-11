#include <iostream>
#include <vector>

#include "GlobalData.h"
#include "Node.h"
#include "FiniteElement.h"
#include "DataLoader.h"

int main()
{
    GlobalData();

    std::vector<Node> Nodes;
    std::vector <FiniteElement> FiniteElements;
    DataLoader::load_nodes_and_elements("temp_model.k", Nodes, FiniteElements);
}
