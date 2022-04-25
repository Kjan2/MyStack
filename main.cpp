#include "Stack.h"
#include <iostream>
#include <utility>
int main()
{
    Stack test(StackContainer::Vector);
    test.push(1.0);
    test.push(2.0);
    return 0;
}
