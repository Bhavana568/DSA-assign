#include <iostream>
#include <iomanip>
#include <string>
#include "mytree.h"
#include "mytree.cpp"
using namespace std;

int main()
{

    mytree t;
    int choice;
    do
    {
        // Menu driven program:
        cout << "-----------------MENU--------------------" << endl;
        cout << "1)Input postfix expression" << endl;
        cout << "2)recursive postorder" << endl;
        cout << "3)recursive inorder" << endl;
        cout << "4)recusive preorder" << endl;
        cout << "5)postorder" << endl;
        cout << "6)inorder" << endl;
        cout << "7)preorder" << endl;
        cout << "8) Exit" << endl;
        cout << "------------------------------------------" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            t.input();
            t.create();
            break;
        case 2:
            t.rec_postorder(t.get_root());
            break;
        case 3:
            t.rec_inorder(t.get_root());
            break;
        case 4:
            t.rec_preorder(t.get_root());
            break;
        case 5:
            t.postorder(t.get_root());
            break;
        case 6:
            t.inorder(t.get_root());
            break;
        case 7:
            t.preorder(t.get_root());
            break;
        default:
            cout << "Invalid entry" << endl;
            break;
        }

    } while (true);
    return 0;
}