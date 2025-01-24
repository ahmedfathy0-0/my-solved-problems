#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> dp(prices.size()+1,-1);
        return maxi(prices,dp,1);
    }
    int maxi(vector<int>& prices,vector<int>&dp,int index){
        if (index > prices.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        else {
            int choice1 = maxi(prices,dp,index+1);
            int choice2 = maxi(prices,dp,index+2)+prices[index-1];
            int choice3 = maxi(prices,dp,index+3)-prices[index-1];
            dp[index] = max(choice1,max(choice2,choice3));
            return dp[index];
        }

    }
};
int main()
{
}