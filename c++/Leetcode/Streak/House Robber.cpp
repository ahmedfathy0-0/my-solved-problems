#include <iostream>
#include <vector>   
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return maxi(nums,dp,1);
    }
    int maxi(vector<int>& nums,vector<int>& dp,int index){
        if(index>nums.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        else{
            int choice1 = maxi(nums,dp,index+1);
            int choice2 = maxi(nums,dp,index+2)+nums[index-1];
            dp[index] = max(choice1,choice2);
            return dp[index];
        }
    }
};