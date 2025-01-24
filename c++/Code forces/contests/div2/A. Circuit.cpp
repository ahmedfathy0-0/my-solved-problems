#include <iostream>
#include <vector>
using namespace std;

int getmin(vector<int>& v) {
    int ones = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 1) {
            ones++;
        }
    }
    if (ones % 2 == 0) {
        return 0;
    }
    else {
        return 1;
    }
}
int getmax(vector<int>& v) {
    int ones = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 1) {
            ones++;
        }
    }
    if (ones < v.size() / 2) {
        return ones;
    }
    else {
        return v.size() - ones;
    }

}
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> v(2 * n);
        for (int j = 0; j < 2 * n; j++) {
            cin >> v[j];
        }
        int min = getmin(v);
        int max = getmax(v);
        cout << min << " " << max << endl;

    }
}