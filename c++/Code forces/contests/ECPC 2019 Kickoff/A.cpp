#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

const int SQ = 175;

struct Query {
    int l, r, q_idx, blk_idx;
    bool operator<(const Query &other) const {
        if (blk_idx != other.blk_idx) return blk_idx < other.blk_idx;
        return (blk_idx & 1) ? (r > other.r) : (r < other.r);
    }
    Query(int _l = 0, int _r = 0, int _q_idx = 0)
        : l(_l), r(_r), q_idx(_q_idx) {
        blk_idx = _l / SQ;
    }
};

Query qu[100000];
int res[100000];
vector<int> cnt(1000001, 0);

multiset<int> values;      
multiset<int> differences;
int duplicateCount = 0; 

void addValue(int x) {
    auto it = values.insert(x);
    auto prev = it, next = it;

    if (it != values.begin()) {
        --prev;
        differences.insert(*it - *prev);
    }

    next++;
    if (next != values.end()) {
        differences.insert(*next - *it);
        if (it != values.begin()) {
            auto itDiff = differences.find(*next - *prev);
            if (itDiff != differences.end()) differences.erase(itDiff);
        }
    }
}

void removeValue(int x) {
    auto it = values.find(x);
    if (it == values.end()) return;

    auto prev = it, next = it;
    bool hasPrev = (it != values.begin());
    if (hasPrev) --prev;
    ++next;

    if (hasPrev && next != values.end()) {
        differences.insert(*next - *prev);
    }

    if (hasPrev) {
        auto itDiff = differences.find(*it - *prev);
        if (itDiff != differences.end()) differences.erase(itDiff);
    }
    if (next != values.end()) {
        auto itDiff = differences.find(*next - *it);
        if (itDiff != differences.end()) differences.erase(itDiff);
    }

    values.erase(it);
}

void add(int idx, const vector<int> &a) {
    int val = a[idx];
    cnt[val]++;
    if (cnt[val] == 2) duplicateCount++; 
    if (cnt[val] == 1) addValue(val);
}

void remove(int idx, const vector<int> &a) {
    int val = a[idx];
    if (cnt[val] == 2) duplicateCount--; 
    cnt[val]--;
    if (cnt[val] == 0) removeValue(val);
}

int getAnswer() {
    if (duplicateCount > 0) return 0;
    if (!differences.empty()) return *differences.begin();
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        qu[i] = Query(l, r, i);
    }

    sort(qu, qu + q);

    int currL = 0, currR = -1;
    for (int i = 0; i < q; i++) {
        int L = qu[i].l;
        int R = qu[i].r;

        while (currL > L) add(--currL, a);
        while (currR < R) add(++currR, a);
        while (currL < L) remove(currL++, a);
        while (currR > R) remove(currR--, a);

        res[qu[i].q_idx] = getAnswer();
    }

    for (int i = 0; i < q; i++) cout << res[i] << "\n";

    return 0;
}
