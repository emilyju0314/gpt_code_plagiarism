#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    int n, px, py;
    cin >> n >> px >> py;

    vector<pair<int, int>> vertices(n);
    for (int i = 0; i < n; i++) {
        cin >> vertices[i].first >> vertices[i].second;
    }

    double max_dist = 0, min_dist = 1e9;
    for (int i = 0; i < n; i++) {
        double dist = distance(px, py, vertices[i].first, vertices[i].second);
        max_dist = max(max_dist, dist);
        min_dist = min(min_dist, dist);
    }

    double cleared_area = M_PI * pow(max_dist, 2) - M_PI* pow(min_dist, 2);

    cout << cleared_area << endl;

    return 0;
}