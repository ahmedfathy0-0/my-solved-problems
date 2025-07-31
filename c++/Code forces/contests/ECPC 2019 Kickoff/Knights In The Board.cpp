#include <bits/stdc++.h>
using namespace std;

const int dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
const int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};

vector<vector<int>> adj;
vector<int> matchR;

bool dfs(int u, vector<int> &vis) {
    for (int v : adj[u]) {
        if (vis[v]) continue;
        vis[v] = 1;
        if (matchR[v] == -1 || dfs(matchR[v], vis)) {
            matchR[v] = u;
            return true;
        }
    }
    return false;
}

int minimumKnightsToRemove(int N, int K, vector<pair<int, int>> &knights) {
    vector<vector<int>> board(N + 1, vector<int>(N + 1, -1));
    for (int i = 0; i < K; i++) {
        board[knights[i].first][knights[i].second] = i;
    }

    adj.assign(K, {});
    vector<int> color(K, -1);

    for (int i = 0; i < K; i++) {
        auto [r, c] = knights[i];
        int col = (r + c) % 2;
        color[i] = col;

        if (col == 0) {
            for (int m = 0; m < 8; m++) {
                int nr = r + dx[m], nc = c + dy[m];
                if (nr >= 1 && nr <= N && nc >= 1 && nc <= N && board[nr][nc] != -1) {
                    adj[i].push_back(board[nr][nc]);
                }
            }
        }
    }

    matchR.assign(K, -1);
    int maxMatch = 0;

    for (int u = 0; u < K; u++) {
        if (color[u] == 0) { 
            vector<int> vis(K, 0);
            if (dfs(u, vis)) maxMatch++;
        }
    }

    return maxMatch;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> knights(K);
    for (int i = 0; i < K; i++) {
        cin >> knights[i].first >> knights[i].second;
    }

    cout << minimumKnightsToRemove(N, K, knights) << "\n";

    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to, rev, cap;
};

struct Dinic {
    int n;
    vector<vector<Edge>> g;
    vector<int> level, it;

    Dinic(int n): n(n), g(n), level(n), it(n) {}

    void addEdge(int u, int v, int cap) {
        g[u].push_back({v, (int)g[v].size(), cap});
        g[v].push_back({u, (int)g[u].size() - 1, 0});
    }

    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        level[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto &e : g[u]) {
                if (e.cap > 0 && level[e.to] == -1) {
                    level[e.to] = level[u] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[t] != -1;
    }

    int dfs(int u, int t, int f) {
        if (u == t) return f;
        for (int &i = it[u]; i < g[u].size(); i++) {
            Edge &e = g[u][i];
            if (e.cap > 0 && level[e.to] == level[u] + 1) {
                int ret = dfs(e.to, t, min(f, e.cap));
                if (ret > 0) {
                    e.cap -= ret;
                    g[e.to][e.rev].cap += ret;
                    return ret;
                }
            }
        }
        return 0;
    }

    int maxFlow(int s, int t) {
        int flow = 0, f;
        while (bfs(s, t)) {
            fill(it.begin(), it.end(), 0);
            while ((f = dfs(s, t, INT_MAX)) > 0) {
                flow += f;
            }
        }
        return flow;
    }
};

const int dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
const int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> knights(K);
    vector<vector<int>> board(N + 1, vector<int>(N + 1, -1));

    for (int i = 0; i < K; i++) {
        cin >> knights[i].first >> knights[i].second;
        board[knights[i].first][knights[i].second] = i;
    }

    int source = K, sink = K + 1;
    Dinic dinic(K + 2);

    for (int i = 0; i < K; i++) {
        int r = knights[i].first, c = knights[i].second;
        if ((r + c) % 2 == 0) {
            dinic.addEdge(source, i, 1);
            for (int m = 0; m < 8; m++) {
                int nr = r + dx[m], nc = c + dy[m];
                if (nr >= 1 && nr <= N && nc >= 1 && nc <= N && board[nr][nc] != -1) {
                    dinic.addEdge(i, board[nr][nc], 1);
                }
            }
        } else {
            dinic.addEdge(i, sink, 1);
        }
    }

    cout << dinic.maxFlow(source, sink) << "\n";
    return 0;
}

*/