#include <iostream>
#include "cattogradplusplus/atto.h"
#include "cattogradplusplus/MLP.h"

using namespace std;

Value loss(Value y, Value label){
    return (y-label);
}

int main() {

    MLP mymlp(3, {4,4,1});

    std::vector<std::vector<Value>> xs = {
            {2.0, 3.0, -1.0},
            {3.0, -1.0, 0.5},
            {0.5, 1.0, 1.0},
            {1.0, 1.0, -1.0}
    };

    std::vector<Value> ys = {1.0, -1.0, -1.0, 1.0};

    for (int i = 0; i < 40; i++) {
        std::vector<Value> x = xs[i % (int)xs.size()];
        Value label = ys[i % (int)xs.size()];

        Value y = mymlp(x)[0];

        Value myloss = loss(y, label);

        mymlp.setGradientsZero();
        myloss.backward();

        for(auto& param: mymlp.parameters()){
            param->data += -0.1 * param->gradient;
        }

        cout << "Step: " << i << ", Loss: " << myloss.data << endl;
    }

//    Value a = Value(2.0);
//    Value b = Value(4.0);
//    Value c = Value(-1.0);
//
//    Value d = a+b; //6
//    Value e = c.pow(2.0); //1
//    Value f = d-e; //5
//
//    Value x = b-a;
//    Value y = a * -1;
//
//    f.backward();
//    return 0;
}


