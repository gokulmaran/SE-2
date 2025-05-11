#include <bits/stdc++.h>
using namespace std;

class Notification{
  public:
     virtual void notify()=0;
     virtual ~Notification(){}
};
class EmailNotification:public Notification{
   public:
      void notify(){
         cout<<"email notification sent"<<endl;
      }
};
class TextNotification:public Notification{
   public:
      void notify(){
         cout<<"text notification sent"<<endl;
      }
};
class NotificationFactory{
  public: 
      static Notification*send(string type){
          if(type=="email"){
            return new EmailNotification();
          }
          return new TextNotification();
      }
};
// Main function
int main() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    Notification*n=NotificationFactory::send("email");
    n->notify();
    delete n;
    return 0;
}
