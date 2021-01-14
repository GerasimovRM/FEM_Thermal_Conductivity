#include <iostream>
#include <vector>
#include <fstream>

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
    std::vector<int> NodesIdAmbient;
    std::vector<FiniteElement> FiniteElements;

    DataLoader::load_nodes_and_elements("big_data.txt", Nodes, FiniteElements, NodesIdAmbient);

    //Node::PrintNodes(Nodes);
    //FiniteElement::PrintElements(FiniteElements);

    Grid grid(FiniteElements);
    //Common::vector_print(grid.global_C);
    //Common::vector_print(grid.global_K);

    for (int i = 0; i < grid.elements.size(); ++i)
    {
        grid.elements[i].calculate_local_C();
        grid.elements[i].calculate_local_K();

    }
    grid.calculate_global_C();
    grid.calculate_global_K();
    grid.calculate_global_f(NodesIdAmbient);

    std::ofstream out_file("dump.txt");

    for (int k = 0; k < GlobalData::count_steps; ++k)
    {
        out_file << GlobalData::count_nodes << std::endl << std::endl;
        for (int i = 0; i < Nodes.size(); ++i)
        {
            double tmp = 0;
            for (int j = 0; j < Nodes.size(); ++j)
                tmp = grid.global_K[i][j] * Nodes[i].temperature;
            Nodes[i].temperature += GlobalData::time_step / grid.global_C[i][i] * tmp;
            out_file << Nodes[i].node_id << "\t" << Nodes[i].x << "\t" << Nodes[i].y << "\t" << Nodes[i].z << "\t" << Nodes[i].temperature << "\n";
        }
    }
    
    /*for (int step = 0; step < 10; ++step)
    {
        /*for (int i = 0; i < grid.elements.size(); ++i)
        {
            grid.elements[i].calculate_local_C();
            grid.elements[i].calculate_local_K();

        }
        grid.calculate_global_C();
        grid.calculate_global_K();
        grid.calculate_global_f(NodesIdAmbient);
        //Common::vector_print(grid.global_C);
        //Common::vector_print(grid.global_K);
        
        double** left = Common::vector_to_array(grid.global_C);
        //Common::matrix_print(left, GlobalData::count_nodes, GlobalData::count_nodes);

        double* right = Common::vector_to_array(grid.global_f);
        //Common::array_print(right, GlobalData::count_nodes);

        double* temperature = new double[GlobalData::count_nodes];
        for (int i = 0; i < GlobalData::count_nodes; ++i)
            temperature[i] = Nodes[i].temperature;
        //Common::array_print(temperature, GlobalData::count_nodes);

        double* K_temperature = Common::matrix_product(
            Common::vector_to_array(grid.global_K),
            GlobalData::count_nodes,
            GlobalData::count_nodes,
            temperature,
            GlobalData::count_nodes);
        //Common::array_print(K_temperature, GlobalData::count_nodes);

        double* C_temperature = Common::matrix_product(
            Common::vector_to_array(grid.global_C),
            GlobalData::count_nodes,
            GlobalData::count_nodes,
            temperature,
            GlobalData::count_nodes);
        //Common::array_print(C_temperature, GlobalData::count_nodes);

        right = Common::array_minus_array(right, K_temperature, GlobalData::count_nodes);
        //Common::array_print(right, GlobalData::count_nodes);

        right = Common::array_product_number(right, GlobalData::count_nodes, GlobalData::time_step);
        //Common::array_print(right, GlobalData::count_nodes);

        right = Common::array_plus_array(right, C_temperature, GlobalData::count_nodes);
        //Common::array_print(right, GlobalData::count_nodes);

        double* result = Common::gauss(left, right, GlobalData::count_nodes);
        // Common::array_print(result, GlobalData::count_nodes);
        for (int i = 0; i < GlobalData::count_nodes; ++i)
            Nodes[i].temperature = result[i];
        out_file << GlobalData::count_nodes << std::endl << std::endl;
        for (int i = 0; i < GlobalData::count_nodes; ++i)
            out_file << Nodes[i].node_id << "\t" << Nodes[i].x << "\t" << Nodes[i].y << "\t" << Nodes[i].z << "\t" << Nodes[i].temperature << "\n";
    }*/
    out_file.close();
}
