#include "GlobalData.h"

GlobalData::GlobalData()
{
    this->time_step = 0.01;
    this->count_steps = 10;
    this->init_temperature = 300;
    this->ambient_temperature = 500;
    this->c = 700;
    this->rho = 7800;

    this->count_x_nodes = 3;
    this->count_y_nodes = 3;
    this->count_z_nodes = 3;
    this->count_nodes = this->count_x_nodes * this->count_y_nodes * this->count_z_nodes;
    
    this->count_x_elements_sq = (this->count_x_nodes - 1);
    this->count_y_elements_sq = (this->count_y_nodes - 1);
    this->count_z_elements_sq = (this->count_z_nodes - 1);
    this->count_elements_sq = this->count_x_elements_sq * this->count_y_elements_sq * this->count_z_elements_sq;

    this->count_x_elements = count_x_elements * 2;
    this->count_y_elements = count_y_elements * 2;
    this->count_z_elements = count_z_elements * 2;
    this->count_elements = this->count_elements_sq * 2;
}