#include <iostream>
#include "cattogradplusplus/atto.h"

int main() {

    Value a(3);
    Value b(2);

    Value c = 2.0 / a;

    std::cout << c << std::endl;
    return 0;
}
