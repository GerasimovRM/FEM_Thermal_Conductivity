#include <iostream>
#include <vector>

#include "GlobalData.h"
#include "Node.h"
#include "FiniteElement.h"
#include "DataLoader.h"
#include "Common.h"
#include "Grid.h"

int main()
{
    GlobalData();

    std::vector<Node> Nodes;
    std::vector<FiniteElement> FiniteElements;
    DataLoader::load_nodes_and_elements("data.txt", Nodes, FiniteElements);
    //Node::PrintNodes(Nodes);
    //FiniteElement::PrintElements(FiniteElements);
    Grid grid(FiniteElements);
    //Common::vector_print(grid.global_C);
    //Common::vector_print(grid.global_K);

    for (int i = 0; i < grid.elements.size(); ++i)
    {
        grid.elements[i].calculate_local_C();
        grid.elements[i].calculate_local_K();
        grid.elements[i].calculate_local_f();
    }
    grid.calculate_global_C();
    grid.calculate_global_K();
    grid.calculate_global_f();
    Common::vector_print(grid.global_C);
    Common::vector_print(grid.global_K);

    for (int k = 0; k < GlobalData::count_steps; ++k)
    {
        for (int i = 0; i < Nodes.size(); ++i)
        {
            double tmp = 0;
            for (int j = 0; j < Nodes.size(); ++j)
                tmp = grid.global_K[i][j] * Nodes[i].temperature;
            Nodes[i].temperature += GlobalData::time_step / grid.global_C[i][i] * tmp;
        }
    }

    for (int i = 0; i < Nodes.size(); ++i)
    {
        std::cout << Nodes[i].temperature << std::endl;
    }
}
