#include <iostream>
#include <vector>

#include <iostream>
#include <fstream>
#include <string>
//Строка с количеством узлов
//Список узлов x,y,z
//Строка с количеством элементов
//Список элементов

#include "GlobalData.h"
#include "Node.h"

int main()
{
    GlobalData();
    std::vector<Node> nodes(GlobalData::count_nodes);
    //std::

    int main()
    {
        int NodeNumber, FiniteElementNumber;

        std::string inputFile, line;
        inputFile = "temp_model.k";

        std::ifstream in(inputFile);

        if (in.is_open())
        {
            in >> NodeNumber;
            Node* Nodes = new Node[NodeNumber];
            for (int i = 0; i < NodeNumber; i++)
            {
                in >> Nodes[i].id >> Nodes[i].x >> Nodes[i].y >> Nodes[i].z;
            }

            in >> FiniteElementNumber;
            FiniteElement* FiniteElements = new FiniteElement[FiniteElementNumber];
            for (int i = 0; i < FiniteElementNumber; i++)
            {
                in >> FiniteElements[i].id >> FiniteElements[i].
            }
        }
        in.close();
    }

}
