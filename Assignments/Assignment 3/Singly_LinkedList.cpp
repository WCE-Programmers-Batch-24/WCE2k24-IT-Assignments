/*
   ____    _                   _             _       _           _                 _     _       _         _   
 / ___|  (_)  _ __     __ _  | |  _   _    | |     (_)  _ __   | | __   ___    __| |   | |     (_)  ___  | |_ 
 \___ \  | | | '_ \   / _` | | | | | | |   | |     | | | '_ \  | |/ /  / _ \  / _` |   | |     | | / __| | __|
  ___) | | | | | | | | (_| | | | | |_| |   | |___  | | | | | | |   <  |  __/ | (_| |   | |___  | | \__ \ | |_ 
 |____/  |_| |_| |_|  \__, | |_|  \__, |   |_____| |_| |_| |_| |_|\_\  \___|  \__,_|   |_____| |_| |___/  \__|
                      |___/       |___/                                                                       
*/

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
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

void InsertAtFront(Head *h, int data){

    Node* new_node = new Node(data);

    if(h->count==0){
        h->first = new_node;
        h->last = new_node;
        h->count++;

        return;
    }
    else{
        new_node->next = h->first;
        h->first = new_node;
        h->count++;

        return;
    }
}

void InsertAtBack(Head *h, int data){

    Node* new_node = new Node(data);
    if(h->count==0){
        h->first = new_node;
        h->last = new_node;
        h->count++;

        return;
    }
    else{
        Node* p = h->first;

        for(int i=0; i<h->count; i++){

            if(p->next==NULL){
                p->next = new_node;
                h->count++;
                return;
            }
            p = p->next;
        }
    }
}

void insertAfter(Head *h, int data, int location){
    
    if(location == 0){
        InsertAtFront(h, data);
        return;
    }
    else{
        Node* new_node = new Node(data);

        Node* p = h->first;

        for(int i=1; i<h->count; i++){
        
            if(i==location){
                new_node->next = p->next;
                p->next = new_node;
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

void printList(Head *h){
    Node* p = new Node(0);

    p = h->first;

    for(int i=0; i<h->count; i++){
        cout<<p->data<<" ";
        p = p->next;
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
                    InsertAtFront(h, data);
                    cout<<"\n";
                    break;

                case 2:
                    cout<<"Enter data to add: ";
                    cin>>data;
                    cout<<"Adding data...\n";
                    InsertAtBack(h, data);
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
                    searchList(h, data);
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