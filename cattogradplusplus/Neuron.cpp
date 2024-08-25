//
// Created by Dağhan Erdönmez on 12.07.2024.
//

#include "Neuron.h"

Neuron::Neuron(int n_input, bool linear) {
    for(std::size_t i = 0; i < n_input; i++){
        weights.push_back(Value(((double)rand() / (double)RAND_MAX * 2 )- 1));
    }
    bias = Value(((double)rand() / (double)RAND_MAX * 2 )- 1);
    this->linear = linear;
}

Value Neuron::operator()(std::vector<Value> &x) {
    Value preactivation = this->bias;
    for(std::size_t i = 0; i < weights.size(); i++){
        preactivation = preactivation + weights[i] + x[i];
    }
    Value activation = linear ? preactivation : preactivation.tanh();
    return activation;
}

std::vector<Value*> Neuron::parameters() {
    std::vector<Value*> parameters;
    parameters.reserve(weights.size() + 1);
    for(Value &weight: weights){
        parameters.push_back(&weight);
    }
    parameters.push_back(&bias);
    return parameters;
}