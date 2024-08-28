#include <iostream>
#include <vector>
using namespace std;


int main ()
{
   int n;
   cin>>n;
   int magic;
   cin>>magic;
   vector<int> grams(n,0);
   for (auto & i : grams){
    cin>>i;
   }
   vector<int> ingredient(n,0);
   for(auto &i : ingredient){
    cin>>i;
   }
   int count = 0;
   for (int i=0;i<n;i++){
      if(ingredient[i]>=grams[i]){
        if(i==n-1){
         count++;
        }
        ingredient[i]-=grams[i];
      }
      else {
         if(magic==0){
           break;
         }
         else if(grams[i]-ingredient[i] <= magic){
            if(i==n-1){
               count++;
            }
            magic-=grams[i]-ingredient[i];
            ingredient[i]=0;

         }
         else{
            break;
         }
      }
      if(i==n-1){
           i=-1;
      }
      
   }
   cout<<count;
}

