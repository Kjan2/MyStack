#include "Stack.h"
#include "LinkedListStack.h"
#include "VectorStack.h"
#include "StackImplementation.h"
#include <stdexcept>
#include <iostream>

Stack::Stack(StackContainer container)
    : _containerType(container)
{
    switch (container)
    {
        case StackContainer::List:
        {
            _pimpl = static_cast<IStackImplementation*>(new LinkedList());
            break;
        }
        case StackContainer::Vector: 
        {
            _pimpl = static_cast<IStackImplementation*>(new Vector());
            break;
        }
        default:
            throw std::runtime_error("Неизвестный тип контейнера");
    }
}

Stack::Stack(const ValueType* valueArray, const size_t arraySize, StackContainer container) 
    : _containerType(container)
{
    switch (container)
    {
        case StackContainer::List:
        {
            _pimpl = static_cast<IStackImplementation*>(new LinkedList());

            for (int i = 0; i < arraySize; i++)
            {
                _pimpl->push(valueArray[i]);
            }

            break;
        }
        case StackContainer::Vector:
        {
            _pimpl = static_cast<IStackImplementation*>(new Vector(valueArray, arraySize)); 
            break;
        }
        default:
            throw std::runtime_error("Неизвестный тип контейнера");
    }
}

Stack::Stack(const Stack& copyStack)
{
   
    switch (copyStack._containerType)
    {
        case StackContainer::List: 
        {
            _pimpl = static_cast<IStackImplementation*>(new LinkedList(*(static_cast<LinkedList*>(copyStack._pimpl))));
            this->_containerType = StackContainer::List;
            break;
        }
        case StackContainer::Vector:
        {
            _pimpl = static_cast<IStackImplementation*>(new Vector(*(static_cast<Vector*>(copyStack._pimpl))));
            this->_containerType = StackContainer::Vector;
            break;
        }
        default:
            throw std::runtime_error("Неизвестный тип контейнера");
    }
}

Stack& Stack::operator=(const Stack& copyStack)
{
    switch (copyStack._containerType)
    {
        case StackContainer::List: {
            if (this == &copyStack)
            {
                return *this;
            }
            delete this->_pimpl;
            _pimpl = static_cast<IStackImplementation*>(new LinkedList(*(static_cast<LinkedList*>(copyStack._pimpl))));
            this->_containerType = StackContainer::List;
            return *this;
            break;
        }

        case StackContainer::Vector: {
            if (this == &copyStack)
            {
                return *this; 
            }
            delete this->_pimpl;
            _pimpl = static_cast<IStackImplementation*>(new Vector(*(static_cast<Vector*>(copyStack._pimpl))));
            this->_containerType = StackContainer::Vector;
            return *this;
            break;
        }
        default:
            throw std::runtime_error("Неизвестный тип контейнера");
    }
}

Stack::Stack(Stack&& moveStack) noexcept
{
    switch (moveStack._containerType)
    {
        case StackContainer::List: {
            this->_pimpl = moveStack._pimpl;
            moveStack._pimpl = nullptr;
            this->_containerType = StackContainer::List;
            break;
        }
        case StackContainer::Vector: {
            this->_pimpl = moveStack._pimpl;
            moveStack._pimpl = nullptr;
            this->_containerType = StackContainer::Vector;
            break;
        }

        default: 
        {
        }
    }
}

Stack& Stack::operator=(Stack&& moveStack) noexcept
{
    switch (moveStack._containerType)
    {
        case StackContainer::List: 
        {   
            if (this == &moveStack)
            {
                return *this;
            }
            delete this->_pimpl;
            this->_pimpl = moveStack._pimpl;
            moveStack._pimpl = nullptr;
            this->_containerType = StackContainer::List;
            return *this;
            break;
        }
        case StackContainer::Vector: 
        {
            if (this == &moveStack)
            {
                return *this;
            }
            delete this->_pimpl;
            this->_pimpl = moveStack._pimpl;
            moveStack._pimpl = nullptr;
            this->_containerType = StackContainer::Vector;
            return *this;
            break;
        }

        default:
        {
            return *this;
        }
    }    
}


Stack::~Stack()
{
    delete _pimpl; 
}

void Stack::push(const ValueType& value)
{
    // можно, т.к. push определен в интерфейсе
    _pimpl->push(value);
}

void Stack::pop()
{
    _pimpl->pop();
}

const ValueType& Stack::top() const
{
    return _pimpl->top();
}

bool Stack::isEmpty() const
{
    return _pimpl->isEmpty();
}

size_t Stack::size() const
{
    return _pimpl->size();
}

