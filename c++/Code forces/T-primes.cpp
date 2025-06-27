#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
#define ll long long
const int MAX = 1e6 + 1;

vector<int> linear_sieve(int n) {
    vector<int> primes;
    vector<int> spf(n + 1);

    for (int i = 2; i <= n; ++i) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > spf[i] || i * p > n) break;
            spf[i * p] = p;
        }
    }

    return primes;
}

int main() {
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> primes = linear_sieve(MAX);

    unordered_set<ll> t_primes;
    for (int p : primes) {
        t_primes.insert((ll)p * p);
    }

    for (ll x : arr) {
        if (t_primes.count(x)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
