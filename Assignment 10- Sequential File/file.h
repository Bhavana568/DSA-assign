/*
 * file.h
 *
 *  Created on: 13-Dec-2020
 *      Author: lenovo
 */

#ifndef FILE_H_
#define FILE_H_
#include<iostream>
using namespace std;

class File {
private:
	 int roll;
	 string name;
	 string div;
	 string address;

public:
	//constructor
	File();
	//method to create a new file and add records
	void create();
	//method to create a new file
	void addRecords();
	//method to get user input
	void input();
	//method to show the records in the database
	void show();
	//modify a record in the database
	void modify(int rollno);
	//method to modify recordsin the database
	void modifyRecord();
	//method to display all the records in the file
	void display();
	//method to delete a particular record in the file
	void deleteRecord();
	//method to display a particular record in the file
	void search();
	//method to return roll no
	int getroll();

	~File();
};

#endif /* FILE_H_ */
