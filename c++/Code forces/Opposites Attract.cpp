#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long long countOpposites(vector<long long> arr) {
    long long count = 0;
    unordered_map<long long, long long> freq;

    for (long long num : arr) {
        freq[num]++;
    }

    for (long long num = -10; num <= 10; num++) {
        if (num == 0) continue;  
        if (freq[num] > 0 && freq[-num] > 0) {
            count += freq[num] * freq[-num];
            freq[num] = 0;  
            freq[-num] = 0;
        }
    }

    if (freq[0] > 1) {
        count += (freq[0] * (freq[0] - 1)) / 2;
    }

    return count;
}

int main() {
    int n;
    cin >> n;
    vector<long long> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << countOpposites(arr) << endl;
    return 0;
}
