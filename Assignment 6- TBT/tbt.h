/*
 * tbt.h
 *
 *  Created on: 30-Nov-2020
 *      Author: lenovo
 */

#ifndef TBT_H_
#define TBT_H_
#include<iostream>
using namespace std;

struct tnode{
	tnode* llink;
	tnode* rlink;
	int data;
	bool lthread;
	bool rthread;
};

class TBT {
	tnode* head;//root node
public:
	TBT();
	void create();
	void display_inorder();
	void insert();
	void preorder();
	tnode* getnode(int);
	//virtual ~TBT();
};




#endif /* TBT_H_ */
