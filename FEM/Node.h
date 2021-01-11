#include <vector>

#pragma once
class Node
{
public:
    int node_id;
    double temperature;
    double x;
    double y;
    double z;

    Node(int, double, double, double, double);
    Node();
    static Node GetNode(std::vector<Node>, int);
};
