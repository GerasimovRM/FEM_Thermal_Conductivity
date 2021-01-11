#include "Grid.h"
#include "GlobalData.h"

Grid::Grid(std::vector<FiniteElement> elements)
{
    this->elements = elements;
    

    this->global_A.resize(GlobalData::count_nodes);
    for (int i = 0; i < this->global_A.size(); ++i)
        this->global_A[i].resize(GlobalData::count_nodes);

    for (int i = 0; i < this->global_A.size(); ++i)
        for (int j = 0; j < this->global_A[i].size(); ++j)
            global_A[i][j] = 0;
    

    this->global_B.resize(GlobalData::count_nodes);
    for (int i = 0; i < this->global_B.size(); ++i)
        this->global_B[i].resize(GlobalData::count_nodes);
    
    for (int i = 0; i < this->global_B.size(); ++i)
        for (int j = 0; j < this->global_B[i].size(); ++j)
            global_B[i][j] = 0;


    this->global_f.resize(GlobalData::count_nodes);

    for (int i = 0; i < this->global_f.size(); ++i)
        global_f[i] = 0;
}

void Grid::calculate_global_A()
{
    //for (int k = 0; k < this->elements.size(); ++k)
        //for (int j = 0; j < )
}
