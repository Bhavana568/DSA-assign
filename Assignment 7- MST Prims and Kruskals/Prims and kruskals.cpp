//============================================================================
// Name        : Prims.cpp
// Author      : Bhavana
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
using namespace std;

#include "Graph.h"

int main() {

	Graph graph;
	graph.creategraph();
	int ch;
	bool flag = true;
	while(flag == true){
		cout<<"1. Prims\n2. Kruskals\n3. Exit";
		cin>>ch;
		switch(ch){
		case 1:
		{
			cout<<endl<<" Primms Algorithm "<<endl;
			graph.prim();
			break;
		}
		case 2:
		{
			cout<<endl<<"Kruskals Algorithm "<<endl;
			graph.kruskals();
			break;
		}
		case 3:
		{
			flag = false;
			break;
		}
		}
	}
	return 0;
}
