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
class Cat: public Animal{
   public:
      void meow(){
         cout<<"cat can meows"<<endl;
      }
};
//Object
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    Cat c;
   c.eat();
   c.meow();
}