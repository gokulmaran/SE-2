#include <bits/stdc++.h>
using namespace std;

// //class and object
class Notification{
    public:
       virtual void sendNotifications(){
         cout<<"Notification sent"<<endl;
       } 
};
class EmailNotification: public Notification{
    public:
       void sendNotifications(){
         cout<<"Email Notification sent"<<endl;
       }
};
class TextNotification: public Notification{
     public:
       void sendNotifications(){
         cout<<"Text Notification sent"<<endl;
       }
};

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
   Notification*Text=new TextNotification();
   Text->sendNotifications();
}