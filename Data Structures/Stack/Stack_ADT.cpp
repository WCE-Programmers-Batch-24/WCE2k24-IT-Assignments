#include<iostream>
#include<stack>
using namespace std;
int main(){
   stack<int> stk;
   if(stk.empty()){
      cout << "Stack is empty" << endl;
   } else {
      cout << "Stack is not empty" << endl;
   }
   //insert elements into stack
   stk.push(5);
   stk.push(10);
   stk.push(15);
   stk.push(20);
   
   cout << "Size of the stack: " << stk.size() << endl;
   
   while(!stk.empty()){
      int item = stk.top(); 
      stk.pop();
      cout << item << " ";
   }
   return 0;	
	
}
