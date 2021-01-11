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
    for (int i = 0; i < GlobalData::count_nodes; ++i)
        for (int j = i + 1; j < GlobalData::count_nodes;  ++j)
        {
            // ������� ��� �������� � ����� ����� i j
            std::vector<FiniteElement> elements;
            for (auto element : this->elements)
                if (element.FiniteElementWithNode(i) && element.FiniteElementWithNode(j))
                    elements.push_back(element);

        }
}

