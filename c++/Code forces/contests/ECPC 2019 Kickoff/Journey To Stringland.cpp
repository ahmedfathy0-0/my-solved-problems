#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, K;
string S;
vector<vector<vector<int>>> dp;

int solve(int i, int j, int k) {

    if (k == 0) return 0;          
    if (i > j) return INF;         
    if (k == 1) return (i <= j) ? 0 : INF; 
    if (j - i + 1 < k) return INF;

    int &res = dp[i][j][k];
    if (res != -1) return res;

    res = INF;

    res = min(solve(i, j - 1, k), solve(i + 1, j, k));
    res = min(res, (S[i] != S[j]) + solve(i + 1, j - 1, k - 1 - (i != j)));

    return res;
}

int main() {
    cin >> N >> K;
    cin >> S;

    dp.assign(N, vector<vector<int>>(N, vector<int>(K + 1, -1)));

    cout << solve(0, N - 1, K) << "\n";
    return 0;
}
