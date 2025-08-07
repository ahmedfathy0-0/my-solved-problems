#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9+7;

int n;
vector<int> value;
vector<vector<int>> adj;
vector<bool> isPrime;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

void sieve(int maxVal) {
    isPrime.assign(maxVal+1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i=2; i*i<=maxVal; i++)
        if (isPrime[i])
            for (int j=i*i; j<=maxVal; j+=i)
                isPrime[j] = false;
}

vector<unordered_map<int,ll>> dp;
vector<ll> result;

void dfs(int u, int parent) {
    dp[u][value[u]] = 1;

    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs(v, u);

        unordered_map<int,ll> newDp = dp[u];

        for (auto [g1, cnt1] : dp[u]) {
            for (auto [g2, cnt2] : dp[v]) {
                int g = gcd(g1, g2);
                newDp[g] = (newDp[g] + (cnt1 * cnt2) % MOD) % MOD;
            }
        }

        for (auto [g2, cnt2] : dp[v])
            newDp[g2] = (newDp[g2] + cnt2) % MOD;

        dp[u] = move(newDp);
    }

    ll sum = 0;
    for (auto [g, cnt] : dp[u])
        if (isPrime[g]) sum = (sum + cnt) % MOD;

    result[u] = sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    value.resize(n+1);
    adj.assign(n+1, {});
    for (int i=1; i<=n; i++) cin >> value[i];

    for (int i=0; i<n-1; i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    sieve(1'000'000);
    dp.assign(n+1, {});
    result.assign(n+1, 0);

    dfs(1, -1);

    for (int i=1; i<=n; i++)
        cout << result[i] << " ";
    cout << "\n";
}
