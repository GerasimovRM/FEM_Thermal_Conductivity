#include "GlobalData.h"

double GlobalData::time_step;
int GlobalData::count_steps;
double GlobalData::init_temperature;
double GlobalData::ambient_temperature;
double GlobalData::c;
double GlobalData::rho;

int GlobalData::count_x_nodes;
int GlobalData::count_y_nodes;
int GlobalData::count_z_nodes;
int GlobalData::count_nodes;

int GlobalData::count_x_elements_sq;
int GlobalData::count_y_elements_sq;
int GlobalData::count_z_elements_sq;
int GlobalData::count_elements_sq;

int GlobalData::count_x_elements;
int GlobalData::count_y_elements;
int GlobalData::count_z_elements;
int GlobalData::count_elements;

double** GlobalData::lambda;

GlobalData::GlobalData()
{
    time_step = 1e-3;
    count_steps = 10000;
    init_temperature = 300;
    ambient_temperature = 500;
    c = 300;
    rho = 2000;

    /*
    count_x_nodes = 3;
    count_y_nodes = 3;
    count_z_nodes = 3;
    count_nodes = count_x_nodes * count_y_nodes * count_z_nodes;

    count_x_elements_sq = (count_x_nodes - 1);
    count_y_elements_sq = (count_y_nodes - 1);
    count_z_elements_sq = (count_z_nodes - 1);
    count_elements_sq = count_x_elements_sq * count_y_elements_sq * count_z_elements_sq;

    count_x_elements = count_x_elements * 2;
    count_y_elements = count_y_elements * 2;
    count_z_elements = count_z_elements * 2;
    count_elements = count_elements_sq * 2;
    */

    lambda = new double* [3];
    for (int i = 0; i < 3; ++i)
    {
        lambda[i] = new double[3];
        for (int j = 0; j < 3; ++j)
            lambda[i][j] = 0;
    }
    lambda[0][0] = 100;
    lambda[1][1] = 100;
    lambda[2][2] = 100;

}