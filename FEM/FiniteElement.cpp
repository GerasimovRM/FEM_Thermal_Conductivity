#include <iostream>

#include "FiniteElement.h"

void FiniteElement::Print()
{
    std::cout << "FiniteElement: =======================\n";
    std::cout << "Id:" << this->element_id << std::endl;
    std::cout << "Id Node 1:" << this->nodes[0].node_id << std::endl;
    std::cout << "Id Node 2:" << this->nodes[1].node_id << std::endl;
    std::cout << "Id Node 3:" << this->nodes[2].node_id << std::endl;
    std::cout << "Id Node 4:" << this->nodes[3].node_id << std::endl;
    std::cout << "======================================\n";
}

void FiniteElement::PrintElements(std::vector<FiniteElement> FiniteElements)
{
    for (auto element : FiniteElements)
        element.Print();
}