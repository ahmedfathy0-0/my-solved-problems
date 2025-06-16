#include <iostream>
using namespace std;

string ask(int x) {
    cout << x << endl;
    cout.flush();
    string res;
    cin >> res;
    return res;
}

int main() {
    int l = 1, r = 1000000;

    while (l < r) {
        int mid = (l + r + 1) / 2; // use upper mid
        string res = ask(mid);

        if (res == "<") {
            r = mid - 1;
        } else {
            l = mid;
        }
    }

    cout << "! " << l << endl;
    cout.flush();
    return 0;
}
