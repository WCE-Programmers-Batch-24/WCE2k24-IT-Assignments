/*
   ____   _                  _                    _       _           _                 _     _       _         _   
  / ___| (_)  _ __   _   _  | |   __ _   _ __    | |     (_)  _ __   | | __   ___    __| |   | |     (_)  ___  | |_ 
 | |     | | | '__| | | | | | |  / _` | | '__|   | |     | | | '_ \  | |/ /  / _ \  / _` |   | |     | | / __| | __|
 | |___  | | | |    | |_| | | | | (_| | | |      | |___  | | | | | | |   <  |  __/ | (_| |   | |___  | | \__ \ | |_ 
  \____| |_| |_|     \__,_| |_|  \__,_| |_|      |_____| |_| |_| |_| |_|\_\  \___|  \__,_|   |_____| |_| |___/  \__|
                                                                                                                    
*/

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int d){
        data = d;
        next = NULL;
    }
};

class Head{
    public:
    int count;
    Node *first;
    Node *last;

    Head(int c, Node *f, Node* l){
        this->count = c;
        this->first = f;
        this->last = l;
    }
};

// Function to insert at head of circular linked list
void insertAtHead(Head *head, int data){
    Node *newNode = new Node(data);
    
    if(head->count == 0){
        head->first = newNode;
        head->last = newNode;

        head->first->next = head->last;
        head->last->next = head->first;
    }
    else{
        newNode->next = head->first;
        head->first = newNode;
        head->last->next = head->first;
    }
    head->count++;
}

// Function to insert at tail of circular linked list
void insertAtTail(Head *head, int data){
    Node *newNode = new Node(data);
    
    if(head->count == 0){
        head->first = newNode;
        head->last = newNode;

        head->first->next = head->last;
        head->last->next = head->first;
    }
    else{
        head->last->next = newNode;
        head->last = newNode;
        head->last->next = head->first;
    }
    head->count++;
}

// Fucntion to insert at any position of circular linked list
void insertAfter(Head *head, int data, int pos){
    Node *newNode = new Node(data);
    Node *temp = head->first;
    Node *prev = head->first;

    if(pos == 1){
        insertAtHead(head, data);
    }
    else if(pos == head->count + 1){
        insertAtTail(head, data);
    }
    else{
        for(int i = 1; i < pos; i++){
            prev = temp;
            temp = temp->next;
        }
        prev->next = newNode;
        newNode->next = temp;
        head->count++;
    }
}

// Function to delete a node by value from circular linked list
void deleteByValue(Head *head, int data){
    Node *temp = head->first;
    Node *prev = head->first;

    if(head->count == 0){
        cout << "List is empty" << endl;
    }
    else if(head->count == 1){
        if(head->first->data == data){
            head->first = NULL;
            head->last = NULL;
            head->count--;
        }
        else{
            cout << "Element not found" << endl;
        }
    }
    else{
        if(head->first->data == data){
            head->first = head->first->next;
            head->last->next = head->first;
            head->count--;
        }
        else{
            while(temp->data != data){
                prev = temp;
                temp = temp->next;
            }
            if(temp->data == data){
                prev->next = temp->next;
                head->count--;
            }
            else{
                cout << "Element not found" << endl;
            }
        }
    }
}

// Function to delete a node by position from circular linked list
void deleteByPos(Head *head, int pos){
    Node *temp = head->first;
    Node *prev = head->first;

    if(head->count == 0){
        cout << "List is empty" << endl;
    }
    else if(head->count == 1){
        if(pos == 1){
            head->first = NULL;
            head->last = NULL;
            head->count--;
        }
        else{
            cout << "Element not found" << endl;
        }
    }
    else{
        if(pos == 1){
            head->first = head->first->next;
            head->last->next = head->first;
            head->count--;
        }
        else if(pos == head->count){
            while(temp->next != head->first){
                prev = temp;
                temp = temp->next;
            }
            prev->next = head->first;
            head->last = prev;
            head->count--;
        }
        else{
            for(int i = 1; i < pos; i++){
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            head->count--;
        }
    }
}

// Function to search a node by value from circular linked list
void searchByValue(Head *head, int data){
    Node *temp = head->first;

    if(head->count == 0){
        cout << "List is empty" << endl;
    }
    else{
        for(int i=0; i<head->count; i++){
            if(temp->data == data){
                cout << "Element found at position " << i+1 << endl;
                return;
            }
            else{
                temp = temp->next;
            }
        }
    }
}

// Function to print circular linked list
void printList(Head *head){
    Node *temp = head->first;

    if(head->count == 0){
        cout << "List is empty" << endl;
    }
    else{
        for(int i=0; i<head->count; i++){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main(){
    Head* h = new Head(0, NULL, NULL);

    int opt, data, index;
    char choice;
    while(1){
        cout<<"\nMENU\n a. Add directly to LinkedList.\n b. Use functions.\n";
        cout<<"Choose: ";
        cin>>choice;

        switch (choice){

        case 'a':
            int num;
            cout<<"Enter the data to add in LinkedList (enter '-1' if you want stop): ";
            while(1){
                cin>>num;
                if(num == -1) break;

                Node* addNode = new Node(num);
                if(h->count == 0){
                    h->first = addNode;
                    h->last = addNode;
                    addNode->next = h->first;

                    h->count++;
                }
                else{
                    h->last->next = addNode;
                    h->last = addNode;
                    addNode->next = h->first;

                    h->count++;    
                }
            }
            break;

            case 'b':
            cout<<"\nMENU 1.0\n 1.Add at head\n 2.Add at tail\n 3.Add after\n 4.Delete (by Value)\n 5.Delete (by Index))\n 6.Search\n 7.Display the List\n 8.Exit\n";
            cout<<"Enter your option: ";
            
            cin>>opt;
            cout<<"\n";
            if(opt>7) break;

            switch(opt){

                case 1:
                    cout<<"Enter data to add: ";
                    cin>>data;
                    cout<<"Adding data...\n";
                    insertAtHead(h, data);
                    cout<<"\n";
                    break;

                case 2:
                    cout<<"Enter data to add: ";
                    cin>>data;
                    cout<<"Adding data...\n";
                    insertAtTail(h, data);
                    cout<<"\n";
                    break;
                
                case 3:
                    cout<<"Enter the index: ";
                    cin>>index;
                    cout<<"Enter data to add: ";
                    cin>>data;
                    cout<<"Adding data...\n";
                    insertAfter(h, data, index);
                    cout<<"\n";
                    break;
                
                case 4:
                    cout<<"Enter data to delete: ";
                    cin>>data;
                    cout<<"Deleting data...\n";
                    deleteByValue(h, data);
                    cout<<"\n";
                    break;

                case 5:
                    cout<<"Enter the index: ";
                    cin>>index;
                    cout<<"Deleting data...\n";
                    deleteByPos(h, index);
                    cout<<"\n";
                    break;
                
                case 6:
                    cout<<"Enter data to search: ";
                    cin>>data;
                    cout<<"Searching data...\n";
                    searchByValue(h, data);
                    cout<<endl;
                    break;

                case 7:
                    cout<<"Displaying the LinkedList: ";
                    printList(h);
                    cout<<"\n";
                    break;
                
                default: 
                    break;

            }
        
        default:
            break;
        }
    }

    return 0;
}