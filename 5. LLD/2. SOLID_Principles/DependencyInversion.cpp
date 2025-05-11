#include <bits/stdc++.h>
using namespace std;

// //class and object
class RecommendationStrategy{
  public:
      virtual void recommend()=0;
};
class RecentlyAdded:public RecommendationStrategy{
  public:
      void recommend(){
         cout<<"Recently added Recommended"<<endl;
      }
};
class TrendingNow:public RecommendationStrategy{
  public:
      void recommend(){
         cout<<"Trending Now Recommended"<<endl;
      }
};
class RecommendationEngine{
   public:
       RecommendationStrategy*strategy;

       RecommendationEngine(RecommendationStrategy*strategy):
          strategy(strategy) {}
        
       void recommendations(){
          strategy->recommend();
       }
};
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
   RecommendationStrategy*r=new RecentlyAdded();
   RecommendationEngine engine(r);
   engine.recommendations();
}