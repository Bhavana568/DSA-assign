#ifndef MYTREE_H_
#define MYTREE_H_

#include <iostream>

using namespace std;
struct tnode // structure tnode consisting of data, left and right child
{

    char data;
    tnode *lchild, *rchild;
};
class mytree // class mytree containing root pointer and string input for postfix expression
{
    tnode *root;
    string ip;

public:
    mytree(); // default contructor
    // functions to be used:
    tnode *get_root();
    void create();
    void input();
    void rec_inorder(tnode *);
    void rec_preorder(tnode *);
    void rec_postorder(tnode *);
    void inorder(tnode *);
    void postorder(tnode *);
    void preorder(tnode *);
};
#endif /* MYTREE_H_ */