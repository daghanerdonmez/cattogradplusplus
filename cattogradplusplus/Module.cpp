//
// Created by Dağhan Erdönmez on 12.07.2024.
//

#include "Module.h"

void Module::setGradientsZero() {
    std::vector<double*> params = parameters();
    for(double *param : params){
        *param = 0.0;
    }
}

std::vector<double*> Module::parameters() {
    return {};
}