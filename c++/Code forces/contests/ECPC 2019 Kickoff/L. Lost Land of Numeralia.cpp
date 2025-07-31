#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1001;
signed main() {
    ll n, q;
    cin >> n >> q;
    while (q--) {
        ll sum, p;
        cin >> sum >> p;
        ll limit = n / p;
        ll res = 0;

        for (int sz = 2; sz <= N; ++sz) {
            ll ss = (sz - 1) * sz / 2;
            ll a = sum / p - ss;
            a = max(1LL, (a + sz - 1) / sz);

            if (p * (ss + a * sz) < sum)
                ++a;

            ll r = (limit - sz + 1);
            if (r <= 0) break;

            res += max(0LL, r - a + 1);
        }
        cout << res << '\n';
    }
}
