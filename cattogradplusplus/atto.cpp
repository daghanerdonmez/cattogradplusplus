//
// Created by Dağhan Erdönmez on 10.07.2024.
//

#include "atto.h"

Value::Value(double data, std::set<Value*> children, std::string operation)
        : data(data), gradient(0.0), _children(children), _operation(operation) {
    _backward = []() {};
}

Value Value::operator+(Value& other) {
    Value out(data + other.data, { this, &other }, "+");
    out._backward = [this, &other, &out]() {
        this->gradient += out.gradient;
        other.gradient += out.gradient;
    };
    return out;
}

Value Value::operator+(double other) {
    auto* temp = new Value(other);
    return *this + *temp;
}

Value Value::operator*(Value& other) {
    Value out(data * other.data, { this, &other}, "*");
    out._backward = [this, &other, &out]() {
        this->gradient += other.data * out.gradient;
        other.gradient += this->data * out.gradient;
    };
    return out;
}

Value Value::operator*(double other) {
    auto* temp = new Value(other);
    return *this * *temp;
}

Value Value::operator-() {
    return *this * -1;
}

Value Value::operator-(Value& other) {
    Value out(data - other.data, { this, &other }, "-");
    out._backward = [this, &other, &out]() {
        this->gradient += out.gradient;
        other.gradient -= out.gradient;
    };
    return out;
}

Value Value::operator-(double other) {
    auto* temp = new Value(other);
    return *this - *temp;
}

Value Value::operator/(Value& other) {
    Value temp = other.pow(-1);
    return *this * temp;
}

Value Value::operator/(double other) {
    auto* temp = new Value(other);
    return *this / *temp;
}

Value Value::pow(double other) {
    assert(other == static_cast<int>(other));
    Value out(std::pow(data, other), { this }, "**" + std::to_string(other));
    out._backward = [this, &other, &out]() {
        this->gradient += (other * (std::pow(this->data, (other -1)))) * out.gradient;
    };
    return out;
}

Value Value::relu() {
    Value out(data < 0 ? 0 : data, { this }, "ReLU");
    out._backward = [this, &out]() {
        this->gradient += (out.data > 0) * out.gradient;
    };
    return out;
}

Value Value::tanh() {
    double t = std::tanh(data);
    Value out(t, { this }, "tanh");
    out._backward = [this, &out, t]() {
        this->gradient += (1 - t * t) * out.gradient;
    };
    return out;
}

Value operator+(double lhs, Value& rhs) {
    auto* temp = new Value(lhs);
    return *temp + rhs;
}

Value operator*(double lhs, Value& rhs) {
    auto* temp = new Value(lhs);
    return *temp * rhs;
}

Value operator-(double lhs, Value& rhs) {
    auto* temp = new Value(lhs);
    return *temp - rhs;
}

Value operator/(double lhs, Value& rhs) {
    auto* temp = new Value(lhs);
    return *temp / rhs;
}

void Value::backward() {
    std::vector<Value*> topological_sorted;
    std::set<Value*> visited;

    std::function<void(Value*)> build_topological_sort = [&](Value* node) {
        if (visited.find(node) == visited.end()) {
            visited.insert(node);
            for (auto child : node->_children) {
                build_topological_sort(child);
            }
            topological_sorted.push_back(node);
        }
    };

    build_topological_sort(this);

    this->gradient = 1.0;
    for (auto it = topological_sorted.rbegin(); it != topological_sorted.rend(); it++){
        // Alternative: (*it)->_backward();
        (*(*it))._backward();
    }
}

std::ostream& operator<<(std::ostream& os, const Value& v) {
    os << "Value(Data: " << v.data << ", Gradient: " << v.gradient << ")";
    return os;
}
