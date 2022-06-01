//============================================================================
// Name        : Threaded.cpp
// Author      : Bhavana
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "tbt.h"
using namespace std;

int main() {
	int choice;
	TBT t;
	do{
		cout<<"\n----------------------------MENU----------------------------\n1)Insert\n2)Preorder traversal\n3)Exit"<<endl;
		cin>>choice;
		switch(choice){
		//to insert a new element
		case 1:t.create();
				t.display_inorder();
				break;
		// to display in preorder
		case 2:t.preorder();
		break;
		case 3:cout<<"Program finished!!";
		break;
		default:cout<<"Invalid entry"<<endl;


		}
	}while(true);

}
