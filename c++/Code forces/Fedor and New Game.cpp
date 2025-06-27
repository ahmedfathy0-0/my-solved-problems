#include <iostream>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    int armies[m + 1];
    for (int i = 0; i <= m; ++i) {
        cin >> armies[i];
    }

    int fedorsArmy = armies[m];
    int friends = 0;

    for (int i = 0; i < m; ++i) {
        int diff = __builtin_popcount(armies[i] ^ fedorsArmy);
        if (diff <= k)
            friends++;
    }

    cout << friends << '\n';
    return 0;
}
