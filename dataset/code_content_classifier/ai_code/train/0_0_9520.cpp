#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
    int N;

    while (true) {
        cin >> N;

        if (N == 0) break;

        vector<Point> points(N);
        for (int i = 0; i < N; i++) {
            cin >> points[i].x >> points[i].y;
        }

        vector<vector<double>> dp(N, vector<double>(N, 1e9));
        dp[0][0] = 0;

        for (int i = 0; i < N - 1; i++) {
            for (int j = i; j < N - 1; j++) {
                for (int k = j + 1; k < N; k++) {
                    dp[j + 1][k] = min(dp[j + 1][k], dp[i][j] + distance(points[j], points[k]));
                }
            }
        }

        cout << dp[N-2][N-1] << endl;
    }

    return 0;
}