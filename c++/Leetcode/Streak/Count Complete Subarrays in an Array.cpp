#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            unordered_map<int, int> fullMap;
            for (int num : nums) fullMap[num]++;
            int totalDistinct = fullMap.size();

            int count = 0;
            unordered_map<int, int> windowMap;
            int left = 0;

            for (int right = 0; right < nums.size(); ++right) {
                windowMap[nums[right]]++;

                while (windowMap.size() == totalDistinct) {
                    count += (nums.size() - right);
                    windowMap[nums[left]]--;
                    if (windowMap[nums[left]] == 0) {
                        windowMap.erase(nums[left]);
                    }
                    left++;
                }
            }
            return count;
        }
};