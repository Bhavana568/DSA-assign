/*
 * Graph.cpp
 *
 *  Created on: 10-Dec-2020
 *      Author: lenovo
 */
#include "graph.h"
#include <iostream>
using namespace std;

graph::graph() {
	// TODO Auto-generated constructor stub

}

void graph :: create_graph()
{
	float w;
	int a,b,i,j=0;
	string s,t;
	cout<<"Enter number of landmarks : ";
	cin>>v;
	cout<<"Enter number of links : ";
	cin>>e;
	cout<<"\n=========================================\n"<<endl;
	for (int x =0;x<20;x++){
	    for (int j = 0; j<20;j++){
	        weight[x][j]=0;
	        p[x]=visited[x]=0;
	        d[x]=5000;
	    }
	}

	for (int x2 = 0; x2<v; x2++){
	    cout<<"Enter landmark number "<<(x2+1)<<" : ";
	    cin>>names[x2].name;
	}
	cout<<"\n=========================================\n";

	for (i=0;i<e;i++)
		{
		  cout<<endl<<"Enter source landmark : ";
		  cin>>s;
		  for (int l=0;l<v;l++){
		    if(names[l].name==s){
		        a=l;
		    }
		  }
		  cout<<"Enter target landmark : ";
		  cin>>t;
		  for (int l=0;l<v;l++){
		    if(names[l].name==t){
		        b=l;
		    }
		  }
		  cout<<"Enter distance : ";
		  cin>>w;
		  weight[a][b]=w;
		  edge[i].u=a;
		  edge[i].v=b;
		  edge[i].w=w;
		  weight[b][a]=w;
		  cout<<"\n=========================================\n";
		}
    cout<<endl<<"Adjacency Matrix :- "<<endl;
    cout<<"\t";
    for (int f= 0; f<v;f++)
        if (f==0)
            cout<<"\t"<<names[f].name;
        else
            cout<<"\t"<<names[f].name;
    cout<<endl;
	for (i=0;i<v;i++)
	{
		for (j=0;j<v;j++){
		    if (j==0){
		        cout<<"\t"<<names[i].name;
		    }
			cout<<"\t"<<weight[i][j];
		}
        cout<<endl;
	}
}

void graph :: dijkstras()
{
    int i,j,k,u,min,current;
    int s;
    string s2;
    cout<<endl<<"Enter source landmark : ";
    cin>>s2;
    for (int l=0;l<v;l++){
	    if(names[l].name==s2){
		    s=l;
		}
	}
    for (i=0;i<v;i++)
    	{
    	  visited[i] =0;
    	  if(weight[s][i]!=0)
    		  d[i] = weight[s][i];
    	  else d[i] = 32767;
    	  p[i]=s;
    	}
    cout<<"Shortest path = "<<s;
    cout<<endl<<"\n===========================================\n"<<endl;
    current=s;
    visited[current]=1;
    d[s]=0;
    cout<<endl<<"Visited distance and path status is : "<< endl;
    cout<<"\n===========================================\n";
    cout<<"i"<<"\t"<<"visited[i]"<<"\t"<<"p[i]"<<"\t"<<"d[i]";
	for (i=0;i<v;i++)
	{
	    cout<<endl;
	    cout<<names[i].name<<"\t"<<names[visited[i]].name<<"\t"<<"\t"<<names[p[i]].name<<"\t"<<d[i]<<"\t";
	}
	cout<<endl<<"\n===========================================\n"<<endl;
    for(i=0;i<v-1;i++)
    {
    	min=32767;
    	for(j=0;j<v;j++)
    	{
    		if (min>d[j] && visited[j]==0)
    		{
    			min=d[j];
    			current=j;
    		}
    	}
    	cout<<endl<<"Selected Vertex is : "<<current;
    	cout<<endl<<"Minimum is : "<<min;
    	visited[current]=1;
    	for(k=0;k<v;k++)
    	{
    		if(visited[k]==0 && (d[current]+weight[current][k])<d[k])
    		{
    			if(weight[current][k]!=0)
    			{
    				d[k]=d[current]+weight[current][k];
    			    p[k]=current;
    			}
    		}
    	}
    	cout<<endl<<"Visited distance and path status is : "<< endl<<"i"<<"\t"<<"visited[i]"<<"\t"<<"p[i]"<<"\t"<<"d[i]";
    	for (int i2=0;i2<v;i2++)
    	{
    	    cout<<endl;
    	    cout<<names[i2].name<<"\t"<<names[visited[i2]].name<<"\t"<<"\t"<<names[p[i2]].name<<"\t"<<d[i2]<<"\t";
    	}
    	cout<<endl<<"\n===========================================\n"<<endl;
    }
    cout<<endl<<"Shortest Path from Source to all destinations";
    cout<<endl<<"Source is -->"<<s<<endl;
    for(i=0;i<v;i++)
    {
    	if(i!=s)
    	{
    		cout<<endl<<"landmark = "<<names[i].name<<", Distance = "<<d[i];
    		cout<<" Path = "<<names[i].name;
    		j=i;
    		do
    		{
    			j=p[j];
    			cout<<" <- "<<names[j].name;
    		}while(j!=s);
    	}
    }
}

graph::~graph() {
	// TODO Auto-generated destructor stub
}