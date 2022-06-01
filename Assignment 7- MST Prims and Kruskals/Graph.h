/*
 * Graph.h
 *
 *  Created on: 08-Dec-2020
 *      Author: lenovo
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
using namespace std;

struct Edge
{
	int U,V,wt;
};

struct name
{
	string name;
};

class Graph {
	int weight[100][100];
	int visited[100], d[100],p[100];
	int v,e;
	name names[100];
	Edge edge[100];
public:
	Graph();
	void creategraph();
	void prim();
	void sortg();
	void kruskals();
	virtual ~Graph();
};

#endif /* GRAPH_H_ */
