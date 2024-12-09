#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;

    vector<pair<int, int>> flowers(n);
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        flowers[i] = make_pair(x, y);
    }

    int max_dist = 0;
    for(int i = 0; i < n; i++) {
        int dist1 = pow((flowers[i].first - x1), 2) + pow((flowers[i].second - y1), 2);
        int dist2 = pow((flowers[i].first - x2), 2) + pow((flowers[i].second - y2), 2);
        max_dist = max(max_dist, min(dist1, dist2));
    }

    cout << max_dist << endl;

    return 0;
}