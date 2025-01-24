#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp, vector<vector<int>>& directions) {
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int longest = 1;
        for (auto& dir : directions) {
            int ni = i + dir[0];
            int nj = j + dir[1];
            if (ni >= 0 && ni < matrix.size() && nj >= 0 && nj < matrix[0].size() && matrix[ni][nj] > matrix[i][j]) {
                longest = max(longest, 1 + dfs(ni, nj, matrix, dp, directions)); // 1 + recursive result
            }
        }
        dp[i][j] = longest;
        return longest;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0; 
        }
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int longestPath = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                longestPath = max(longestPath, dfs(i, j, matrix, dp, directions));
            }
        }
        return longestPath;
    }
};
