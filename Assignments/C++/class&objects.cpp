#include <iostream>

using namespace std;

class box{
    int h,l,b;
    
    public:
    int vol(int , int , int);
};

int box :: vol(int a , int b, int c){
    h=a;
    l=b;
    b=c;
    int ans=h*l*b;
    return ans;
}

int main(){
    int h,l,b;
    cin >> h >> l >> b;
    box v1;
    cout << v1.vol(h,l,b);

    return 0;
}