#include "Stack.h"
#include <iostream>
#include <utility>
#include <typeinfo>


int main()
{


    double array[] = {1., 2., 3., 4., 5., 6., 7};
    Stack test (array, 7, StackContainer::List);
    std::cout << (int)test._containerType;
    //Stack test2(StackContainer::List);
    Stack test2(test);
    test2.push(1.);
    test2.push(2.);
    test2.push(3.);
    for (int i = 0; i < 7; i++)
    {
        std::cout << test2.top() << std::endl;
        test2.pop();
    }

    return 0;
}

