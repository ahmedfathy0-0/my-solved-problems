#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

max_heapify(vector<int>& a, int i, int n) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;
    if (l < n && a[l] > a[largest]) {
        largest = l;
    }
    if (r < n && a[r] > a[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(a[i], a[largest]);
        max_heapify(a, largest, n);
    }
}
heapsort(vector<int>& a) {
    int n = a.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        max_heapify(a, i, n);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        max_heapify(a, 0, i);
    }
}



int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    heapsort(a);
    int sum = 0;
    for (int i = 0; i < m; i++) {
        if (a[i] >= 0) {
            break;
        }
        sum += a[i];
    }
    cout << -sum << endl;
    return 0;
}