#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t; // Number of test sets

    for (int i = 0; i < t; i++) {
        int n, m, x1, y1, x2, y2;
        cin >> n >> m >> x1 >> y1 >> x2 >> y2;

        // Calculate the distance between the lasers in rows and columns
        int dx = abs(x2 - x1);
        int dy = abs(y2 - y1);

        // Calculate the cells that can't be melted by the lasers
        long long cells_cant_melt = (long long)dx * (m - dy) + (long long)dy * (n - dx) - dx * dy;

        cout << cells_cant_melt << endl;
    }

    return 0;
}