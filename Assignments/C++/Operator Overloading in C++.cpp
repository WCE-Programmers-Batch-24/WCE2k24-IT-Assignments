#include <bits/stdc++.h>
using namespace std;

class Time{
    private:
    int hr, min;

    public:
    Time(){
        hr = 0;
        min = 0;
    }

    void setTime(){
        cout << "\nEnter the hour: ";
        cin >> hr;
        cout << "Enter the minute: ";
        cin >> min;
    }

    Time operator+(Time t1){
        Time t;

        t.min = (min + t1.min)%60;
        t.hr = (min + t1.min)/60 + hr + t1.hr;
        t.hr %= 12;

        return t;
    }

    void display(){
        cout<< hr<< ":"<< min;
    }
};

int main(){
    Time t1,t2,t3;
 
    cout << "Enter the current time: ";
    t1.setTime();

    cout << "\nEnter the time to add: ";
    t2.setTime();

    t3 = t1 + t2;    

    cout << "\nInitial time: ";
    t1.display();
    cout << "\nTime to add: ";
    t2.display();

    cout << "\nSum of times: ";
    t3.display();

    return 0;
}