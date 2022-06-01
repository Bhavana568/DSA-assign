#ifndef STACK_H_
#define STACK_H_
#include <cstdlib>
template <typename T> // template used
//structure defined
struct Node
{
    // node consists of data and next part storing the address of the next node
    T data;
    Node<T> *next;
};
template <class T>
class Stack // class stack
{
    Node<T> *top;

public:
    // functions to be used :
    Stack();
    bool isFull();
    void push(T x);
    T pop();
    void display();
    bool isEmpty();
    T peep();
    virtual ~Stack();
};
#endif /* STACK_H_ */