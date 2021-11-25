#include <iostream>
 using namespace std;

 class student                                                   //Parent class
 {
     int rno;
     public:
     void get_no()
     {
         cout<<"Enter roll no"<<endl;
         cin>>rno;
     }
     void put_no()
     {
         cout<<"roll no:"<<rno<<"\n";
     }
 };
 class test:public student{                                       //inherited class of student class
     protected:
     float part1,part2;
     public:
     void get_marks()
     {
         cout<<" enter part 1 marks"<<endl;
         cin>>part1;
         cout<<" enter part 2 marks"<<endl;
         cin>>part2;        
     }
     void put_marks()
     {
         cout<<"Marks obtained"<<"\n";
         cout<<"part 1:"<<part1<<endl<<"part2:"<<part2<<endl;
     }
 };
 class sports                                                     //Spots class
 {
     protected:
     float score;
     public:
     void get_score()
     {
         cout<<"enter score"<<endl;
         cin>>score;
     }
     void put_score()
     {
         cout<<"spots score is:"<<score<<"\n";
     }
 };
 class result:public test,public sports                          //inherited result class of sports ans test 
 {
     float total;
     public:
     void display()
     {
         total=part1+part2+score;
         put_no();
         put_marks();
         put_score();
         cout<<"Total score:"<<total<<endl;
     }
 };
 int main()
 {
     result r;
     r.get_no();
     r.get_marks();
     r.get_score();
     r.display();
     return 0;
 }