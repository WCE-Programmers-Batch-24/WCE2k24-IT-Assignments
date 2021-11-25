#include<iostream>
#include<conio.h>
using namespace std;  //

class student {
protected:
    int no;
public:

    void get() {
        cout << "Roll no:";
        cin>>no;
        
    
    }
};
class test: virtual public student{
    protected:
    int sub1,sub2;
    public:
    void getmarks( ){
    cout << "Marks in two subjects:";
        cin >> sub1>>sub2;
    }
};
class sports: virtual public student{
protected:
    int sporM; 
public:

    void getsm() {
        cout << "\nEnter the sports mark :";
        cin>>sporM;

    }
};
    class result : public test, public sports {
    int total, avg;
public:

    void display() {
        total = (sub1 + sub2 + sporM);
        avg = total / 3;
        cout << "\n\n\tRoll No    : " << no << "\n\tTotal      : " << total;
        cout << "\n\tAverage    : " << avg;
    }
};
int main( ){
    result obj;
    obj.get( );
    obj.getmarks( );
    obj.getsm( );
    obj.display( );
}