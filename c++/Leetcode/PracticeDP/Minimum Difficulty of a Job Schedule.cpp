#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (d > n) {
            return -1; 
        }
        vector<vector<int>> dp(n, vector<int>(d + 1, -1));
        return totalD(jobDifficulty, d, 0, dp);
    }

    int totalD(vector<int>& jobDifficulty, int d, int index, vector<vector<int>>& dp) {
        int n = jobDifficulty.size();
        if (d == 0 && index == n) {
            return 0; 
        }
        if (d == 0 || index == n) {
            return INT_MAX; 
        }
        if (dp[index][d] != -1) {
            return dp[index][d];
        }

        int maxDifficulty = 0;
        int result = INT_MAX;

        for (int i = index; i < n; ++i) {
            maxDifficulty = max(maxDifficulty, jobDifficulty[i]); 
            int nextDay = totalD(jobDifficulty, d - 1, i + 1, dp); 
            if (nextDay != INT_MAX) {
                result = min(result, maxDifficulty + nextDay);
            }
        }

        dp[index][d] = result;
        return result;
    }
};

int main() {
    Solution s;
    vector<int> jobDifficulty = {6, 5, 4, 3, 2, 1};
    int d = 2;
    cout << s.minDifficulty(jobDifficulty, d) << endl; 
    return 0;
}
