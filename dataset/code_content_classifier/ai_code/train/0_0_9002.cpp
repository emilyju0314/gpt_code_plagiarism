#include <iostream>
#include <vector>

using namespace std;

double calculateArea(vector<pair<int, int>>& points) {
    double area = 0.0;
    for (int i = 0; i < points.size(); i++) {
        int j = (i + 1) % points.size();
        area += points[i].first * points[j].second - points[j].first * points[i].second;
    }
    return abs(area) / 2.0;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }

    double area = calculateArea(points);
    cout << area << endl;

    return 0;
}