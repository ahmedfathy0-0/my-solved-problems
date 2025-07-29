#include <bits/stdc++.h>
using namespace std;

const int N = 12;
vector<vector<int>> grid = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, -1,-1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, -1,-1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, -1,-1, 0, 0, 0, 0, 0, 0, -1,-1, 0},
    {0, -1, 1, 0, 0, 0, 0, 0, 0,  1,-1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

vector<pair<int, int>> dirs = {{-1,0}, {1,0}, {0,1}, {0,-1}};
string dir_chars = "UDRL";

bool is_cross(pair<int, int> p) {
    return grid[p.first][p.second] == 1;
}

uint64_t encode(const vector<pair<int, int>>& robots) {
    uint64_t key = 0;
    for (int i = 0; i < 4; i++) {
        key |= (robots[i].first * 12 + robots[i].second) << (i * 8);
    }
    return key;
}

vector<pair<int,int>> decode(uint64_t state) {
    vector<pair<int,int>> robots(4);
    for (int i = 0; i < 4; i++) {
        int v = (state >> (i * 8)) & 0xFF;
        robots[i] = {v / 12, v % 12};
    }
    return robots;
}

bool all_crossed(const vector<pair<int,int>>& robots) {
    for (auto& r : robots)
        if (!is_cross(r)) return false;
    return true;
}

bool in_bounds(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < N;
}

void solve(vector<pair<int,int>> start) {
    queue<pair<uint64_t, string>> q;
    unordered_set<uint64_t> visited;

    uint64_t init = encode(start);
    q.push({init, ""});
    visited.insert(init);

    while (!q.empty()) {
        auto [state, path] = q.front(); q.pop();
        auto robots = decode(state);

        if (all_crossed(robots)) {
            cout << path.size() << '\n' << path << '\n';
            return;
        }

        if (path.size() >= 1000) continue;

        for (int d = 0; d < 4; d++) {
            auto dir = dirs[d];
            vector<pair<int,int>> next = robots;
            set<pair<int,int>> occupied(robots.begin(), robots.end());

            // simulate movement
            for (int i = 0; i < 4; i++) {
                int nr = robots[i].first + dir.first;
                int nc = robots[i].second + dir.second;

                if (!in_bounds(nr, nc) || grid[nr][nc] == -1) continue;

                pair<int,int> dest = {nr, nc};
                // check if destination is empty or robot is moving
                if (occupied.count(dest)) {
                    // only move if other robot also moving
                    bool other_moving = false;
                    for (int j = 0; j < 4; j++) {
                        if (j == i) continue;
                        if (robots[j] == dest) {
                            int jr = robots[j].first + dir.first;
                            int jc = robots[j].second + dir.second;
                            if (in_bounds(jr,jc) && grid[jr][jc]!=-1)
                                other_moving = true;
                        }
                    }
                    if (!other_moving) continue;
                }
                next[i] = dest;
            }

            uint64_t new_state = encode(next);
            if (visited.count(new_state)) continue;
            visited.insert(new_state);
            q.push({new_state, path + dir_chars[d]});
        }
    }

    // fallback
    cout << 0 << "\n\n";
}

int main() {
    int L;
    cin >> L;

    vector<pair<int,int>> start(4);
    for (int i = 0; i < 4; i++) {
        int r, c;
        cin >> r >> c;
        start[i] = {r - 1, c - 1}; // convert to 0-based index
    }

    solve(start);


    return 0;
}
