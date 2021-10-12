/*
    Ackerman Function :-

                _
              /  x  + 1             if y=0
    A(y,x) = |  A(y-1,1)            if (y>0) & x=0
             \  A(y-1, A(y, x-1))   if (y>0) & (x>0)
              \ _
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int Ackermann(int y, int x){
    if(!y){
        return (x + 1);
    }
    else if((y>0) && (!x)){
        return Ackermann(y-1, 1);
    }
    else if((y>0) && (x>0)){
        return Ackermann(y-1, Ackermann(y, x-1));
    }
}

int main(){
    int ack, y, x;
    cin>>y>>x;

    ack = Ackermann(y, x);
    cout<<ack<<endl;
    
    return 0;
}


/*
    For visualization of the working code and the memory visit "https://gfredericks.com/things/arith/ackermann"
*/
