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
    Node::PrintNodes(Nodes);
    FiniteElement::PrintElements(FiniteElements);
    Grid grid(FiniteElements);

    for (int i = 0; i < grid.elements.size(); ++i)
    {
        grid.elements[i].calculate_local_C();
        grid.elements[i].calculate_local_K();
        grid.elements[i].calculate_local_f();
    }
    grid.calculate_global_C();
    //grid.calculate_global_K();
    //grid.calculate_global_f();
    Common::matrix_print(Common::vector_to_array(grid.global_C), grid.global_C.size(), grid.global_C[0].size());
}
