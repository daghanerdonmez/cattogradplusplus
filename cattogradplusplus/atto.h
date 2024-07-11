//
// Created by Dağhan Erdönmez on 10.07.2024.
//

#ifndef CATTOGRADPLUSPLUS_ATTO_H
#define CATTOGRADPLUSPLUS_ATTO_H

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

    friend Value operator+(double lhs, Value& rhs);
    friend Value operator*(double lhs, Value& rhs);
    friend Value operator-(double lhs, Value& rhs);
    friend Value operator/(double lhs, Value& rhs);
    friend std::ostream& operator<<(std::ostream& os, const Value& v);
};


#endif //CATTOGRADPLUSPLUS_ATTO_H
