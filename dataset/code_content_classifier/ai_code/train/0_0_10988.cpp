#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double calculateMinimumPerimeter(vector<pair<int, int>>& points) {
    double minPerimeter = 0;
    for (int i = 0; i < points.size(); i++) {
        pair<int, int> p1 = points[i];
        pair<int, int> p2 = points[(i + 1) % points.size()];
        minPerimeter += sqrt(pow(p2.first - p1.first, 2) + pow(p2.second - p1.second, 2));
    }
    return minPerimeter;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> points;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.push_back(make_pair(x, y));
    }

    double minPerimeter = calculateMinimumPerimeter(points);
    cout << minPerimeter << endl;

    return 0;
}