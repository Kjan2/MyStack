#include "Stack.h"
#include <iostream>
#include <utility>



int main()
{
    Stack test(StackContainer::List);
    test.push(1.0);
    test.push(2.0);
    std::cout << test.top();
    Stack test2(test);
    std::cout << test2.top();
    test2.pop();
    std::cout << test2.top();
    return 0;
}
