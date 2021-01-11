#include <iostream>
#include <vector>

#include "FiniteElement.h"
#include "GlobalData.h"


double** FiniteElement::calculate_local_C()
{
    if (this->local_C == NULL)
    {
        this->local_C = new double* [4];
        for (int i = 0; i < 4; ++i)
            local_C[i] = new double [4];
    }
    /// TODO:
}


double** FiniteElement::calculate_local_K()
{

}

double* FiniteElement::calculate_local_f()
{

}

double FiniteElement::calculate_volume()
{
    std::vector<std::vector<double>> v = {
        {this->nodes[1].x - this->nodes[0].x, this->nodes[1].y - this->nodes[0].y, this->nodes[1].z - this->nodes[0].z },
        {this->nodes[2].x - this->nodes[0].x, this->nodes[2].y - this->nodes[0].y, this->nodes[2].z - this->nodes[0].z },
        {this->nodes[3].x - this->nodes[0].x, this->nodes[3].y - this->nodes[0].y, this->nodes[3].z - this->nodes[0].z }
    };
    return (v[0][0] * (v[1][1] * v[2][2] - v[1][2] * v[2][1]) 
        - v[0][1] * (v[1][0] * v[2][1] - v[1][2] * v[2][0]) 
        + v[0][2] * (v[1][0] * v[2][1] - v[1][1] * v[2][0])) / 6.;
}


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