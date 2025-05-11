#include <bits/stdc++.h>
using namespace std;

// //class and object
class Animal{
     public:
      void eat(){
         cout<<"The animal eats"<<endl;
      }
};
class Dog:public Animal{
   public:
     void barks(){
       cout<<"dog can barks"<<endl;
     }
};
class Mammal: public Dog{
   public:
      void both(){
         cout<<"A mammal can do both"<<endl;
      }
};
//Object
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    Mammal m;
    m.barks();
   //m.eat();
   m.both();
}