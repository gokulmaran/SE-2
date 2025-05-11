#include <bits/stdc++.h>
using namespace std;

class PaymentManager{
   private:
       PaymentManager(){
         cout<<"Payment manager intialised.."<<endl;
       }
   static mutex mtx;
   static PaymentManager*instance;
   public:
   static PaymentManager*getInstance(){
       if(instance==nullptr){
         lock_guard<mutex>lock(mtx);
         if(instance==nullptr){
            instance= new PaymentManager();
         }
       }
       return instance;
   }
};
 PaymentManager*PaymentManager::instance=nullptr;
 mutex PaymentManager::mtx;
// Main function
int main() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    PaymentManager*p=PaymentManager::getInstance();
     PaymentManager*p2=PaymentManager::getInstance();
    
      if (p == p2)
    {
        cout << "Both instances are the same. Singleton pattern is working" << endl;
    }
    else
    {
        cout << "Singleton pattern is not working correctly" << endl;
    }
    return 0;
}
