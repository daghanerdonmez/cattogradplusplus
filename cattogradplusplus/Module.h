//
// Created by Dağhan Erdönmez on 12.07.2024.
//

#ifndef CATTOGRADPLUSPLUS2_MODULE_H
#define CATTOGRADPLUSPLUS2_MODULE_H

#include <vector>


class Module {
public:
    void setGradientsZero();
    std::vector<double*> parameters();
};


#endif //CATTOGRADPLUSPLUS2_MODULE_H
