#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> points;

    for(int i = 0; i < n; i++) {
        int x, y;
        cout << "0 0" << endl;
        cin >> x >> y;
        points.push_back({x, y});
    }

    int x1, y1, x2, y2;
    int minX = points[0].first, maxX = points[0].first;
    int minY = points[0].second, maxY = points[0].second;

    for(auto point : points) {
        minX = min(minX, point.first);
        maxX = max(maxX, point.first);
        minY = min(minY, point.second);
        maxY = max(maxY, point.second);
    }

    x1 = minX;
    y1 = minY;
    x2 = maxX;
    y2 = maxY;

    cout << x1 << " " << y1 << endl;
    cout << x2 << " " << y2 << endl;

    return 0;
}