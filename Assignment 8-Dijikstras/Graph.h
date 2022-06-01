/*
 * Graph.h
 *
 *  Created on: 10-Dec-2020
 *      Author: lenovo
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include <string>
using namespace std;

struct edge_s{
    int u,v;
    float w;
};

//structure to store name of the landmarks
struct name{
    string name;
};

//class graph with related functions
class graph {
	float weight[20][20];		//distance between 2 landmarks
	int visited[20], p[20];		//the landmark is visited or not and the position
	float d[20];				//distance
	int v,e;					//vertex and edge
	name names[20];				//name of the landmarks
	edge_s edge[20];			//array of structure of edge_s type
public:
	graph();
	void create_graph();		//creation of new graph and adjacency matrix
	void dijkstras();			//finding the shortest path using dijktras algorithm
	virtual ~graph();
};

#endif /* GRAPH_H_ */
