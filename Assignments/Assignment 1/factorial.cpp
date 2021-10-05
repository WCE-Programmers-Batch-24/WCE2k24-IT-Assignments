#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll Factorial(ll x){
    if(x<=1) return 1;
    return x*Factorial(x-1);
}

int main(){
    ll n;

    cout<<"Enter a number:";
    cin>>n;

    cout<<"The factorial of entered number ("<<n<<") is: "<<Factorial(n)<<endl;

    return 0;
}