/*
 * bstree.h
 *
 *  Created on: 16-Nov-2020
 *      Author: lenovo
 */

#ifndef BSTREE_H_
#define BSTREE_H_
#include <iostream>
using namespace std;
struct bnode // structure bnode consisting of data ,right and left child pointers
{
    int data;
    bnode *lchild;
    bnode *rchild;
};
class bstree // class bstree
{
    bnode *root;

public:
    bstree(); // default constructor
    // functions to be used:
    bnode *search(bnode *, int);
    bnode *rec_insert(bnode *p, int x);
    bnode *insert(bnode *root, int x);
    bnode *getnode(int);
    bnode *mirror(bnode *);
    void inorder(bnode *);
    bnode *copy(bnode *);
    int height(bnode *);
    bnode *deleteNode(bnode *, int);
    bnode *maxOf(bnode *);

#endif /* BSTREE_H_ */
};
