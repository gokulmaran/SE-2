#include <bits/stdc++.h>
using namespace std;

// //class and object
class A{
    public:
      static int count;
      
      A(){
         count++;
      }

      static void display(){
         cout<<count<<endl;
      }
};
//Object
int A::count=0;

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    A a;
    A b;

    A::display();
}