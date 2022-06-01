/*
 * Graph.cpp
 *
 *  Created on: 08-Dec-2020
 *      Author: lenovo
 */

#include "Graph.h"
#include<iostream>
using namespace std;

Graph::Graph() {
	// TODO Auto-generated constructor stub
	v=6;
	e=10;
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			weight[i][j]=0;
		}
	}
}

void Graph::creategraph(){

	int w;
	int a,b,i,j=0;
	string s,t;
	cout<<"Enter number of vertices : ";
	cin>>v;
	cout<<"Enter number of edges : ";
	cin>>e;
	cout<<"*****************************"<<endl;
	for (int x =0;x<20;x++){
		for (int j = 0; j<20;j++){
			weight[x][j]=0;
		    p[x]=visited[x]=0;
		    d[x]=5000;
		}
	}
	for (int x2 = 0; x2<v; x2++){
		cout<<"Enter vertice number "<<(x2+1)<<" : ";
		cin>>names[x2].name;
	}
	cout<<"*****************************";

	for (i=0;i<e;i++)
	{
		cout<<endl<<"Enter source : ";
		cin>>s;
		for (int l=0;l<v;l++){
			if(names[l].name==s){
				a=l;
			}
		}
	cout<<"Enter destination : ";
	cin>>t;
	for (int l=0;l<v;l++){
		if(names[l].name==t){
			b=l;
		}
	}
	cout<<"Enter weight : ";
	cin>>w;
	weight[a][b]=w;
	edge[i].U=a;
	edge[i].V=b;
	edge[i].wt=w;
	weight[b][a]=w;
	cout<<"*****************************";
	}
	cout<<endl<<"Weight matrix : "<<endl;
	for (int f= 0; f<v;f++)
		if (f==0)
	            cout<<" "<<names[f].name;
	    else
	            cout<<" "<<names[f].name;
	cout<<endl;
	for (i=0;i<v;i++)
	{
		for (j=0;j<v;j++){
			if (j==0)
				cout<<" "<<names[i].name;
			cout<<" "<<weight[i][j];
		}
		cout<<endl;
	}
}

void Graph::sortg(){

	int i,j;
	Edge temp;
	for(i=0;i<e-1;i++){
		for(j=0;j<e-1;j++){
			if(edge[j].wt>edge[j+1].wt){
				temp=edge[j+1];
				edge[j+1]=edge[j];
				edge[j]=temp;
			}
		}
	}
	cout<<"Sorted List of edges"<<endl;
	for(int i=0;i<e;i++){
		//cout<<edge[i].U<<", "<<edge[i].V<<", "<<edge[i].wt<<endl;
		cout<<names[edge[i].U].name<<", "<<names[edge[i].V].name<<", "<<edge[i].wt<<"\n";
	}
}

void Graph::kruskals(){
	int i,j;
	cout<<"edge array is:"<<endl;
	for (i=0;i<e;i++){
		//cout<<edge[i].U<<", "<<edge[i].V<<", "<<edge[i].wt<<endl;
		cout<<names[edge[i].U].name<<", "<<names[edge[i].V].name<<", "<<edge[i].wt<<"\n";
	}
	sortg(); // Sort the list of edges

	Edge t[15];
	int conn[10],k,r,p,Val,cnt=0;
	for (i=0;i<e;i++){
		conn[i]=0;
	}
	Val=1;
	cnt=0;
	j=0;
	while(cnt<e-1 && j<e){
		if(conn[edge[j].U]==0 && conn[edge[j].V]==0){
			cout<<"edge selected"<<names[edge[j].U].name<<", "<<names[edge[j].V].name<<", "<<edge[j].wt<<"\n";
			t[cnt]=edge[j];
			conn[edge[j].U]=Val;
			conn[edge[j].V]=Val;
			Val++;
			cnt++;
		}else if(conn[edge[j].U]!=conn[edge[j].V]){
			cout<<"edge selected"<<names[edge[j].U].name<<", "<<names[edge[j].V].name<<", "<<edge[j].wt<<"\n";
			if(conn[edge[j].U]!=0 && conn[edge[j].V]!=0){
				t[cnt]=edge[j];
				if(conn[edge[j].U]<conn[edge[j].V]){
					r=conn[edge[j].U];
					p=conn[edge[j].V];
				}else{
					r=conn[edge[j].V];
					p=conn[edge[j].U];
				}
				for(k=0;k<e;k++){
					if(conn[k]==p) {
						conn[k]=r;
					}
				}
				cnt++;
			}
			else if(conn[edge[j].U]==0 && conn[edge[j].V]!=0){
				t[cnt]=edge[j];
				conn[edge[j].U]=conn[edge[j].V];
				cnt++;
			}else{
				t[cnt]=edge[j];
				conn[edge[j].V]=conn[edge[j].U];
				cnt++;
			}
		}
		else{
			cout<<"edge Rejected"<<names[edge[j].U].name<<", "<<names[edge[j].V].name<<", "<<edge[j].wt<<"\n";
		}
		j++;
	}
	cout<<"Krskals MST contains following edges::"<<endl;
	int cost=0;
	for(i=0;i<cnt;i++){
		//cout<<t[i].U<<", "<<t[i].V<<", "<<t[i].wt<<endl;
		cout<<names[t[i].U].name<<", "<<names[t[i].V].name<<", "<<t[i].wt<<"\n";
		cost=cost+t[i].wt;
	}
	cout<<endl<<"Total Cost of MST is "<<cost;
}

void Graph::prim(){
	int current, totalvisited, mincost,i;
	current=0; d[current]=0;
	totalvisited =1;
	visited[current]=1;
	cout<<endl<<"visited   distance and path status is :"<< endl<<"i , visited[i]     p[i]     , d[i]";
	for(i=0;i<v;i++){
		cout<<endl;
		cout<<names[i].name<<"\t"<<names[visited[i]].name<<"\t"<<names[p[i]].name<<"\t"<<d[i]<<"\t";
	}
	while(totalvisited!=v){
		cout<<endl<<"total visited="<<totalvisited;
		for (i=0;i<v;i++){
			if(weight[current][i]!=0)
			if(visited[i]==0)
			if(d[i]>weight[current][i]){
				d[i] = weight[current][i];
				p[i] = current;
			}
		}
		cout<<endl<<"visited   distance and path status is :"<< endl<<"i , visited[i]     p[i]     , d[i]";

		for (i = 0;i<v;i++){
			cout<<endl;
			cout<<names[i].name<<"\t"<<names[visited[i]].name<<"\t"<<names[p[i]].name<<"\t"<<d[i]<<"\t";
		}
		mincost= 32767;
		cout<<endl<<"finding minimum cost";
		for (i=0;i<v;i++){
			if(visited[i] ==0)
			if (d[i] <mincost)
			{
				mincost = d[i];
				current = i;
			}
		}
		cout<< endl<<"for I="<<i;
		cout<<"mincost= "<<mincost;
		cout<<"current= "<<current;
		visited[current] = 1;
		totalvisited++;

		cout<<endl<<"current= "<<current<<"  Total Visited== "<<totalvisited;
	}
	cout<<endl<<"Minimum span tree is"<<endl;
	mincost =0;
	for (i=1;i<v;i++){
		mincost += d[i];
		cout<<" Edge "<<names[i].name<<"-->"<<names[p[i]].name<<" Weight= "<<d[i]<<"\n";
	}
	cout<<"Minimum cost = ";
	cout<<mincost;
	cout<<endl<<"After Manip visited   distance and path status is :";
	cout<<endl<<"i , visited[i]     p[i]     , d[i]";
	for (i=0;i<v;i++){
		cout<<endl;
		cout<<names[i].name<<"\t"<<names[visited[i]].name<<"\t"<<names[p[i]].name<<"\t"<<d[i]<<"\t";
	}
}

Graph::~Graph() {
	// TODO Auto-generated destructor stub
}


