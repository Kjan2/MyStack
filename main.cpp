#include "Stack.h"
#include <iostream>
#include <utility>
#include <typeinfo>
Stack& shit()
{
    Stack shit(StackContainer::Vector);
    return shit;
}

int main()
{
    Stack test(StackContainer::List);
    test.push(1.0);
    test.push(2.0);

    Stack test2(test);
    Stack test3(StackContainer::Vector);
    test3 = std::move(test2);
    std::cout << test2.top() << " " << test2.size() << std::endl;
    test2.pop();
    std::cout << test2.top() << " " << test2.size() << std::endl;
    std::cout << typeid(&test2).name() << std::endl;
    //test2.pop();
    //std::cout << test2.top();
    return 0;
}

