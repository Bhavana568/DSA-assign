//============================================================================
// Name        : CQ_queue.cpp
// Author      : Bhavana
// Class       : SE 09
// Batch       : E 09
// Roll no.    : 23107
// Version     : 1
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include"Queu1.h"
#include <iostream>
//#include "Queue.h"
#include<bits/stdc++.h>
using namespace std;

//main function
int main()
{
	q1 patient(3);//object created
	int choice=0;

	while(choice<6)
	{//menu driven program
		cout<<"\n<***Menu***>"<<endl;
		cout<<"1. Insert"<<endl;
		cout<<"2. Remove"<<endl;
		cout<<"3. Full"<<endl;
		cout<<"4. Empty"<<endl;
		cout<<"5. Exit"<<endl;
		cout<<"Enter Your Choice: ";
		cin>>choice;

		if(choice==1)
		{//choice for user input
			string name;
			Patient newPatient;
			cout<<"Name: ";//name taken
			getline(cin,name);
			getline(cin,name);
			newPatient.name=name;//name value stored
			cout<<"Age: ";//age taken
			cin>>newPatient.age;
			patient.addPatient(newPatient);//to add new patient
		}
		else if(choice==2)
			patient.removePatient();//to delete patient
		else if(choice==3)
			if(patient.isFull())
				cout<<endl<<"Queue is Full";//when queue is full
			else
				cout<<endl<<"Not Full";
		else if(choice==4)
			if(patient.isEmpty())
				cout<<endl<<"Queue is Empty";//queue is empty
			else
				cout<<endl<<"Not Empty";
		else
			break;

		patient.display();//display function called

	}
}
//Program Finished!!
