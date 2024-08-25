//
// Created by Dağhan Erdönmez on 13.07.2024.
//

#ifndef CATTOGRADPLUSPLUS2_LAYER_H
#define CATTOGRADPLUSPLUS2_LAYER_H

#include "Neuron.h"

class Layer : public Module{
public:
    std::vector<Neuron> neurons;
    int n_input;
    int n_output;

    Layer(int n_input, int n_output, bool linear = false);
    std::vector<Value> operator()(std::vector<Value>& x);
    std::vector<Value*> parameters();

};


#endif //CATTOGRADPLUSPLUS2_LAYER_H
