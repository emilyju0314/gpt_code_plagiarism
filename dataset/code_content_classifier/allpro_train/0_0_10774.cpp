#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int max_dist = 0;

    for (int i = 0; i < n; i++) {
        int xi, yi, li;
        cin >> xi >> yi >> li;
        
        for (int j = 0; j < m; j++) {
            int xj, yj, lj;
            cin >> xj >> yj >> lj;

            int center_x = xi;
            int center_y = yj;

            int dist_x = min(abs(center_x - xi), abs(center_x - (xi + li)));
            int dist_y = min(abs(center_y - yj), abs(center_y - (yj + lj)));

            int dist = min(dist_x, dist_y);

            max_dist = max(max_dist, dist);
        }
    }

    cout << max_dist << endl;

    return 0;
}