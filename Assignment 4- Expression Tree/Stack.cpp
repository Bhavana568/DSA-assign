#include "Stack.h"
#include <iostream>
using namespace std;
template <class T>
Stack<T>::Stack()
{
    // TODO Auto-generated constructor stub
    top = NULL; //top initialized to null
}
//method to push element in stack
template <class T>
bool Stack<T>::isEmpty() // isempty function
{
    if (top == NULL) // iftop is  null stack is empty
    {
        return true;
    }
    else
    {
        return false;
    }
}
template <class T>
void Stack<T>::push(T x) // push function
{
    //if starts

    Node<T> *newnode = new Node<T>(); //node to new node
    newnode->data = x;
    newnode->next = top;
    top = newnode; //top to new node

} //method ends
  //func to pop element from stack
template <class T>
T Stack<T>::pop()
{
    Node<T> *temp;
    //	char popped;
    temp = top;      // set temp to point at start of list
                     //	popped = top->data;
    top = top->next; // change the head address to point at the second node
    delete (temp);
}
//display method
template <class T>
void Stack<T>::display()
{
    Node<T> *ptr;
    ptr = top;
    cout << "Stack elements are: " << endl; //to display all elements
    while (ptr != NULL)
    {
        cout << "|  " << ptr->data << "  |" << endl;
        ptr = ptr->next;
    }
}

template <class T>
T Stack<T>::peep() // function to peep th etop element in the stack
{
    if (!isEmpty())
    {
        return top->data;
    }
    else
    {
        cout << "empty" << endl;
    }
}
template <class T>
Stack<T>::~Stack()
{
    // TODO Auto-generated destructor stub
}