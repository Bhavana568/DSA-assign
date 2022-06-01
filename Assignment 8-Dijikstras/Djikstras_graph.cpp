//============================================================================
// Name        : Djikstras.cpp
// Author      : Bhavana
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
using namespace std;
#include "graph.h"

int main() {
	graph g;
	g.create_graph();
	cout<<"\nDijkistras Algorithm\n";
	g.dijkstras();
	return 0;
}
