/*
  ____                    _       _             _       _           _                 _     _       _         _   
 |  _ \    ___    _   _  | |__   | |  _   _    | |     (_)  _ __   | | __   ___    __| |   | |     (_)  ___  | |_ 
 | | | |  / _ \  | | | | | '_ \  | | | | | |   | |     | | | '_ \  | |/ /  / _ \  / _` |   | |     | | / __| | __|
 | |_| | | (_) | | |_| | | |_) | | | | |_| |   | |___  | | | | | | |   <  |  __/ | (_| |   | |___  | | \__ \ | |_ 
 |____/   \___/   \__,_| |_.__/  |_|  \__, |   |_____| |_| |_| |_| |_|\_\  \___|  \__,_|   |_____| |_| |___/  \__|
                                      |___/                                                                       
*/

#include <bits/stdc++.h>
using namespace  std;

class Node{
    public:

    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

};

class Head{
    public:

    int count;
    Node* first;
    Node* last;

    Head(int count, Node* f, Node* l){
        this->count = count;
        this->first = f;
        this->last = l;
    }
};

/*
  insertAtHead function
*/
void insertAtHead(Head* h, int data){

    Node* new_node = new Node(data);

    if(h->count == 0){
        h->first = new_node;
        h->last = new_node;
        h->count++;
    }
    else{
        new_node->next = h->first;
        h->first->prev = new_node;

        h->first = new_node;
        h->count++;
    }
}

/*
  InsertAtTail function
*/
void insertAtTail(Head* h, int data){

    if(h->count == 0){
        insertAtHead(h, data);
        return;
    }
    else{
        Node* new_node = new Node(data);

        h->last->next = new_node;
        new_node->prev = h->last;
        h->count++;
        return;
    }
}

void insertAfter(Head* h, int data, int location){
    
    if(location == 0){
        insertAtHead(h, data);
        return;
    }
    else if(location == h->count){
        insertAtTail(h, data);
        return;
    }
    else{
        Node* p = h->first;
        Node* new_node = new Node(data);

        for(int i=1; i<h->count; i++){
            if(i == location){
                new_node->next = p->next;
                new_node->prev = p;

                p->next = new_node;
                new_node->next->prev = new_node;
                h->count++;

                return;
            }

            p = p->next;
        }
    }
}

void delNode_byVal(Head* h, int val){

    if(h->count==0){
        cout<<"List is empty, can't delete."<<"\n";
        return;
    }

    Node* p = h->first;
    
    //  To Del head
    if(p->data==val){
        h->first = p->next;
        p->next = NULL;
        free(p);
        h->count--;

        return;
    }
    
    Node* q;
    for(int i=0; i<h->count; i++){

        if(p->data==val){
            q->next = p->next;
            p->next = NULL;
            free(p);
            h->count--;

            return;
        }

        q = p;
        p = p->next;
    }
}

void delNodeAt(Head* h, int location){

    if(h->count==0){
        cout<<"List is empty, can't delete."<<"\n";
        return;
    }

    Node* p = h->first;
    
    //  To Del head
    if(location==0){
        h->first = p->next;
        p->next = NULL;
        free(p);
        h->count--;

        return;
    }

    Node* q;
    for(int i=1; i<h->count; i++){

        if(i==location){
            q->next = p->next;
            p->next = NULL;
            free(p);
            h->count--;

            return;
        }

        q = p;
        p = p->next;
    }
}

bool searchList(Head* h, int key){
    Node* p = h->first;

    for(int i=0; i<h->count; i++){
        
        if(p->data == key){
            return true;
        }

        p = p->next;
    }

    return false;
}

void printListHead(Head* h){
    Node* p = h->first;

    for(int i=0; i<h->count; i++){
        cout<<p->data<<" ";
        p = p->next;
    }
}

void printListTail(Head* h){
    Node* p = h->last;

    for(int i=0; i<h->count; i++){
        cout<<p->data<<" ";
        p = p->prev;
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
                    h->count++;
                    }
                else{
                    h->last->next = addNode;
                    addNode->prev = h->last;
                    h->last = addNode;
                    h->count++;
                }
            }
            break;
        case 'b':
            cout<<"\nMENU 1.0\n 1.Add at head\n 2.Add at tail\n 3.Add after\n 4.Delete (by Value)\n 5.Delete (by Index))\n 6.Search\n 7.Display from Head\n 8.Display from Tail\n 9.Exit\n";
            cout<<"Enter your option: ";
            
            cin>>opt;
            cout<<"\n";
            if(opt>8) break;

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
                    delNode_byVal(h, data);
                    cout<<"\n";
                    break;

                case 5:
                    cout<<"Enter the index: ";
                    cin>>index;
                    cout<<"Deleting data...\n";
                    delNodeAt(h, index);
                    cout<<"\n";
                    break;
                
                case 6:
                    cout<<"Enter data to search: ";
                    cin>>data;
                    cout<<"Searching data...\n";
                    cout<<searchList(h, data)<<endl;
                    break;

                case 7:
                    cout<<"Displaying the LinkedList from Head: ";
                    printListHead(h);
                    cout<<"\n";
                    break;
                
                case 8:
                    cout<<"Displaying the LinkedList from Tail: ";
                    printListTail(h);
                    cout<<"\n";
                    break;
                
                case 9:
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
