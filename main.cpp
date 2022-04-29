#include "Stack.h"
#include <iostream>
#include <utility>

Stack& shit()
{
    Stack test(StackContainer::List);
    return test;
}

int main()
{
    Stack test(StackContainer::List);
    test.push(1.0);
    test.push(2.0);
    std::cout << test.top();
    Stack test2 = std::move(test);
    std::cout << test2.top() << test2.size(); 
    test2.pop();



    return 0;
}
