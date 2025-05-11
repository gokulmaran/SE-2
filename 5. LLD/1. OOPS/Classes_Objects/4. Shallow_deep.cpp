#include <bits/stdc++.h>
using namespace std;

// //shallow vs deep copy
class A{
  public:
      char*data;

      A(char*val){
        data=new char(strlen(val)+1);
        strcpy(data,val);
      }

      A(A &obj){
        //data=obj.data;
        data=new char(strlen(obj.data)+1);
        strcpy(data,obj.data);
      }

      void display(){
        cout<<data<<endl;
      }
};
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    A a("Hello");
    A b=a;
    a.display();
    b.display();
    a.data[0]='g';
    a.display();
    b.display();
}