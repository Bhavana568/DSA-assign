//===============================================================//
// Author: Bhavana Bafna
// Class: SE9
// Batch : E9
// Roll number: 23107
// Subject: DSA Assignment 1
// Topic : Student enrollment
//================================================================//
#include <iostream>
#include<cmath>
using namespace std;
//structure defined for date of birth
struct dob
{
	int dd;//for date(2)
	int mm;//for month(2)
	int yyyy;//for year(4)
};
//structure defined for student details
struct student
{
//data members declared
    string name;//for name
    int roll;//for roll no.
    int total;//for total marks
    int marks[5];//for marks of 5 subjects
    float per;//to find percentage
//    char Address[50];
//    char phone_no[10];
    int dd;//for date
    int mm;//for month
    int yyyy;//for year
};
//class defined
class Student
{
    student s[15];

    public:
//all the methods defined
    void input(int);//for user input
    void valid_name(int);//validations for name
    void bubble_sort(int);//sorting of students using roll no
    void linear_search(int);//searching student by CGPA
    void binary_search(int);//searching student by name
    void display(int);//displaying data in table format
    void valid(int);//validations for roll no
    void pass_display(int,int);
    void insertion_sort(int);//sorting students by name
    void quick_sort(int,int,int);//sorting students by percentage
    void valid_marks(int,int);//validations for marks
    void valid_dob(int);//validations for date of birth
    int partition(int,int,int*,int*);

//  void sequential_search(int);

    Student()
    {

    }
};
//validation for name
void Student::valid_name(int i)
{

    do{
        cin>>s[i].name;//take the name as input
        int k=0,c=0;
        string str=s[i].name;
        if((s[i].name).length()<=1)//check if name is a single char
        {
            cout<<"Name cannot be a single character please try again"<<endl;
            continue;
        }
      for (int k=0; k<=str.length(); k++)//check if any char in the name is a digit
      {
          if (isdigit(str[k]))
            {
                cout<<"Invalid name please try again"<<endl;
                c ++;//increment counter if present
                break;
            }
      }

      if(c>0)//if digit is present take the name again
      {
          continue;
      }
      else{
          break;//if correct then break the loop
      }

    }while(1);


	int flag =1;
	        do{
	        int len = s[i].name.length();
	        for(int j=0; j<len ; j++)
	        {
	            if (isalpha(s[i].name[j]))
	            {
	                flag =1;
	                continue;
	            }
	            else
	            {
	                cout<<"Invalid name!Please try again!!"<<endl; //wrong input
	                flag =0;
	                cin>>s[i].name;
	                continue;
	            }
	        }break;
	        }while(flag ==0);

}
//validation for marks
void Student::valid_marks(int i,int j)
{


	do{//loop to run until inner breaks


        cin>>s[i].marks[j];//take the marks as input
		if(s[i].marks[j]<0){
			cout<<"Marks should be positive"<<endl;//for negative no
			continue;//if negative continue so that it will take marks input again after printing the msg
		}

		if(s[i].marks[j]>100){
			cout<<"Marks should be less than 100"<<endl;//for invalid marks,i.e greater than 100
			continue;
		}

		else{
			break;//break out of do while loop if correct
		}

	}while(1);

}
//validation for roll no.
void Student::valid(int i)
{
    int j;
    do{//loop to run until inner breaks

        cin>>s[i].roll;//take roll number as input
        if(s[i].roll<0)
        {
            cout<<"roll number is negative, please re-enter the number"<<endl;//for negative no
            continue;
        }
        if(s[i].roll>231081 || s[i].roll<23101)
        {
            cout<<"Invalid roll no.(Enter roll no. from 23101-23181)"<<endl;//for invalid roll no
            continue;
        }
        for ( j=0;j<i;j++)
        {
            if(s[i].roll==s[j].roll)//check if roll number is already present in array
            {

                cout<<"This number is already entered please try again"<<endl;//print error
                break;
            }
        }
        if(j==i){
            break;//break if correct
        }

    }while(1);

}
//validations for date of birth
void Student::valid_dob(int i){

		do{
			cout<<"Enter date\n";
		    cin>>s[i].dd;//user input for date
			if(s[i].dd<1 || s[i].dd>31){
				//to check month between 1-31
				cout<<"Date is invalid!! Please re-enter date betwee 1-31.\n";
				continue;//if invalid then ask again to enter
			}
			else{
				cout<<"Date is valid!!\n";
				break;
			}

		}while(1);

		do{
			cout<<"Enter month\n";//user input for month
		    cin>>s[i].mm;
			if(s[i].mm>=1 && s[i].mm<=12){
				//to check month between 1-12
				cout<<"Valid month!\n";
				break;
			}else
			{
			   cout<<"Month is not valid.Please re-enter month between 1-12.\n";
			   continue;//if invalid then ask again to enter
			}
		}while(1);

	    do{
	    	cout<<"Enter year\n";//user input for year
	    	cin>>s[i].yyyy;
	    	if(s[i].yyyy>=1900 && s[i].yyyy<=9999){
	    		//to check month between 1900-9999
	    			cout<<"Year is valid\n";
	    			break;
	    		}
	    	    else{
	    		   cout<<"Year is invalid.Please re-enter year between 1900-9999.\n";
	    		   continue;//if invalid then ask again to enter
	    	    }
	    }while(1);

}
//INPUT FUNCTION
void Student::input(int n)
{

    for(int i=0;i<n;i++)
    {
        cout<<"Enter details of student "<<(i+1)<<endl;
        cout<<"enter name"<<endl;//take name as input
        //cin>>s[i].name;
        valid_name(i);
        cout<<"Enter roll number"<<endl;//take roll no. as input
        valid(i);
        cout<<"Details of Date of birth"<<endl;//take dob as input
        valid_dob(i);
        cout<<"Enter marks of 5 subjects : "<<endl;//take marks as input
        //accepting marks and total calculation
        for(int j=0;j<5;j++)
        {
            //cin>>s[i].marks[j];
            valid_marks(i,j);
            s[i].total+=s[i].marks[j];
        }
        //percentage calculation
        s[i].per=(s[i].total/5.0);
    }

}

//BUBBLE SORTING FUNCTION
void Student::bubble_sort(int n)
{
	    int c, j;

	    cout << "Pass no.\t\tlist\t\tNo. of comparisons\t\tNo. of swap" << endl; // Displaying tabular  format
	    cout<<"===================================================================================================================="<<endl;
	    for (int i = 0; i < n; i++)//for start
	    {
	        cout << i + 1 << "\t\t"; // pass number
	        for (int k = 0; k < n; k++)//1st for start
	        {
	            cout << s[k].roll << " ";
	        }//1st for end
	        struct student temp;//struct student
	        c = 0;//initializing c to 0
	        for (j = 0; j < n - i; j++)//2nd for start
	        { // Swapping of data
	            if (s[j].roll > s[j + 1].roll)
	            {
	                c += 1;      // number of comparisons
	                temp = s[j]; // temp for data swapping
	                s[j] = s[j + 1];
	                s[j + 1] = temp;//temp value stored
	            }//if end
	        }//2nd for end
	        cout << "\t\t\t" << j - 1 << "\t\t\t" << c << endl;//for displaying table format
	    }
	    cout<<"===================================================================================================================="<<endl;
	    cout << "DATA SORTED!!" << endl;//sorted data display
//analysis for bubble sort
	    cout<<"===================================================================================================================="<<endl;
	    cout<<"****BUBBLE SORT ANALYSIS**** \n";
	    cout<<"===================================================================================================================="<<endl;
	    int worst;//declaring variable worst
	    worst=n*(n-1)/2;
	    if(c==n){//for best case
	    	cout<<"Best case"<<endl;
	    }
	    if(c==worst){//worst case
	    	cout<<"Worst case"<<endl;
	    }
	    else{//average case
	    	cout<<"Average case"<<endl;
	    }
	    display(n);
}


//INSERTION SORT
void Student::insertion_sort(int n)
{
    int i, j,c=0,swap;
    struct student key;//declare a struct key
    cout<<"Pass no.\tlist\t\tNo. of comparisons\tNo. of swap"<<endl;
    cout<<"===================================================================================================================="<<endl;
    for (i = 1; i < n; i++)
    {
    swap=0;

        key = s[i]; //set key as stuct at position i
        cout<<c+1<<"\t\t";//print pass number
        j = i - 1;
        c+=1;

        while (j >= 0 && s[j].name > key.name)//keep swapping until name at pos j is greater
        {  swap+=1;

           s[j+1]=s[j];
            j = j - 1;
        }
        s[j + 1]= key;//make name at key as name at j+1

         for(int k=0;k<n;k++)
        {
            cout<<s[k].name<<" ";//print the names
        }
        cout<<"\t\t\t"<<swap+1<<"\t\t"<<swap<<endl; //print number of swaps

    }
    display(n);//display function

   //analysis
    cout<<"===================================================================================================================="<<endl;
    cout<<"**** INSERTION SORT ANALYSIS**** \n";
    cout<<"===================================================================================================================="<<endl;
    	cout<<"\n\t Input size          : "<<n;
    	cout<<"\n\t Total comparisons   : "<<c;
    	cout<<"\n\t Case   : ";

    	if(c==1){
    		cout<<"\tBest case\n";
    	}
    	else if(c==(n+1)*n){cout<<"\tWorst case \n"<<endl;}
    	else
    	    cout<<"\tAverage case \n";
}

//QUICK SORT
int Student::partition(int pivot, int n, int *tot_comp, int *pass)
{
    int i = pivot + 1; //setting the Starting Index
    int j = n;         //ending Index

    int comp = 2; //comparsions

    do
    {
        while (s[i].per >= s[pivot].per)
        {
            i++; //looking for smaller element than pivot element
            comp++;
        }
        while (s[j].per < s[pivot].per)
        {
            comp++;
            j--; //looking for greater element than pivot element
        }

        if (i < j)
        {
            student t;
            t = s[i]; //swapping the smaller element with larger element
            s[i] = s[j];
            s[j] = t;
        }

    } while (i < j);

    *tot_comp += comp; //Incrementing Total Comparisons
    *pass += 1;        //incrementing Passes

    cout << "\n\nPass: " << *pass << "| Comparisons: " << comp;


    student t;
    t = s[pivot]; //putting the pivot element at its correct position
    s[pivot] = s[j];
    s[j] = t;
    return j; //returning the correct position of pivot element

}

void Student::quick_sort(int start, int end, int n)
{
    static int tot_comp = 0; //total comparisons and passes
    static int pass = 0;     //to store the number of passes

    if (start < end)
    {
        int j = partition(start, end, &tot_comp, &pass);
        //showing pass wise output
        cout << "\nPartition 1: ";
        for (int i = 0; i < j; i++)
            cout << s[i].per << "|";
        cout << "\n";
        cout << "\nPartition 2: ";
        for (int i = j; i < n; i++)
            cout << s[i].per << "|";
        cout << "\n";
        quick_sort(start, j - 1, n); //Smaller part
        quick_sort(j + 1, end, n);   //Greater part
    }
    else{
    	//analysis
    	            cout<<"===================================================================================================================="<<endl;
    	            cout<<"**** QUICK SORT ANALYSIS**** \n";
    	            cout<<"===================================================================================================================="<<endl;
    	            if(tot_comp==(n*log((double)n)))
    	            {
    	                cout<<"Best case"<<endl;
    	            }
    	            else if(tot_comp==(n*n))
    	            {
    	               cout<<"Worst case"<<endl;
    	            }
    	            else{
    	                cout<<"Average case"<<endl;
    	            }
    }



}

// BINARY SEARCH FUNCTION
void Student::binary_search(int n)
{
    insertion_sort(n);//sorting all the data in name before searching
    string r;
    cout<<"===================================================================================================================="<<endl;
    cout << "Enter the name of the student to be searched" << endl;
    cin >> r;
    int counter=0;
    int ub, result, lb, mid, pass = 1; // upper bound,lower bound ,mid declared
    mid = lb = 0;                      // initialized to 0
    ub = n - 1;                        //upper bound
    cout<<"===================================================================================================================="<<endl;
    cout << "PASS\t\tMID\t\tLOW\t\tHIGH\t\tKEY\t\tEle[mid]" << endl;
    cout<<"===================================================================================================================="<<endl;

    		while(lb<=ub) // this loop will work till there are 1 or more elements
    		{
    			pass = pass + 1 ;
    			mid = (lb+ub)/2 ; // assigning value of mid

    			cout << "\n" << pass << "\t\t" << mid << "\t\t" << lb << "\t\t" << ub <<"\t\t" << r << "\t\t" << s[mid].name << endl ;
    			cout<<"===================================================================================================================="<<endl;
    			cout<<"*** BINARY SEARCH ANALYSIS**** \n";
    			if(s[mid].name == r) // if mid element is the required key
    			{
    				if(s[mid].name == r) // if mid element is the required key
    						{
    							if(pass == 1 ) // if the element is found in the first pass of the algorithm ; it is best case.
    							{
    								cout << "\nBest case of Algorithm " << endl ;
    							}
    							if(pass != 1) // condition for average case.
    							{
    								cout << "\nAverage case of Algorithm " << endl ;
    							}
    						}
    				cout<<"===================================================================================================================="<<endl;
    				cout << r << " Found at : " << mid << endl ; // displays the position
    				cout << "\nName : " << s[mid].name << endl ; // displays record
    				cout << "Roll No. : " << s[mid].roll<<endl ;
    				cout << "Percentage : " << s[mid].per << endl ;

    				break;
    			}
    			if(s[mid].name > r) // if mid element is greater than required key
    			{
    				ub = mid - 1 ;
    			}
    			if(s[mid].name <r) // if mid element is smaller than required key
    			{
    				lb = mid + 1 ;
    			}
    			cout<<"===================================================================================================================="<<endl;
    			cout << r<< " Element not Found!!" << endl ; // if key does not exist in the list
    			cout<<"===================================================================================================================="<<endl;

    		}
}

//LINEAR SEARCH
void Student::linear_search(int n)
{
    float r;
    //user input for CGPA
    cout<<"Enter the CGPA of the student to be searched"<<endl;
    cin>>r;
    display(n);
    //displaying the table format
    cout<<"Location\t key\t\t element"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<i<<"\t\t"<<r<<"\t\t"<<s[i].per<<"\t\t"<<endl;
        //LINEAR SEARCH
        if(s[i].per==r)
        {
        	//displaying element if found
            cout<<"Element found at position "<<i<<endl;
            break;//break if found
        }
        else
        {
        	//if not found
            cout<<("Search is unsuccessful.")<<endl;
        }

    }

    //displaying analysis
    cout<<"===================================================================================================================="<<endl;
    cout<<"*** LINEAR SEARCH ANALYSIS**** \n";
    cout<<"===================================================================================================================="<<endl;
    	cout<<"\n\t Input size     : "<<n;

    	cout<<"\n\t Case   : ";

    	if(n==1){
    		cout<<"\tBest case\n";
    	}

    	else
    		cout<<"\tAverage case / Worst case\n";
}
//swapping of structure
void swap(struct student *a,struct student *b){
	struct student temp;
	temp=*b;
	*b=*a;
	*a=temp;
}



//DISPLAY FUNCTION
void Student::display(int n)
{
    //DISPLAYING IN TABLE FORMAT
	cout<<"===================================================================================================================="<<endl;
    cout<<"Sr. No.\t\tRoll no\t\tName\t\tDOB\t\tTotal\t\tPercentage"<<endl;
    cout<<"===================================================================================================================="<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<(i+1)<<"\t\t"<<s[i].roll<<"\t\t"<<s[i].name<<"\t\t"<<s[i].dd<<"-"<<s[i].mm<<"-"<<s[i].yyyy<<"\t\t"<<s[i].total<<"\t\t"<<s[i].per<<endl;
    }
    cout<<"===================================================================================================================="<<endl;
    }
//MAIN function
int main()
{
    Student SE;//declaring student object
    int n;//declaring variable for passing parameters

int op; //declaring a variable to store choice of user
do
{
    cout<<"\n****AVAILABLE OPERATIONS FOR ARRAY ASSIGNMENT 1**** "<<endl; //displaying the menu
    cout<<"===================================================================================================================="<<endl;
    cout<<"1. Input : "<<endl;
    cout<<"2. Bubble Sort for Roll no : "<<endl;
    cout<<"3. Insertion Sort for Names : "<<endl;
    cout<<"4. Quick Sort for CGPA: "<<endl;
    cout<<"5. Linear Search to search Student by CGPA: "<<endl;
    cout<<"6. Binary search to search Student by  Name: "<<endl;
    cout<<"7. Display student database: "<<endl;
    cout<<"8. Exit"<<endl;
    cin>>op;
    switch (op)
    {
    case 1:
        //for input from user;
        do
        {
        	//validations for input
        	cout<<"\n\t Enter no. of students you want to enter (between 1 to 15)"<<endl;
        	//if number greater than 15
        	cin>>n;
        	if(n<0 || n>15){
        		cout<<"\n\t Invalid size. Please re-enter correct value : ";
        		continue;
        	}else
        		break;

        }while(1);
        SE.input(n);
        break;
    case 2:SE.bubble_sort(n);//for bubble sort for roll no
           break;
    case 3:SE.insertion_sort(n);//for insertion sort for names
           break;
    case 4:SE.quick_sort(0,n,1);//for quick sort for percentage

           SE.display(n);
           break;
    case 5: //linear search for CGPA
    	   SE.linear_search(n);
            break;
    case 6: SE.binary_search(n);//binary search for names
            break;
    case 7:
    	    //display data base
            if (n>0){
            	SE.display(n);

            }else{
            	cout<<"\n\t List is empty";
            }
            break;
    case 8: cout<<("Are you sure you want to exit \n\t 1.Yes \n\t 2.No")<<endl;
    //to confirm to exit the program
            cin>>n;
            if(n==1){
            	cout<<"PROGRAM FINISHED!!";
            	return 0;
            }
            else
            {
            	//if no then repeat the program
            	cout<<"Enter further program you want to execute!!"<<endl;
            	do
            	        {
            	        	//validations for input
            	        	cout<<"\n\t Enter no. of students you want to enter (between 1 to 10)"<<endl;
            	        	//if number greater than 10
            	        	cin>>n;
            	        	if(n<0 || n>10){
            	        		cout<<"\n\t Invalid size. Please re-enter correct value : ";
            	        		continue;
            	        	}else
            	        		break;

            	        }while(1);
            	        SE.input(n);
            	        break;
            	return -1;
            }
            break;
//if user enter wrong input
    default:cout<<"Invalid entry!"<<endl;
        break;
    }
} while (op!=8);
return 0;
}
//PROGRAM FINISHED!!
