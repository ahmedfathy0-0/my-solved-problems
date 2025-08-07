#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        ll mx = 0;
        ll x = n - k;
        if (x % 3 == 0) {
            mx =  x / 3 + k;
        } 
        else if (x % 2 == 0) {
            mx = x / 2 + k;
        } 
        else {
            mx = x + k;
        }

        for (ll i = 0; i <= min(5LL, k); i++) {
            ll x = n - i;
            if (x % 3 == 0) {
                mx = max(mx, x / 3 + i);
            } 
            else if (x % 2 == 0) {
                mx = max(mx, x / 2 + i);
            } 
            else {
                mx = max(mx, x + i);
            }
        }

        cout << mx << "\n";
    }
    return 0;
}
