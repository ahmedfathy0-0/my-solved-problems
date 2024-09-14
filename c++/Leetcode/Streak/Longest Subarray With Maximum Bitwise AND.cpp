#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int Max = *max_element(nums.begin(), nums.end()); 
        int longest = 0;
        int currentLength = 0;

        for (int num : nums) {
            if (num == Max) {
                currentLength++; 
                longest = max(longest, currentLength);
            } else {
                currentLength = 0; 
            }
        }
        
        return longest;
    }
};


int main (){

    vector<int> nums = {1,2,3,3,2,2};
    Solution s;
    cout<<s.longestSubarray(nums)<<endl;

    return 0;
}