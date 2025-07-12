#include <iostream>
#include <vector>
using namespace std;

vector<bool> visited;
vector<vector<int>> adjacencyList;
vector<bool> cats;
int ans = 0;
int n, m;

void dfs(int node, int consecutiveCats) {
    visited[node] = true;
    
    // Update consecutive cat counter
    if(cats[node]) {
        consecutiveCats++;
    } else {
        consecutiveCats = 0;
    }

    // Stop DFS if limit exceeded
    if(consecutiveCats > m) return;

    bool isLeaf = true;

    for(int neighbor : adjacencyList[node]) {
        if(!visited[neighbor]) {
            isLeaf = false;
            dfs(neighbor, consecutiveCats);
        }
    }

    if(isLeaf) {
        ans++;
    }
}

int main() {
    cin >> n >> m;

    cats.resize(n);
    for(int i = 0; i < n; i++) {
        int cat;
        cin >> cat;
        cats[i] = (cat == 1);
    }

    adjacencyList.resize(n);
    visited.resize(n, false);

    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }

    dfs(0, 0);
    cout << ans << endl;
    return 0;
}
