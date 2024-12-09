#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

double distance(pair<int, int> p1, pair<int, int> p2) {
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i].first >> points[i].second;
    }

    sort(points.begin(), points.end());

    double minPath = 0;
    for (int i = 0; i < N-1; i++) {
        minPath += distance(points[i], points[i+1]);
    }

    minPath += min(distance(points[0], points[K-1]), distance(points[N-1], points[K-1]));

    cout << fixed;
    cout.precision(6);
    cout << minPath << endl;

    return 0;
}