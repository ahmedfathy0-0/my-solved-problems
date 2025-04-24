#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Rectangle
{
    int x1, y1, h, w;
};

int calcshapePerimeter(vector<Rectangle> &rectangles)
{
    int n = rectangles.size();
    sort(rectangles.begin(), rectangles.end(), [](const Rectangle &a, const Rectangle &b) {
        if (a.x1 == b.x1)
        {
            return a.y1 < b.y1;
        }
        return a.x1 < b.x1;
    });
    int totalPerimeter = 0;
    for (int i = 1; i < n; i++)
    {
        if (rectangles[i].x1 < rectangles[i - 1].x1 + rectangles[i - 1].w && rectangles[i].y1 < rectangles[i - 1].y1 + rectangles[i - 1].h)
        {
            int x1 = max(rectangles[i].x1, rectangles[i - 1].x1);
            int y1 = max(rectangles[i].y1, rectangles[i - 1].y1);
            int x2 = min(rectangles[i].x1 + rectangles[i].w, rectangles[i - 1].x1 + rectangles[i - 1].w);
            int y2 = min(rectangles[i].y1 + rectangles[i].h, rectangles[i - 1].y1 + rectangles[i - 1].h);
            totalPerimeter -= 2 * (x2 - x1 + y2 - y1);
        }
    }
    for (int i = 0; i < n; i++)
    {
        totalPerimeter += 2 * (rectangles[i].w + rectangles[i].h);
    }
    return totalPerimeter;

}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<Rectangle> rectangles(n);
        int w, h;
        cin >> w;
        h = w;
        cin >> rectangles[0].x1 >> rectangles[0].y1;
        rectangles[0].h = h;
        rectangles[0].w = w;
        for(int i=1;i<n;i++)
        {
            int x,y;
            cin >> x >> y;
            rectangles[i].x1 =x+ rectangles[i-1].x1;
            rectangles[i].y1 =y+ rectangles[i-1].y1;
            rectangles[i].h = rectangles[i-1].h;
            rectangles[i].w = rectangles[i-1].w;
        }
        cout << calcshapePerimeter(rectangles) << endl;
    }
}