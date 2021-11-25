#include <iostream>
using namespace std;
class complex{
    private:
    int real_prt;
    int imag_prt;

    public:
    complex(){
        real_prt = 0;
        imag_prt = 1;
    }
    complex(int b){
        real_prt = 0;
        imag_prt = b;
    }
    complex(int a , int b){
        real_prt = a;
        imag_prt = b;
    }

    void show(){
        cout << real_prt << "+" << imag_prt << "i" << endl;
    }
};

int main(){
    cout << endl;
    cout << "COMPLEX NUMBERS" << endl;
    int real = 10;
    int imag = 20;
    complex num1;
    complex num2(imag);
    complex num3(real , imag);
    num1.show();
    num2.show();
    num3.show();
    return 0;
}