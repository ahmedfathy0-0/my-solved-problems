#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        int sub = 0;
        for(int i =1; i*i <= n; i++) {
            if(i * i <= n){
                sub += n-1;
            }
        }
        cout << n*n - sub << "\n";
    }

    return 0;
}
