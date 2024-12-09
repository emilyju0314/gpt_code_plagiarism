#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Point {
    int x, y;
};

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);
    for(int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    unordered_map<double, int> slopes;
    int infinite_lines = 0;
    int symmetric_lines = 0;

    for(int i = 0; i < n; i++) {
        slopes.clear();

        for(int j = 0; j < n; j++) {
            if(i == j) continue;

            // Calculate the slope of the line passing through the two points
            double slope;
            if(points[j].x - points[i].x != 0) {
                slope = (double)(points[j].y - points[i].y) / (points[j].x - points[i].x);
            } else {
                slope = numeric_limits<double>::infinity();
            }

            slopes[slope]++;
        }

        for(auto entry : slopes) {
            symmetric_lines = max(symmetric_lines, entry.second);
        }

        infinite_lines = max(infinite_lines, slopes[numeric_limits<double>::infinity()]);
    }

    if(symmetric_lines == 0) {
        cout << -1 << endl;
    } else {
        cout << symmetric_lines + infinite_lines << endl;
    }

    return 0;
}