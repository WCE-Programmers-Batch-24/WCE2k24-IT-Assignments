#include <bits/stdc++.h>
 using namespace std;

 class student {
 public:
 string name;
 int roll;
 student()
 {
     string n;
     cout<<"Enter the name of the student: "<<endl;
     cin>>n;
    name =n;
     cout<<"Enter roll no. of the student: "<<endl;
     int r;
     cin>>r;
     roll =r;

 }
 };

 class result: public student {
 public:
 int phy;
 int chem;
 int math;

 float average;
    
 result()
 {
     int n1;
     cout<<"Enter the marks obtained in physics: ";
     cin>>n1;
     phy=n1;
     cout<<"Enter the marks obtained in chemistry: ";
     int n2;
     cin>>n2;
     chem = n2;
     int n3;
     cout<<"Enter the marks obtained in maths: ";
     cin>>n3;
     math=n3;

     cout<<"The Average Marks obtained are : "<<(float)(n1+n2+n3)/3<<endl<<endl;
     average = (float)(n1+n2+n3)/3;
     

 }

    void display(int i)
    {
        
    cout<<"---------------------------------"<<name<<"'s Result---------------------------------"<<endl;
        cout<<"Roll No. "<<roll<<endl;
        cout<<"The marks obtained in physics are : "<<phy<<endl;
        cout<<"The marks obtained in chemistry are : "<<chem<<endl;
        cout<<"The marks obtained in maths are : "<<math<<endl;

        cout<<"The average marks obtained by "<<name<<" are "<<average<<endl;
        if(average>=35)
        cout<<name<<" has passed the examination\n\n";
        else
        cout<<name<<" has failed the examination\n\n";

    cout<<"------------------------------------------------------------------------"<<endl;
    }

 };

 int main() 
 {
    int size;
    cout<<"Enter the no. of students: "<<endl;
    cin>>size;
    result r[size];

    for (int i = 0; i < size; i++)
    {
        r[i].display(i);
    }
       
 return 0;
 }

 