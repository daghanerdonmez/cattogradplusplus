//
// Created by Dağhan Erdönmez on 12.07.2024.
//

#ifndef CATTOGRADPLUSPLUS2_NEURON_H
#define CATTOGRADPLUSPLUS2_NEURON_H

#include "Module.h"
#include "atto.h"

class Neuron: public Module {
public:
    std::vector<Value> weights;
    Value bias = Value(0);
    bool linear;

    Neuron(int n_input, bool linear);
    Value operator()(std::vector<Value>& x);
    std::vector<Value*> parameters();


};


#endif //CATTOGRADPLUSPLUS2_NEURON_H
