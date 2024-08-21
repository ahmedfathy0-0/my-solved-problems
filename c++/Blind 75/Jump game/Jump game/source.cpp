#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
		int goal = nums.size() - 1;
		for (int i = nums.size() - 2; i >= 0; i--) {
			if (i + nums[i] >= goal) {
				goal = i;
			}
		}
		if (goal == 0) return true;
		return false;

    }
};
int main() {
	Solution s;
	vector<int> nums = { 2, 3, 1, 1, 4 };
	cout << s.canJump(nums) << endl;
	return 0;
}