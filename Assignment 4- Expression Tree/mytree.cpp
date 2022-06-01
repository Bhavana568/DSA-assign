#include <iostream>
#include "Stack.h"
#include "Stack.cpp"
#include "mytree.h"

mytree::mytree() // constructor of tree
{
    root = NULL; // root initialized as null
}
void mytree::input() // function to take input from the user
{
    cout << "Enter the postfix expression:" << endl; // input of the postfix expression
    cin >> ip;
}
void mytree::create() // function to create a tree
{
    Stack<tnode *> s; // obj of stack s created
    int i;
    for (i = 0; ip[i] != '\0'; i++) // until null of the string is traversed
    {
        if (isalnum(ip[i])) // if a number or a character comes in the expression
        {
            tnode *temp = new tnode; // create a new node
            temp->data = ip[i];      // char goes in the data part of the node
            temp->lchild = NULL;     // left child declared as null
            temp->rchild = NULL;     // right child declared as null
            s.push(temp);            // new node pushed in the stack
        }
        else // for operator in the expression
        {
            tnode *temp = new tnode; // new node created
            temp->data = ip[i];      // op goes in the data part of the node
            temp->rchild = s.peep(); // the top element of the stack as right child
            s.pop();
            temp->lchild = s.peep(); // top as the left child of the tree
            s.pop();
            s.push(temp); // push the new node in the stack
        }
    }
    root = s.peep();
    s.pop();
}
void mytree::rec_inorder(tnode *temp) // inorder traversal using recursion
{
    if (temp != NULL) // if temp not null
    {
        rec_inorder(temp->lchild); // left child passed
        cout << temp->data;        // data printed
        rec_inorder(temp->rchild); // right child passed
    }
}
void mytree::rec_preorder(tnode *temp) // preorder using recursion
{
    if (temp != NULL)
    {
        cout << temp->data;         // root data printed
        rec_preorder(temp->lchild); // left child passed
        rec_preorder(temp->rchild); // right child passed
    }
}
void mytree::rec_postorder(tnode *temp) // postorder func using recursion
{
    if (temp != NULL)
    {
        rec_postorder(temp->lchild); // left right passed
        rec_postorder(temp->rchild); // right child passed
        cout << temp->data;
    }
}
void mytree::inorder(tnode *node) // inorder without recursion
{
    Stack<tnode *> s; // stack obj s created
    if (node == NULL)
    { // check if empty
        cout << "EMPTY!";
        return;
    }

    // inorder is: left -> subtree root -> right

    while (node != NULL)
    {                 // traverse the left children till leaf node
        s.push(node); // push every node
        node = node->lchild;
    }
    while (!s.isEmpty())
    {
        node = s.peep();
        s.pop();
        cout << node->data;  // print subtree root data
        node = node->rchild; // go to right child
        while (node != NULL)
        { // traverse the left children of every right child till leaf node
            s.push(node);
            node = node->lchild;
        }
    }
}

void mytree::preorder(tnode *node) // preorder without recursion
{
    Stack<tnode *> s; // stack obj s created
    if (node == NULL) // if node null
    {
        cout << "Tree is empty";
        return;
    }
    s.push(node); // push node in the stack
    while (!s.isEmpty())
    {
        node = s.peep(); // top element as node
        s.pop();
        cout << node->data;

        if (node->rchild != NULL) //
            s.push(node->rchild);
        if (node->lchild != NULL)
            s.push(node->lchild);
    }
}

void mytree::postorder(tnode *node) //postorder traversal function
{
    Stack<tnode *> s1;
    Stack<tnode *> s2;
    if (node == NULL)
    {
        cout << "Tree is empty!";
        return;
    }
    s1.push(node);
    while (!s1.isEmpty())
    {
        node = s1.peep();
        s1.pop();

        s2.push(node);
        if (node->lchild != NULL)
            s1.push(node->lchild);
        if (node->rchild != NULL)
            s1.push(node->rchild);
    }
    while (!s2.isEmpty())
    {
        node = s2.peep();
        s2.pop();
        cout << node->data;
    }
}
tnode *mytree::get_root() // get root function
{
    return root;
}