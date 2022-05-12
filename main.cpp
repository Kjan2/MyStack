#include "Stack.h"
#include <iostream>
#include <utility>
#include <typeinfo>
#include "LinkedListStack.h"

int main()
{
    LinkedList test;
    test.push(3);
    test.push(4);
    test.print();
    test.pop();
    test.print();
    test.pop();
    test.pop(); 


    return 0;
}

