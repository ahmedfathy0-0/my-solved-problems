#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    sort(a.begin(), a.end());

    if (n == 2) {
        cout << (a[0] == a[1] ? "YES" : "NO") << "\n";
    } 
    else if (n % 2 == 1) {
        int mid = n / 2;
        cout << (a[mid] == a[mid - 1] ? "YES" : "NO") << "\n";
    } 
    else {
        int mid = n / 2 - 1;
        cout << ((a[mid] == a[mid - 1] || a[mid] == a[mid + 1]) ? "YES" : "NO") << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
