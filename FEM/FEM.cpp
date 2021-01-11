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
    DataLoader::load_nodes_and_elements("data.txt", Nodes, FiniteElements);
    Node::PrintNodes(Nodes);
}
