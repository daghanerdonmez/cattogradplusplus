//
// Created by Dağhan Erdönmez on 13.07.2024.
//

#ifndef CATTOGRADPLUSPLUS2_MLP_H
#define CATTOGRADPLUSPLUS2_MLP_H

#include "Layer.h"

class MLP : public Module {
public:
    std::vector<Layer> layers;
    int n_input;
    std::vector<int> n_outputs;
    std::vector<int> sizes;

    MLP(int n_input, std::vector<int> n_outputs);
    std::vector<Value> operator()(std::vector<Value>& x);
    std::vector<Value*> parameters();
};


#endif //CATTOGRADPLUSPLUS2_MLP_H
