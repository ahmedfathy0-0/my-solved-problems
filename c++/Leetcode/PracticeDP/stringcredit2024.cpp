#include <iostream>
#include <vector>
#include <string>
using namespace std;

int findSubgroups(string& s, int idx, int lastSum, vector<vector<int>>& dp) {
    int n = s.size();
    if (idx == n) {
        return 1; 
    }
    if (dp[idx][lastSum] != -1) {
        return dp[idx][lastSum]; 
    }

    int sum = 0;
    int ways = 0;
    for (int i = idx; i < n; i++) {
        sum += (s[i] - '0');
        if (sum >= lastSum) { 
            ways += findSubgroups(s, i + 1, sum, dp); 
        }
    }
    return dp[idx][lastSum] = ways; 
}

int main() {
    string s = "1119";
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n * 9 + 1, -1)); 
    cout << "Total valid subgroups: " << findSubgroups(s, 0, 0, dp) << endl;
    return 0;
}
