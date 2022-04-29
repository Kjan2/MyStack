#include "Stack.h"
#include <iostream>
#include <utility>

/*Stack& shit()
{
    Stack shit;
    return shit;
}*/

int main()
{
    Stack test(StackContainer::List);
    test.push(1.0);
    test.push(2.0);
    std::cout << test.top(); 
    Stack test2(test);
    std::cout << test2.top() << (int)test2._containerType;
    test2 = test2;
    //Stack test3;
    //test3 = std::move(shit());
    //std::cout << test2.top() << " " << test2.size();
    //test2.pop();
    //std::cout << test2.top();
    return 0;
}

