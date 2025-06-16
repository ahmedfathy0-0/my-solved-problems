#include <iostream>
#include <vector>
using namespace std;

int ask(int i, int j) {
    cout << "? " << i << " " << j << endl;
    cout.flush();
    int sum;
    cin >> sum;
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);

    int s12 = ask(1, 2);
    int s13 = ask(1, 3);
    int s23 = ask(2, 3);

    a[1] = (s12 + s13 - s23) / 2;
    a[2] = s12 - a[1];
    a[3] = s13 - a[1];

    for (int i = 4; i <= n; i++) {
        int si = ask(1, i);
        a[i] = si - a[1];
    }

    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    cout.flush();

    return 0;
}
