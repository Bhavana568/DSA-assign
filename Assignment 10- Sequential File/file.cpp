/*
 * file.cpp
 *
 *  Created on: 13-Dec-2020
 *      Author: lenovo
 */

#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>
#include "file.h"
#include <cstdio>
#include <iomanip>
using namespace std;

File fileobj;
File modified;
fstream records;

//constructor to initialize variable
File::File() {
	// TODO Auto-generated constructor stub
	roll = 0;

}

//method to return roll no
int File::getroll(){
	return roll;
}

//method to create database
void File::create(){

	cout<<"============================================="<<endl;
	cout<<"\t CREATING DATABASE"<<endl;
	cout<<"============================================="<<endl;

	//open file in binary and out mode for input
	records.open("binary.dat",ios::out| ios::binary);

	fileobj.input();
	records.write((char*)&fileobj, sizeof(fileobj));
	cout<<endl;


	records.close();
	cout<<"==============================================="<<endl;
}

//method to add new records to file
void File::addRecords(){


	//open file in binary mode and append mode
	records.open("binary.dat",ios::app| ios::binary);

	fileobj.input();
	//method to write object of file class to binary file
	records.write((char*)&fileobj, sizeof(fileobj));
	cout<<endl;
	records.close();

}

//method to get input from user
void File::input()
{

	//enter roll no
	 cout<<"Enter the roll no:";
	 cin>>roll;
	 //validate roll no
	 if(roll<0)
	 {
	 	cout<<"Please enter a valid roll no!!"<<endl;
	 	cin>>roll;
	 }

	 cout<<"Enter name:";
	 cin.ignore();
	 getline(cin,name);
	 //validate name before entering
	 for (int i=0;i<(name.length());i++)
	 	{
	 		if(isalpha(name[i])==0 && isspace(name[i])==0)
	 		{
	 			cout<<"Invalid name."<<endl;
	 			cout<<"Enter name:";
	 			cin.ignore();
	 			getline(cin,name);
	 		}
	 	}
	 cout<<"Enter address:";
	 getline(cin,address);
	 cout<<"Enter div:";
	 cin>>div;
}

//method to modify data in the file
void File::modify(int rollno){
	//roll no is not modified
	roll = rollno;
	//enter new name
	cout<<"Enter name:";
	cin.ignore();
	getline(cin,name);
	 //enter new address
	cout<<"Enter address:";
	getline(cin,address);
	cout<<"Enter div:";
	cin>>div;
}
//method  to show the record in the file object
void File::show()
{
	cout<<left<<setw(8)<<roll<<setw(20)<<name<<setw(5)<<div<<setw(10)<<address<<endl;
}

//method to display all the records in the database
void File::display(){

	//open binary file in read mode
	records.open("binary.dat",ios::in| ios::binary);
	 if(!records) {
		 cout<<"File not Found";
		 exit(0);
	 }
	 else  {
		 //read file object from binary file
		 records.read((char*)&fileobj, sizeof(fileobj));
		 cout<<"============================================================"<<endl;
		 cout<<left<<setw(8)<<"ROLL NO"<<setw(20)<<"NAME"<<setw(5)<<"DIV"<<setw(10)<<"ADDRESS"<<endl;
		 cout<<"============================================================"<<endl;
		 //if records are present
		 while(!records.eof()) {
			 //show records if present
			 fileobj.show();
			 //read next records
			 records.read((char*)&fileobj, sizeof(fileobj));
		 }
		 cout<<"==========================================================="<<endl;
	 }
	 //close fie
	 records.close();
}

//method to search for a record in a file
void File::search(){

	//enter roll no to be searched
	int rollnu;
	cout<<"Enter Roll No to be searched:";
	cin>>rollnu;
	int found = 0;
	//method to open binary file in read mode
	records.open("binary.dat",ios::in| ios::binary);
	if(!records) {
		cout<<"File not Found";
		exit(0);
	}
	else {
		//method to read data into file object
		records.read((char*)&fileobj, sizeof(fileobj));
		 cout<<"============================================================"<<endl;
		 cout<<left<<setw(8)<<"ROLL NO"<<setw(20)<<"NAME"<<setw(5)<<"DIV"<<setw(10)<<"ADDRESS"<<endl;
		 cout<<"============================================================"<<endl;
		 //if records are present
		  while(!records.eof())  {
			  //if  record matches then print that record
			  if(rollnu==fileobj.getroll()){
				  fileobj.show();
				  found++;
			  }
			  //read records from file
			  records.read((char*)&fileobj, sizeof(fileobj));
		  }
		  cout<<"========================================================="<<endl;
	}
	records.close();
	if (found ==0){
		cout<<endl;
		cout<<"Record not found!!!"<<endl;
		cout<<endl;
	}
}


//method to modify existing recordin the database
void File::modifyRecord()
{

	int rollnu;
	cout<<"Enter Roll No. that should be modified:";
	cin>>rollnu;
	ofstream m;
	records.open("binary.dat",ios::in| ios::out|ios::binary);
	m.open("new.dat",ios::out|ios::binary);
	if(!records) {
		cout<<"File not Found";
		exit(0);
	}
	else {
		//read data from old file
		records.read((char*)&fileobj, sizeof(fileobj));
		//if records are not present
		while(!records.eof())  {
			//if roll no is found
			if(rollnu==fileobj.getroll()) {
				//new record to be entered if found
				cout<<"Enter New Record.."<<endl;
				modified.modify(rollnu);
				m.write((char*)&modified, sizeof(modified));
			}
			else
				//write data which does not match directly
				m.write((char*)&fileobj, sizeof(fileobj));
			//read next record from oiginal binary file
			records.read((char*)&fileobj, sizeof(fileobj));
		}
	}
	m.close();
	records.close();
	remove("binary.dat");
	rename("new.dat", "binary.dat");
}

//method to delete record from file
void File::deleteRecord(){

	int flag = 0;
	int ch;
	int rollnu;
	cout<<"Enter Roll No. to delete:";
	cin>>rollnu;
	ofstream o;
	//open current binary file
	o.open("new.dat",ios::out|ios::binary);
	//open new file to copy data
	records.open("binary.dat",ios::in| ios::binary);
	if(!records) {
		cout<<"File not Found";
		exit(0);
	}
	else {
		//read data from original file
		records.read((char*)&fileobj, sizeof(fileobj));
		while(!records.eof())  {
			//if record does not match copy directly
			if(rollnu!=fileobj.getroll())
				o.write((char*)&fileobj, sizeof(fileobj));
			else{
				//if record matches then do not copy data
				cout<<endl;
				cout<<"============================================================="<<endl;
				cout<<left<<setw(8)<<"ROLL NO"<<setw(20)<<"NAME"<<setw(5)<<"DIV"<<setw(10)<<"ADDRESS"<<endl;
				cout<<"============================================================="<<endl;
				fileobj.show();
				cout<<"============================================================="<<endl;
				cout<<endl;
				cout<<"Are you sure you want to delete?"<<endl;
				cout<<"1. Yes."<<endl;
				cout<<"2. No."<<endl;
				cout<<"Enter:";
				cin>>ch;
				if(ch==2){
					o.write((char*)&fileobj, sizeof(fileobj));
				}
				else{
					flag++;
				}

			}
			//read next record from binary file
			records.read((char*)&fileobj, sizeof(fileobj));
		}
	}
	//confirm deletion
	if(flag!=0){
		cout<<endl;
		cout<<"Record deleted successful!!!!"<<endl;
		cout<<endl;
	}

	o.close();
	records.close();
	remove("binary.dat");
	rename("new.dat", "binary.dat");
}

File::~File() {
}
