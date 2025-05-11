#include <bits/stdc++.h>
using namespace std;

// //class and object
class A{
   private:
   int salary;
     string employeeName;
  public:
     

     void setName(string s){
        employeeName=s;
     }

     void setSalary(int l){
        salary=l;
     }

     int getSalary(){
        return salary;
     }
};
//Object
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
     A a;
     a.setName("Gokul");
     a.setSalary(100000);
     cout<<a.getSalary();

}