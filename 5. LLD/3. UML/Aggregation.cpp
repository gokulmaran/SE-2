#include <bits/stdc++.h>
using namespace std;

class Department{
   public:
       string name;

       Department(string name){
         this->name=name;
       }

       string getName(){
         return name;
       }
};
class Teacher{
   public:
      string name;
      Department*department;
      Teacher(string name,Department*department){
          this->name=name;
          this->department=department;
      }

      void getDetails(){
         cout<<"Teacher name: "<<name<<endl;
         cout<<"Department name: "<<department->getName()<<endl;
      }
};
// Main function
//Aggeration department class exists,even though Teacher class destroyed
int main() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
     Department d("ECE");
     Teacher t("Gokul",&d);
     t.getDetails();

    return 0;
}
