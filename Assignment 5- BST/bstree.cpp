/*
 * bstree.cpp
 *
 *  Created on: 16-Nov-2020
 *      Author: lenovo
 */

#include "bstree.h" // including the bstree.h file
bstree::bstree()    // default constructor
{
    root = NULL; // root pointer initialized as null
}
bnode *bstree::maxOf(bnode *temp) // function of getting the max value of the targeted tree
{
    while (temp->rchild != NULL) // unless right child is not null
        temp = temp->rchild;
    return temp;
}

bnode *bstree::deleteNode(bnode *temp, int key) // function to delete node
{

    if (temp == NULL)
        return NULL;

    if (key < temp->data) // to traverse the left child
        temp->lchild = deleteNode(temp->lchild, key);
    else if (key > temp->data) // to traverse the right child
        temp->rchild = deleteNode(temp->rchild, key);
    else // element found
    {

        bnode *reference = temp;

        if (temp->lchild == NULL and temp->rchild == NULL)
        { //no children
            temp = NULL;
            delete reference;
        }
        else if (temp->lchild == NULL)
        { //only right child
            temp = temp->rchild;
            delete reference;
        }
        else if (temp->rchild == NULL)
        { //only left child
            temp = temp->lchild;
            delete reference;
        }
        else
        {                                     //both child are present
            bnode *max = maxOf(temp->lchild); //getting the max value left subTree of targeted tree
            int maxVal = max->data;
            temp = deleteNode(temp, max->data); //deleting the node with max value
            temp->data = maxVal;                //assigning the max value to the current node
            delete max;                         //deleting the copy of max node
        }
    }
    return temp; //returning the updated node
}
void bstree::inorder(bnode *temp) // recursive inorder traversal function
{
    if (temp != NULL)
    {
        inorder(temp->lchild);
        cout << temp->data;
        inorder(temp->rchild);
    }
}
bnode *bstree::getnode(int x) // get node function
{
    bnode *node = new bnode; // new node created
    node->data = x;          // data part as x
    node->lchild = NULL;     // left child as null
    node->rchild = NULL;     // right child as null
    return node;
}
bnode *bstree::rec_insert(bnode *temp, int x) // recursive insertion function
{
    if (temp == NULL) // if temp null
    {
        temp = getnode(x); // get node
        return temp;
    }
    else if (x < temp->data) // if x less than temp data then insert at left
        temp->lchild = rec_insert(temp->lchild, x);
    else if (x > temp->data) // if temp greater than temp data then insert at right
        temp->rchild = rec_insert(temp->rchild, x);
    else if (x == temp->data) // if same display error
    {
        cout << "duplicate not allowed" << endl;
        return temp;
    }
    return temp;
}
bnode *bstree::insert(bnode *root, int x) // insert method without recursion
{
    if (root == NULL) // if root pointer is null
    {
        root = getnode(x); // get node function called
        return (root);
    }
    // p and q pointing both to root pointer
    bnode *p;
    bnode *q;
    p = root;
    q = root;
    while (q != NULL and x != p->data)
    {
        p = q;
        if (x < p->data)      // x less than p data
            q = p->lchild;    // q as left child
        else if (x > p->data) // x greater than p data
            q = p->rchild;    // q as right child
    }
    if (x == (p->data)) // if both data are equal
    {
        cout << "Duplicate not allowed" << endl;
        return root;
    }
    if (x < p->data)
    {
        p->lchild = getnode(x);
    }
    else
    {
        p->rchild = getnode(x);
    }
    return root;
}
bnode *bstree::search(bnode *root, int key) // search function
{
    if (root == NULL)
    {
        cout << "Empty tree" << endl;
    }
    else
    {
        bnode *p = root;
        if (key < p->data) // if key less than p data
        {
            p = search(p->lchild, key); // rec call of search function
        }
        else if (key > p->data) // if key greater than p data
            p = search(p->rchild, key);
        else
            return p;
    }
}
bnode *bstree::mirror(bnode *root) // mirror function
{
    if (root)
    {
        bnode *temp = new (bnode); // new node
        temp = root->rchild;
        root->rchild = root->lchild;
        root->lchild = temp;
        mirror(root->lchild);
        mirror(root->rchild);
    }
    return root;
}
bnode *bstree::copy(bnode *root)
{
    if (root == NULL)
        return NULL;
    // create a copy of root node
    bnode *new_node = getnode(root->data);
    // Recursively create clone of left and right sub tree
    new_node->lchild = copy(root->lchild);
    new_node->rchild = copy(root->rchild);
    // Return root of cloned tree
    return new_node;
}
int bstree::height(bnode *node)
{
    if (node == NULL)
        return 0;
    else
    {
        int l_subtree_depth = height(node->lchild);
        int r_subtree_depth = height(node->rchild);
        if (l_subtree_depth > r_subtree_depth)
            return (l_subtree_depth + 1);
        else
            return (r_subtree_depth + 1);
    }
}
