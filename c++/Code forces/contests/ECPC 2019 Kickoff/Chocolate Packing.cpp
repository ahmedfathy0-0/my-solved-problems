#include <iostream>
#include <vector>
using namespace std;

int main() {
    int L, W, H;
    int l, w, h; 
    cin >> L >> W >> H;
    cin >> l >> w >> h;

    vector<vector<int>> orientations = {
        {l, w, h},
        {l, h, w},
        {w, l, h},
        {w, h, l},
        {h, l, w},
        {h, w, l}
    };

    long long maxBoxes = 0;
    for (auto &box : orientations) {
        long long count = 1LL * (L / box[0]) * (W / box[1]) * (H / box[2]);
        maxBoxes = max(maxBoxes, count);
    }

    cout << maxBoxes << "\n";
    return 0;
}
