#include <iostream>

using namespace std;

#define n 100

class queue{
    public:
    int bottom;
    int* arr;
    queue(){
        arr = new int[n];
        bottom = 0; 
    }

    void enqueue(int data){
        if(bottom == n){
            cout << "Queue is full" << endl;
            return;
        }
        else{
            arr[bottom] = data;
            bottom++;
        }
        return;
    }

    void dequeue(){
        if(bottom == 0){
            cout << "Queue is empty" << endl;
            return;
        }
        else{
            for(int i=0; i< bottom-1; i++){
                arr[i] = arr[i+1];
            }
            bottom--;
        }
        return;
    }

    void displayqueue(){
        for(int i=0; i<bottom; i++){
            cout << arr[i] << " <- ";
        }
        cout << endl;
        return;
    }

};

int main(){
    queue q1;

    int a = 0;

    while(a != 4){
        cout << "1. enqueue" << endl << "2. dequeue" << endl << "3. display" << endl << "4. exit" << endl << endl << endl;
        cin >> a;
        switch (a)
        {
            case 1:  
                int data;
                cout << "enter data" << endl;
                cin >> data;
                q1.enqueue(data);
                break;
            
            case 2: 
                q1.dequeue();
                break;

            case 3:
                q1.displayqueue();
                break;

            case 4:
                cout << "exited" << endl;
                break;

            default :
                cout << "enter valid choice" << endl;
        }
    }

    return 0;
}