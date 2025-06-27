#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    string n;
    cin >> n;

    int length = n.size();
    int index = 0;

    for (int i = 0; i < length; ++i) {
        index <<= 1;
        if (n[i] == '7')
            index |= 1;
    }

    int answer = (1 << length) - 2 + index + 1;
    cout << answer << '\n';

    return 0;
}
