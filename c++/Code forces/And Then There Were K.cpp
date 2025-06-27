#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int k = (1 << (31 - __builtin_clz(n))) - 1;
        cout << k << '\n';
    }
    return 0;
}
