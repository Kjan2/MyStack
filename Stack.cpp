#include "Stack.h"
#include "LinkedListStack.h"
#include "VectorStack.h"
#include "StackImplementation.h"
#include <stdexcept>
#include <stdio.h>

Stack::Stack(StackContainer container)
    : _containerType(container)
{
    switch (container)
    {
    case StackContainer::List: {
        _pimpl = static_cast<IStackImplementation*>(new LinkedList());
        break;
    }
    case StackContainer::Vector: {
        _pimpl = static_cast<IStackImplementation*>(new Vector());
        break;
    }
    default:
        throw std::runtime_error("Неизвестный тип контейнера");
    }
}

Stack::Stack(const ValueType* valueArray, const size_t arraySize, StackContainer container)
{
    switch (container)
    {
    case StackContainer::List: {
        _pimpl = static_cast<IStackImplementation*>(new LinkedList());

        for (int i = 0; i < arraySize; i++)
        {
            _pimpl->push(valueArray[i]);
        }

        break;
    }
    case StackContainer::Vector: {
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
    case StackContainer::List: {
        _pimpl = static_cast<IStackImplementation*>(new LinkedList(*(static_cast<LinkedList*>(copyStack._pimpl))));
        break;
    }
    case StackContainer::Vector: {
        this->_pimpl = static_cast<IStackImplementation*>(new Vector(*(static_cast<Vector*>(copyStack._pimpl))));
        break;
    }
    default:
        throw std::runtime_error("Неизвестный тип контейнера");
    }
}

Stack& Stack::operator=(const Stack& copyStack)
{
    // TODO: вставьте здесь оператор return
    switch (copyStack._containerType)
    {
    case StackContainer::List: {
        _pimpl = static_cast<IStackImplementation*>(new LinkedList(*(static_cast<LinkedList*>(copyStack._pimpl))));
        return *this;
        break;
    }

    case StackContainer::Vector: {
        *(static_cast<Vector*>(this->_pimpl)) = *(static_cast<Vector*>(copyStack._pimpl));
        return *this;
        break;
    }
    default:
        throw std::runtime_error("Неизвестный тип контейнера");
    }

}

/*Stack& Stack::operator=(Stack&& moveStack) noexcept
{
    // TODO: вставьте здесь оператор return
    switch (moveStack._containerType)
    {
    case StackContainer::List: {
        _pimpl = static_cast<IStackImplementation*>(new LinkedList());    // конкретизируйте под ваши конструкторы, если надо
        break;
    }
    case StackContainer::Vector: {
        *(static_cast<Vector*>(this->_pimpl)) = static_cast<Vector&&>(*(static_cast<Vector*>(moveStack._pimpl)));    // конкретизируйте под ваши конструкторы, если надо
        return *this;
        break;
    }

    default: {
        throw std::runtime_error("Неизвестный тип контейнера");
    }
    }
}
*/

Stack::~Stack()
{
    delete _pimpl;        // композиция!
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

