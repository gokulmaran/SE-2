#include <bits/stdc++.h>
using namespace std;

// //class and object
class A{
     public:
        string name;
        int salary;

        A(string val,int amount){
         this->name=val;
         this->salary=amount;
        }
        
        A(A &a){
          this->name=a.name;
          this->salary=a.salary;
        }
};
//Object
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    A b("Gokul",100000);

    A c=b;

    cout<<c.name<<endl;
    cout<<c.salary<<endl;

}