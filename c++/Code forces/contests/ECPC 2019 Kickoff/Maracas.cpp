#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll a, b;
    cin >> n;

    vector<ll> v(n), odd;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if (v[i] & 1) odd.emplace_back(i);
    }
    cin >> a >> b;

    if (odd.size() & 1) {
        cout << -1;
        return 0;
    }

    if (odd.empty()) {
        cout << 0;
        return 0;
    }

    ll ans = LLONG_MAX;
    ll tmp = 0;
    int m = odd.size();

    // 1. Linear pairing (no wrap)
    for (int i = 0; i + 1 < m; i += 2)
        tmp += (odd[i + 1] - odd[i]);
    ans = min(ans, tmp);

    // 2. Circular pairing (wrap last with first)
    tmp = (n - odd.back() + odd[0]); 
    for (int i = 1; i + 1 < m; i += 2)
        tmp += (odd[i + 1] - odd[i]);
    ans = min(ans, tmp);

    cout << ans * min(a, b);
    return 0;
}
