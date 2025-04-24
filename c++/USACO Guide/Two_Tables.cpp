#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct rectangle
{
    int x1, y1, x2, y2;
};

pair<int, int> intersection(rectangle a, rectangle b)
{
    int x1 = max(a.x1, b.x1);
    int y1 = max(a.y1, b.y1);
    int x2 = min(a.x2, b.x2);
    int y2 = min(a.y2, b.y2);
    return {x2 - x1, y2 - y1};
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int W, H;
        cin >> W >> H;

        rectangle a;
        cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;

        int w1, h1;
        cin >> w1 >> h1;

        if (w1 > W || h1 > H || (a.x2 - a.x1 + w1 > W && a.y2 - a.y1 + h1 > H))
        {
            cout << -1 << endl;
            continue;
        }

        double min_distance = 1e9;

        if (w1 <= W)
        {
            if (a.x1 >= w1)
                min_distance = min(min_distance, (double)(a.x1 - w1));
            if (a.x2 <= W - w1)
                min_distance = min(min_distance, (double)(w1 - (W - a.x2)));
        }
        if (h1 <= H)
        {
            if (a.y1 >= h1)
                min_distance = min(min_distance, (double)(a.y1 - h1));
            if (a.y2 <= H - h1)
                min_distance = min(min_distance, (double)(h1 - (H - a.y2)));
        }

        cout << (min_distance < 1e9 ? max(0.0, min_distance) : 0.0) << endl;
    }

    return 0;
}
