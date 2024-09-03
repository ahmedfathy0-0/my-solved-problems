#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long calcprice(vector<int>& a, int k) {
    vector<long long> costs(a.size());
    for (int i = 0; i < a.size(); ++i) {
        costs[i] = a[i] + (long long)(i + 1) * k;
    }
    
    sort(costs.begin(), costs.end());
    
    long long total_cost = 0;
    for (int i = 0; i < k; ++i) {
        total_cost += costs[i];
    }
    
    return total_cost;
}

int main() {
    int n;
    long long S;
    cin >> n >> S;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int left = 0, right = n, max_k = 0;
    long long min_cost = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        long long cost = calcprice(a, mid);
        if (cost <= S) {
            max_k = mid;
            min_cost = cost;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << max_k << " " << min_cost << endl;
    return 0;
}