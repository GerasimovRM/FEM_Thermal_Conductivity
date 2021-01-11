#include <iostream>

#include "Node.h"

Node::Node(int node_id, double temperature, double x, double y, double z)
{
    this->node_id = node_id;
    this->temperature = temperature;
    this->x = x;
    this->y = y;
    this->z = z;
}

Node::Node() {}

Node* Node::GetNode(std::vector<Node> Nodes, int NodeId)
{
    Node* result = NULL;
    for (Node node : Nodes)
    {
        if (node.node_id == NodeId)
        {
            result = &node;
            break;
        }
    }
    return result;
}

void Node::Print()
{
    std::cout << "Node: ================================\n";
    std::cout << "Id:" << this->node_id << std::endl;
    std::cout << "Position X:" << this->x << std::endl;
    std::cout << "Position Y:" << this->y << std::endl;
    std::cout << "Position Z:" << this->z << std::endl;
    std::cout << "Temperature" << this->temperature << std::endl;
    std::cout << "======================================\n";
}

void Node::PrintNodes(std::vector<Node> Nodes)
{
    for (auto node : Nodes)
        node.Print();
}