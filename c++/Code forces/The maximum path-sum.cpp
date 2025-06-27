#include <iostream>
#include <climits>
using namespace std;
#define ll long long

ll ei, ej;
ll matrix[10][10];

ll maxPathSum(int i, int j) {
    if (i > ei || j > ej) return LLONG_MIN;
    if (i == ei && j == ej) return matrix[i][j];

    ll down = maxPathSum(i + 1, j);
    ll right = maxPathSum(i, j + 1);

    return matrix[i][j] + max(down, right);
}

int main() {
    int n, m;
    cin >> n >> m;

    ei = n - 1;
    ej = m - 1;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];

    cout << maxPathSum(0, 0) << endl;

    return 0;
}
