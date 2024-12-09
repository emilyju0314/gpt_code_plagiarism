#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int n, a;
    cin >> n >> a;

    vector<pair<int, int>> outposts(n);

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        outposts[i] = make_pair(x, y);
    }

    double min_diff = 1e9;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double x1 = outposts[i].first;
            double y1 = outposts[i].second;
            double x2 = outposts[j].first;
            double y2 = outposts[j].second;

            double dx = x2 - x1;
            double dy = y2 - y1;

            double dist = sqrt(dx * dx + dy * dy);
            double height = fabs((x1 - a) * dy - (y1) * dx + a*y1) / dist;

            min_diff = min(min_diff, height);
        }
    }

    cout << min_diff << endl;

    return 0;
}