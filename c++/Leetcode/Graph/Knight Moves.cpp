#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <climits>
using namespace std;

vector<vector<int>> chessKnightsDirections = {
    {-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};

int bfs(int x1, int y1, int x2, int y2)
{
    vector<vector<bool>> visited(8, vector<bool>(8, false));
    queue<pair<pair<int, int>, int>> q;
    q.push({{x1, y1}, 0});
    visited[x1][y1] = true;

    while (!q.empty())
    {
        auto [pos, moves] = q.front();
        auto [x, y] = pos;
        q.pop();

        if (x == x2 && y == y2)
        {
            return moves;
        }

        for (auto dir : chessKnightsDirections)
        {
            int nx = x + dir[0];
            int ny = y + dir[1];
            if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && !visited[nx][ny])
            {
                visited[nx][ny] = true;
                q.push({{nx, ny}, moves + 1});
            }
        }
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;

    string start, end;
    while (t--)
    {
        cin >> start >> end;

        int x1 = start[0] - 'a';
        int y1 = start[1] - '1';
        int x2 = end[0] - 'a';
        int y2 = end[1] - '1';

        cout << "To get from " << start << " to " << end << " takes "
             << bfs(x1, y1, x2, y2) << " knight moves." << endl;
    }

    return 0;
}
