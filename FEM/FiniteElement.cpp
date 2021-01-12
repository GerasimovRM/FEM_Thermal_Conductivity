#include <iostream>
#include <vector>

#include "FiniteElement.h"
#include "GlobalData.h"
#include "Common.h"


void FiniteElement::calculate_local_C()
{
    double volume = this->calculate_volume();

    if (this->local_C == NULL)
    {
        this->local_C = new double* [4];
        for (int i = 0; i < 4; ++i)
            local_C[i] = new double [4];
    }
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            local_C[i][j] = GlobalData::c * GlobalData::rho * volume / 20.;
            if (i == j)
                local_C[i][j] *= 2;
        }
    }
    std::cout << "Volume: " << volume << std::endl;
    this->Print();
    Common::matrix_print(local_C, 4, 4);

}


void FiniteElement::calculate_local_K()
{
    double volume = this->calculate_volume();

    double b0 = (nodes[1].y - nodes[3].y) * (nodes[2].z - nodes[3].z) - (nodes[2].y - nodes[3].y) * (nodes[1].z - nodes[3].z);
    double b1 = (nodes[2].y - nodes[3].y) * (nodes[0].z - nodes[3].z) - (nodes[0].y - nodes[3].y) * (nodes[2].z - nodes[3].z);
    double b2 = (nodes[0].y - nodes[3].y) * (nodes[1].z - nodes[3].z) - (nodes[1].y - nodes[3].y) * (nodes[0].z - nodes[3].z);
    double b3 = b0 + b1 + b2;

    double c0 = (nodes[2].x - nodes[3].x) * (nodes[1].z - nodes[3].z) - (nodes[1].x - nodes[3].x) * (nodes[2].z - nodes[3].z);
    double c1 = (nodes[0].x - nodes[3].x) * (nodes[2].z - nodes[3].z) - (nodes[2].x - nodes[3].x) * (nodes[0].z - nodes[3].z);
    double c2 = (nodes[1].x - nodes[3].x) * (nodes[0].z - nodes[3].z) - (nodes[0].x - nodes[3].x) * (nodes[1].z - nodes[3].z);
    double c3 = -(c0 + c1 + c2);

    double d0 = (nodes[1].x - nodes[3].x) * (nodes[2].y - nodes[3].y) - (nodes[2].x - nodes[3].x) * (nodes[2].y - nodes[3].y);
    double d1 = (nodes[2].x - nodes[3].x) * (nodes[0].y - nodes[3].y) - (nodes[0].x - nodes[3].x) * (nodes[2].y - nodes[3].y);
    double d2 = (nodes[0].x - nodes[3].x) * (nodes[1].y - nodes[3].y) - (nodes[1].x - nodes[3].x) * (nodes[0].y - nodes[3].y);
    double d3 = -(d0 + d1 + d2);

    
    std::vector<std::vector<double>> B_vec = {
        {b0 / (6 * volume), b1 / (6 * volume), b2 / (6 * volume), b3 / (6 * volume)},
        {c0 / (6 * volume), c1 / (6 * volume), c2 / (6 * volume), c3 / (6 * volume)},
        {d0 / (6 * volume), d1 / (6 * volume), d2 / (6 * volume), d3 / (6 * volume)}
    }; 
    

    double** B = Common::vector_to_array(B_vec);
    double** B_trans = Common::matrix_transpose(B, 3, 4);
    double** B_trans_D = Common::matrix_product(B_trans, 4, 3, GlobalData::lambda, 3, 3);
    this->local_K = Common::matrix_product(B_trans_D, 4, 3, B, 3, 4);
}

void FiniteElement::calculate_local_f()
{
    this->local_f = new double[4];
    for (int i = 0; i < 4; ++i)
        this->local_f[i] = 0;
}

double FiniteElement::calculate_volume()
{
    std::vector<std::vector<double>> v = {
        {this->nodes[1].x - this->nodes[0].x, this->nodes[1].y - this->nodes[0].y, this->nodes[1].z - this->nodes[0].z },
        {this->nodes[2].x - this->nodes[0].x, this->nodes[2].y - this->nodes[0].y, this->nodes[2].z - this->nodes[0].z },
        {this->nodes[3].x - this->nodes[0].x, this->nodes[3].y - this->nodes[0].y, this->nodes[3].z - this->nodes[0].z }
    };
    return (v[0][0] * (v[1][1] * v[2][2] - v[1][2] * v[2][1]) 
        - v[0][1] * (v[1][0] * v[2][2] - v[1][2] * v[2][0]) 
        + v[0][2] * (v[1][0] * v[2][1] - v[1][1] * v[2][0])) / 6.;
}

bool FiniteElement::FiniteElementWithNode(int node_id)
{
    if (Node::GetNode(this->nodes, node_id) != NULL)
        return true;
    else
        return false;
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