#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       
        for (int i = 0; i < nums.size(); i++) {
            int first = nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                int second = nums[j];
                if (first + second == target) {
                    return { i, j };
                }
			}
		}
		return {};

    }
};
int main() {
	Solution s;
	vector<int> nums = { 2,7,11,15 };
	int target = 9;
	vector<int> result = s.twoSum(nums, target);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	return 0;

}