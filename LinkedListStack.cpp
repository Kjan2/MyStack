#include "LinkedListStack.h"
#include <iostream>

LinkedList::LinkedList(const LinkedList& copyList)
{
    Node* node = copyList._head;


    while (node)
    {
        this->push(node->value);
        node = node->next;
    } 
}


LinkedList& LinkedList::operator=(const LinkedList& copyList)
{
    Node* node = copyList._head;
    this->_head = copyList._head;

    while (node)
    {
        this->push(node->value);
        node = node->next;
    } 

    return *this;
}

LinkedList::LinkedList(LinkedList&& moveList)
{
    Node* node = moveList._head;
    this->_head = moveList._head;

    while (node)
    {
        this->push(node->value);
        node = node->next;
    }

    Node* nodeDelete = moveList._head;
    while(nodeDelete)
    {
        Node* next = nodeDelete->next;
        delete nodeDelete;
        nodeDelete = next;
    }
    moveList._head = nullptr;
}

LinkedList& LinkedList::operator=(LinkedList&& moveList)
{
    Node* node = moveList._head;
    this->_head = moveList._head;

    while (node)
    {
        this->push(node->value);
        node = node->next;
    }

    Node* nodeDelete = moveList._head;
    while(nodeDelete)
    {
        Node* next = nodeDelete->next;
        delete nodeDelete;
        nodeDelete = next;
    }
    moveList._head = nullptr;

    return *this;
}


LinkedList::~LinkedList()
{
    Node* nodeDelete = _head;
    while(nodeDelete)
    {
        Node* next = nodeDelete->next;
        delete nodeDelete;
        nodeDelete = next;
    }
    _head = nullptr;
}


LinkedList::Node::Node(Value val, Node* nextNode) : value(val), next(nextNode)
{

}

LinkedList::Iterator::Iterator(Node* node) : _node(node) 
{

}

LinkedList::Iterator::~Iterator()
{

}

LinkedList::Iterator& LinkedList::Iterator::operator++()
{
    _node = _node->next;
    return *this;
}

LinkedList::Node& LinkedList::Iterator::operator*()
{
    return *_node;
}

const LinkedList::Node& LinkedList::Iterator::operator*() const
{
    return *_node;
}

LinkedList::Node*  LinkedList::Iterator::operator->()
{
    return _node;
}

const LinkedList::Node* LinkedList::Iterator::operator->() const
{
    return _node;
}

void LinkedList::push(const Value& value)
{
    if (!_head)
    {
        _head = new Node(value, nullptr);
    }

    Node* node = new Node(value, nullptr);
    Node* curr = _head;
    while(curr->next)
    {
        curr = curr->next;
    }
    
    curr->next = node;
}

void LinkedList::pop()
{
    if (!_head)
    {
        return;
    }
    

    Node* curr = _head;

    while(curr->next->next)
    {
        curr = curr->next;
    }

    if(curr == _head && !curr->next)
    {
        _head = nullptr;
        return;
    }
    
    delete curr->next;

    curr->next = nullptr;
}

void LinkedList::print(Node* node)
{
    if (node == nullptr)
    {
        std::cout << "null";
        return;
    }
    std::cout << node->value <<"->";
    print(node->next);
}

void LinkedList::print()
{
    this->print(_head);
}

const Value& LinkedList::top() const
{
    Node* node = _head;
    while(node->next)
    {
        node = node->next;
    }
    return node->value;
}

bool LinkedList::isEmpty() const
{
    return !_head;
}

size_t LinkedList::size() const
{
    if (!_head)   
    {
        return 0;
    }

    int i = 0;
    Node* node = _head;
    while(node->next)
    {
        node = node->next;
        i++;
    }
    return i;
}
