#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<int> ans;

void sort_dfs(int u, const vector<int>& a, vector<bool>& vis, int n) {
    if (vis[u])
        return;
    vis[u] = true;
    ans.push_back(a[u]);

    for (int i = 1; i <= n; ++i) {
        if ((a[u] & a[i]) != 0)
            sort_dfs(i, a, vis, n);
    }

    for (int i = 1; i <= n; ++i) {
        if (((a[u] & (~a[i])) & 7) == (a[u] & 7))
            sort_dfs(i, a, vis, n);
    }
}

int main() {
    cin.tie(nullptr);
    freopen("sort.in", "r", stdin);
    int n;
    cin >> n;

    vector<int> original(n + 1), masked(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> original[i];
        masked[i] = original[i] & 7; 
    }

    vector<bool> vis(n + 1, false);
    ans.clear();
    sort_dfs(1, masked, vis, n);

    for (int val : ans)
        cout << val << " ";
    cout << endl;

    return 0;
}
