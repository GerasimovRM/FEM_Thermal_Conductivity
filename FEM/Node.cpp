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