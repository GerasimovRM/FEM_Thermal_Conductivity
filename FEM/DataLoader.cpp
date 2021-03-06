#include <string>
#include <fstream>
#include <iostream>

#include "DataLoader.h"
#include "Node.h"
#include "GlobalData.h"


void DataLoader::load_nodes_and_elements(std::string input_file, std::vector<Node>& Nodes, std::vector<FiniteElement>& FiniteElements, std::vector<int>& NodesIdAmbient)
{
    std::string line;
    std::ifstream in(input_file);
    int NodeNumber, FiniteElementNumber, NodeId1, NodeId2, NodeId3, NodeId4;
    int n_ambient, node_id_ambient;

    if (in.is_open())
    {
        in >> NodeNumber;
        GlobalData::count_nodes = NodeNumber;
        std::cout << NodeNumber << std::endl;
        Nodes.resize(NodeNumber);
        for (int i = 0; i < NodeNumber; ++i)
        {
            in >> Nodes[i].node_id >> Nodes[i].x >> Nodes[i].y >> Nodes[i].z;
            Nodes[i].temperature = GlobalData::init_temperature;
        }

        in >> FiniteElementNumber;
        GlobalData::count_elements = FiniteElementNumber;
        FiniteElements.resize(FiniteElementNumber);
        for (int i = 0; i < FiniteElementNumber; ++i)
        {
            in >> FiniteElements[i].element_id >> NodeId1 >> NodeId2 >> NodeId3 >> NodeId4;
            FiniteElements[i].nodes.resize(4);
            FiniteElements[i].nodes[0] = Nodes[NodeId1];
            FiniteElements[i].nodes[1] = Nodes[NodeId2];
            FiniteElements[i].nodes[2] = Nodes[NodeId3];
            FiniteElements[i].nodes[3] = Nodes[NodeId4];
        }

        in >> n_ambient;
        NodesIdAmbient.resize(n_ambient);
        for (int i = 0; i < n_ambient; ++i)
        {
            in >> node_id_ambient;
            NodesIdAmbient[i] = node_id_ambient;
            Nodes[node_id_ambient].temperature = GlobalData::ambient_temperature;
        }
    }
    in.close();
}