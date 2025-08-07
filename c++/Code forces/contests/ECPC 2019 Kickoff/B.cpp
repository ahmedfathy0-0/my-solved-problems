#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <limits>
#include <climits>
#include <cmath>
using namespace std;
#define ll long long

const int MAX_A = 1000000; 
vector<int> grundyVal(MAX_A + 1, -1);

int msb(int x) {
    return 1 << (31 - __builtin_clz(x));
}

int MEX(const unordered_set<int>& s) {
    for (int i = 0; ; i++) {
        if (s.find(i) == s.end()) return i;
    }
    return -1; 
}

void precomputeGrundy(int MAX_A = 1000000) {
    grundyVal[0] = 0; // base case
    for (int x = 1; x <= MAX_A; x++) {
        if(grundyVal[x] != -1) continue;
        unordered_set<int> reachable;
        int maxRemove = msb(x);
        for (int k = 1; k < maxRemove; k++) {
            reachable.insert(grundyVal[x - k]);
        }
        // mex calculation
        grundyVal[x] = MEX(reachable);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll ans = 0;
        while (n--) {
            int x;
            cin >> x;
            precomputeGrundy(x); 
            ans ^= grundyVal[x]; 
        }
        if (ans)
            cout << "First\n";
        else
            cout << "Second\n";
    }
    return 0;
}
