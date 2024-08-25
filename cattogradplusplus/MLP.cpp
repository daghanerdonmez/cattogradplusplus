//
// Created by Dağhan Erdönmez on 13.07.2024.
//

#include "MLP.h"

MLP::MLP(int n_input, std::vector<int> n_outputs) {
    this->n_input = n_input;
    this->n_outputs = n_outputs;
    sizes.reserve(n_outputs.size() + 1);
    sizes.push_back(n_input);
    sizes.insert(sizes.end(), n_outputs.begin(), n_outputs.end());

    for (int i = 0; i < sizes.size()-1; i++) {
        layers.push_back(Layer(sizes[i], sizes[i+1], sizes.size()==i+2));
    }
}

std::vector<Value> MLP::operator()(std::vector<Value> &x) {
    for (auto & layer : layers) {
        x = layer(x);
    }
    return x;
}

std::vector<Value*> MLP::parameters() {
    std::vector<Value*> parameters;
    for(auto& layer: layers){
        parameters.insert(parameters.end(), layer.parameters().begin(), layer.parameters().end());
    }
    return parameters;
}