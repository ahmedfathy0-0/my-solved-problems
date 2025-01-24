#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Directions for neighbors (up, down, left, right)
vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

pair<int, int> minDistractions(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    queue<pair<int, int>> q;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 2) {
                q.push({i, j});
            }
        }
    }

    int distractions = 0;
    int passingStudents = 0;

    while (!q.empty()) {
        int size = q.size();
        bool spread = false;

        for (int i = 0; i < size; i++) {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                    spread = true;
                }
            }
        }

        if (spread) {
            distractions++;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 2) {
                passingStudents++;
            }
        }
    }

    return {distractions, passingStudents};
}

int main() {
    vector<vector<int>> grid = {
        {2, 1, 0, 2, 1},
        {0, 0, 1, 1, 1},
        {1, 0, 0, 2, 1}
    };

    auto [distractions, passingStudents] = minDistractions(grid);
    cout << "MinDistractions = " << distractions << ", PassingStuds = " << passingStudents << endl;

    return 0;
}


FUNCTION minDistractions(grid):
    rows = number of rows in grid
    cols = number of columns in grid
    queue = empty queue
    passingStudents = 0

    // Initialize the queue with all students who know the answer (value = 2)
    FOR i FROM 0 TO rows - 1:
        FOR j FROM 0 TO cols - 1:
            IF grid[i][j] == 2:
                queue.push((i, j))
                passingStudents = passingStudents + 1 // Count already passing students

    distractions = 0

    // Directions for neighbors (up, down, left, right)
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

    // Perform BFS to spread the answer
    WHILE queue is not empty:
        size = size of queue
        spread = false

        FOR i FROM 0 TO size - 1:
            (x, y) = queue.front()
            queue.pop()

            // Spread to neighbors
            FOR each (dx, dy) IN directions:
                nx = x + dx
                ny = y + dy
                IF nx >= 0 AND nx < rows AND ny >= 0 AND ny < cols AND grid[nx][ny] == 1:
                    grid[nx][ny] = 2
                    queue.push((nx, ny))
                    spread = true
                    passingStudents = passingStudents + 1 // Count newly passing students

        IF spread:
            distractions = distractions + 1

    RETURN (distractions, passingStudents)
