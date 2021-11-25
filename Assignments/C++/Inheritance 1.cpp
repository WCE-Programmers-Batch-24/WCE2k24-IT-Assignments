//Q1

#include <iostream>
 using namespace std;
 class Account {
 public:
 float salary = 60000;
 };
 class Programmer: public Account {
 public:
 float bonus = 5000;
 };
 int main(void) {
 Programmer p1;
 cout<<"Salary: "<<p1.salary<<endl;
 cout<<"Bonus: "<<p1.bonus<<endl;
 return 0;
 }





 //Q2

 #include <iostream>
using namespace std;
class Animal {
public:
void eat() {
cout<<"Eating..."<<endl;
}
};
class Dog: public Animal
 {
 public:
 void bark(){ 
 cout<<"Barking...";
 }
 };
 int main(void) {
 Dog d1;
 d1.eat();
 d1.bark();
 return 0;
 }
 