#include <bits/stdc++.h>
#include "Stack.hpp"
using namespace std;

int main(){
    Stack<Node> s;

    // Menu for Stack ADT
    int choice;
    while(1){
        cout << "-------------MENU-------------\n";
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                int data;
                cout << "Enter data: ";
                cin >> data;
                s.Push(data);
                break;
            case 2:
                s.Pop();
                break;
            case 3:
                s.Display();
                break;
            case 4:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }
    return 0;
}