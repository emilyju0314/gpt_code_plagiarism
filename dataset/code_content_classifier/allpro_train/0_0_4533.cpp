#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, m, x, y, a, b;
    cin >> n >> m >> x >> y >> a >> b;

    int x1, y1, x2, y2;

    // Calculate the size of the sub-rectangle based on the length-width ratio
    int dx = a, dy = b;
    if (a > n - x) dx = n - x;
    if (b > m - y) dy = m - y;

    // Calculate the center of the rectangle
    x1 = max(0, x - dx);
    y1 = max(0, y - dy);
    x2 = min(n, x + dx);
    y2 = min(m, y + dy);

    // Adjust the rectangle to be closest to the point (x, y)
    int cx = (x1 + x2) / 2, cy = (y1 + y2) / 2;
    if (abs(x - cx) < abs(x - cx + 1)) x2 = cx;
    else x1 = cx + 1;
    if (abs(y - cy) < abs(y - cy + 1)) y2 = cy;
    else y1 = cy + 1;

    cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;

    return 0;
}