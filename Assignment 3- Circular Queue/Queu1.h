/*
 * Queu1.h
 *
 *  Created on: 17-Sep-2020
 *      Author: lenovo
 */

#ifndef QUEUE_H_
#define QUEUE_H_
#include<string>
//structure defined
struct Patient{
	std::string name;//objects defined
	int age;
};

class q1 {
	Patient* queue;
	int size;			//size of queues
	int front;			//first patient
	int rear;			//last patient

public://methods defined
	void addPatient(Patient);//to add function
	bool isEmpty();//for empty queue
	bool isFull();//for full  queue
	void removePatient();//to remove function
	void display();//display method declared
	q1(int);
	virtual ~q1();
};

#endif /* QUEUE_H_ */
