#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

double dist(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double maxNonIntersectingPath(vector<Point>& points) {
    int n = points.size();
    vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0));

    // Calculate the distance between each pair of points
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            dp[i][j] = dist(points[i - 1], points[j - 1]);
        }
    }

    // Use dynamic programming to find the maximum non-intersecting path
    for (int k = 2; k <= n; k++) {
        for (int i = 1; i <= n - k; i++) {
            int j = i + k;
            for (int l = i + 1; l < j; l++) {
                dp[i][j] = max(dp[i][j], dp[i][l] + dp[l][j]);
            }
        }
    }

    return dp[1][n];
}

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    double result = maxNonIntersectingPath(points);
    cout << fixed;
    cout.precision(10);
    cout << result << endl;

    return 0;
}