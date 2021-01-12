#include <vector>

#include "Grid.h"
#include "GlobalData.h"
#include "FiniteElement.h"
#include "Node.h"

Grid::Grid(std::vector<FiniteElement> elements)
{
    this->elements = elements;

    this->global_C.resize(GlobalData::count_nodes);
    for (int i = 0; i < this->global_C.size(); ++i)
        this->global_C[i].resize(GlobalData::count_nodes);

    for (int i = 0; i < this->global_C.size(); ++i)
        for (int j = 0; j < this->global_C[i].size(); ++j)
            global_C[i][j] = 0;
    

    this->global_K.resize(GlobalData::count_nodes);
    for (int i = 0; i < this->global_K.size(); ++i)
        this->global_K[i].resize(GlobalData::count_nodes);
    
    for (int i = 0; i < this->global_K.size(); ++i)
        for (int j = 0; j < this->global_K[i].size(); ++j)
            global_K[i][j] = 0;


    this->global_f.resize(GlobalData::count_nodes);

    for (int i = 0; i < this->global_f.size(); ++i)
        global_f[i] = 0;
}

void Grid::calculate_global_C()
{
    for (auto element : this->elements)
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                global_C[element.nodes[i].node_id][element.nodes[j].node_id] += element.local_C[i][j];
}

void Grid::calculate_global_K()
{
    for (auto element : this->elements)
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                global_K[element.nodes[i].node_id][element.nodes[j].node_id] += element.local_K[i][j];
}

void Grid::calculate_global_f()
{

}



