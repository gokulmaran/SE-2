#include <bits/stdc++.h>
using namespace std;

// //class and object
class Passport{
   private:
      string passportNumber;
   public:
      Passport(){
         this->passportNumber="";
      }
      Passport(string passportNumber){
           this->passportNumber=passportNumber;
      }
      string getPassport(){
         return passportNumber;
      }
};
class Student{
  private:
      string name;
      Passport* passport;
   public:
      Student(string name,Passport* passport){
         this->name=name;
         this->passport=passport;
      }

     void displayDetails(){
        cout<<"Student name: "<<name<<endl;
        cout<<"Passport Number: "<<passport->getPassport()<<endl;
     }
};
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    Passport a("BNGTPG6132Q");
    Student s("Gokul",&a);
    s.displayDetails();
}