#include <bits/stdc++.h>
using namespace std;

// //class and object
class BankAccount{
   private:
      string name;
      double balance;
   public:
      BankAccount(string name,double balance){
         this->name=name;
         this->balance=balance;
      }
      string getName(){
          return name;
      }
      double getBalance(){
         return balance;
      }
      void addBalance(double amt){
         balance+=amt;
      }
      void withdrawBalance(double amt){
         if(balance>0)
           balance-=amt;
         else
            cout<<"withdrawal limit exceeded"<<endl;
      }

};
//Object
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    BankAccount b("Gokul",10000);
    b.addBalance(1000);
    cout<<b.getBalance()<<endl;
    b.withdrawBalance(500);
    cout<<b.getBalance()<<endl;

}