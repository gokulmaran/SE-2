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
      vector<Passport*> passports;
   public:
      Student(string name){
         this->name=name;
      }
      void add(Passport*passport){
         passports.push_back(passport);
      }

     void displayDetails(){
        cout<<"Student name: "<<name<<endl;
        for(auto i:passports)
        cout<<"Passport Number: "<<i->getPassport()<<endl;
     }
};
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    Passport a("BNGTPG6132Q");
    Passport b("123456");
    Student s("Gokul");
    s.add(&a);
    s.add(&b);
    s.displayDetails();
}