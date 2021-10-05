//CPP program to generate fibonacci series by using recursion
#include<iostream>
using namespace std;

int fibo(int n){
    if(n<=1)
       return n;
    
    return (fibo(n-1) + fibo(n-2));
}

int main(){
    int num;
    cout<<"Enter integer:";
    cin>>num;
    int fibo(int);

    cout<<"Fibonacci series is:";
    for(int i=0; i<num; i++){
        cout<<fibo(i)<<" ";
    }
    return 0;
}