//
// Created by Dağhan Erdönmez on 13.07.2024.
//

#include "Layer.h"

Layer::Layer(int n_input, int n_output, bool linear) {
    for(int i = 0; i < n_output; i++){
        neurons.push_back(Neuron(n_input, linear));
    }
    this->n_input = n_input;
    this->n_output = n_output;
}

std::vector<Value> Layer::operator()(std::vector<Value>& x){
    std::vector<Value> output;
    output.reserve(n_output);
    for(int i = 0; i < n_output; i++){
        output.push_back(neurons[i](x));
    }
    return output;
}

std::vector<Value*> Layer::parameters() {
    std::vector<Value*> parameters;
    parameters.reserve((neurons[0].weights.size() + 1) * n_output);
    for (int i = 0; i < n_output; i++) {
        Neuron neuron = neurons[i];
        parameters.insert(parameters.end(), neuron.parameters().begin(), neuron.parameters().end());
    }
    return parameters;
}
