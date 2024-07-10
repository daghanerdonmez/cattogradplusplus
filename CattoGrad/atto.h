#ifndef VALUE_H
#define VALUE_H

#include <iostream>
#include <string>
#include <set>
#include <functional>
#include <cassert>
#include <vector>
#include <cmath>

class Value {
public:
    double data;
    double gradient;
    std::string _operation;
    std::set<Value*> _children;
    std::function<void()> _backward;

    Value(double data, std::set<Value*> children = {}, std::string operation = "");

    Value operator+(Value& other);
    Value operator+(double other);

    Value operator*(Value& other);
    Value operator*(double other);

    Value operator-();
    Value operator-(Value& other);
    Value operator-(double other);

    Value operator/(Value& other);
    Value operator/(double other);

    Value pow(double other);
    Value relu();
    Value tanh();
    void backward();
};

#endif // VALUE_H
