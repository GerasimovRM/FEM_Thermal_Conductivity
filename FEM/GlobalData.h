#pragma once
class GlobalData
{
public:
    static double time_step;
    static int count_steps;
    static double init_temperature;
    static double ambient_temperature;
    static double c;
    static double rho;

    static int count_x_nodes;
    static int count_y_nodes;
    static int count_z_nodes;
    static int count_nodes;

    static int count_x_elements_sq;
    static int count_y_elements_sq;
    static int count_z_elements_sq;
    static int count_elements_sq;

    static int count_x_elements;
    static int count_y_elements;
    static int count_z_elements;
    static int count_elements;

    GlobalData();
};

