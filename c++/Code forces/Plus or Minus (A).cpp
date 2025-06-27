#include <iostream>
using namespace std;

#define ll long long

ll n;
ll a[20];
char op[20];
ll minchanges;

void calc (ll index, ll sum, ll changeCount = 0) {
    if (index == n) {
        if (sum == 0) {
            if (minchanges == -1) minchanges = changeCount;
            else minchanges = min(minchanges, changeCount);
        }
        return;
    }

    // Use '+' for this element
    if (op[index - 1] == '+')
        calc(index + 1, sum + a[index], changeCount);
    else
        calc(index + 1, sum + a[index], changeCount + 1);

    // Use '-' for this element
    if (op[index - 1] == '-')
        calc(index + 1, sum - a[index], changeCount);
    else
        calc(index + 1, sum - a[index], changeCount + 1);
}

int main() {
    cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        if (i != n - 1)
            cin >> op[i];
    }

    minchanges = -1;
    calc(1, a[0]); // start from second term, sum initialized with first number

    cout << minchanges << endl;
    return 0;
}
