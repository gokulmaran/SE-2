#include <bits/stdc++.h>
using namespace std;

// //class and object
class A{
    public:
      int add(int a,int b){
         return a+b;
      }
      void add(double a,double b){
         cout<<" "<<a<<" "<<b;
      }
};
//Object
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
   A a;
   //cout<<a.add(4,5);
    a.add(4.5,5.5);
}