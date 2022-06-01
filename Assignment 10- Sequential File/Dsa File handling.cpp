//============================================================================
// Name        : Dsa.cpp
// Author      : Bhavana
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "file.h"
using namespace std;

int main()
{

	File o;
	int ch;

	o.create();

	while(1) {
		cout<<endl;
		cout<<"============================================="<<endl;
		cout<<"\t DATABASE"<<endl;
		cout<<"============================================="<<endl;
		cout<<"1.Add Record"<<endl;
		cout<<"2.Display Records"<<endl;
		cout<<"3.Search"<<endl;
		cout<<"4.Modify"<<endl;
		cout<<"5.Delete"<<endl;
		cout<<"0.Exit"<<endl;
		cout<<"Enter: ";
		cin>>ch;
		cout<<"=============================================="<<endl;
		cout<<endl;

		if(ch==1) {
			o.addRecords();
		}
		else if(ch==2) {
			o.display();
		}
		else if(ch==3) {
			o.search();
		}
		else if(ch==4) {
			o.modifyRecord();
		}
		else if(ch==5) {
			o.deleteRecord();
		}
		else if(ch==0) {
			exit(0);
		}
		else {
			cout<<"Enter valid choice.";
		}
	}
}
