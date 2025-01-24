#include <cmath>
#include <climits>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int mincost(vector<int> &cuts, vector<vector<int>> &dp, int start, int end, int st, int ed) {
    if (st >= ed) {
        return 0;
    }

    int minimumCost = INT_MAX;
    for (int i = st; i < ed; i++) {
        if (dp[i][end - start] < 0) {
            dp[i][end - start] = (end - start) +
                                 mincost(cuts, dp, start, cuts[i], st, i) +
                                 mincost(cuts, dp, cuts[i], end, i + 1, ed);
        }
        if (dp[i][end - start] < minimumCost) {
            minimumCost = dp[i][end - start];
        }
    }
    return minimumCost;
}

int main() {
    int cost;
    cin >> cost;
    int n;
    cin >> n;
    vector<int> cuts(n);
    for (int i = 0; i < n; i++) {
        cin >> cuts[i];
    }
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(n, vector<int>(cost + 1, -1));
    cout << mincost(cuts, dp, 0, cost, 0, n);
    return 0;
}
