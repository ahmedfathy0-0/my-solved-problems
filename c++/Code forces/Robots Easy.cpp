#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>
using namespace std;

// Grid definition
vector<vector<int>> grid = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, -1, -1, 0, 0, 0, 0, 0, 0, -1, -1, 0},
    {0, -1, 1, 0, 0, 0, 0, 0, 0, 1, -1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int dr[4] = {-1, 1, 0, 0}; // U, D, L, R
int dc[4] = {0, 0, -1, 1};
char moveChar[4] = {'U', 'D', 'L', 'R'};

struct Node {
    int r, c;
    string path;
};

bool isValid(int r, int c, vector<vector<bool>>& visited) {
    return r >= 0 && r < 12 && c >= 0 && c < 12 && !visited[r][c] && grid[r][c] != -1;
}

void bfs(int sr, int sc) {
    queue<Node> q;
    vector<vector<bool>> visited(12, vector<bool>(12, false));
    
    q.push({sr, sc, ""});
    visited[sr][sc] = true;

    while (!q.empty()) {
        Node cur = q.front(); q.pop();

        // Found target cell
        if (grid[cur.r][cur.c] == 1) {
            cout << cur.path.length() << "\n" << cur.path << "\n";
            return;
        }

        for (int i = 0; i < 4; ++i) {
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];

            if (isValid(nr, nc, visited)) {
                visited[nr][nc] = true;
                q.push({nr, nc, cur.path + moveChar[i]});
            }
        }
    }

    cout << 0 << "\n\n";
}

int main() {
    int L;
    cin >> L;
    while (L--) {
        int r, c;
        cin >> r >> c;
        bfs(r - 1, c - 1);
    }
    return 0;
}
