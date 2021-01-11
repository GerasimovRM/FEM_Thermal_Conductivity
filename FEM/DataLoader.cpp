#include <string>
#include <fstream>
#include <iostream>

#include "DataLoader.h"
#include "Node.h"

void DataLoader::load_nodes_and_elements(std::string input_file, std::vector<Node>& Nodes, std::vector<FiniteElement>& FiniteElements)
{
    std::string line;
    std::ifstream in(input_file);
    int NodeNumber, FiniteElementNumber, NodeId1, NodeId2, NodeId3, NodeId4;

    if (in.is_open())
    {
        in >> NodeNumber;
        std::cout << NodeNumber << std::endl;
        Nodes.resize(NodeNumber);
        for (int i = 0; i < NodeNumber; i++)
        {
            in >> Nodes[i].node_id >> Nodes[i].x >> Nodes[i].y >> Nodes[i].z;
        }

        in >> FiniteElementNumber;
        FiniteElements.resize(FiniteElementNumber);
        for (int i = 0; i < FiniteElementNumber; i++)
        {
            in >> FiniteElements[i].element_id >> NodeId1 >> NodeId2 >> NodeId3 >> NodeId4;
            FiniteElements[i].nodes.resize(4);
            FiniteElements[i].nodes[0] = Node::GetNode(Nodes, NodeId1);
            FiniteElements[i].nodes[1] = Node::GetNode(Nodes, NodeId2);
            FiniteElements[i].nodes[2] = Node::GetNode(Nodes, NodeId3);
            FiniteElements[i].nodes[3] = Node::GetNode(Nodes, NodeId4);
        }
    }
    in.close();
}