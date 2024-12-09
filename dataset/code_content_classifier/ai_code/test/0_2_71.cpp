#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double distance(pair<int, int> p1, pair<int, int> p2) {
    return sqrt((p1.first - p2.first)*(p1.first - p2.first) + (p1.second - p2.second)*(p1.second - p2.second));
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i].first >> points[i].second;
    }

    double minDist = 1e9;
    int index = -1;
    for (int i = 0; i < N; i++) {
        if (i != K-1) {
            double dist = distance(points[K-1], points[i]);
            if (dist < minDist) {
                minDist = dist;
                index = i;
            }
        }
    }

    double result = minDist;
    minDist = 1e9;
    for (int i = 0; i < N; i++) {
        if (i != K-1 && i != index) {
            double dist1 = distance(points[index], points[i]);
            double dist2 = distance(points[K-1], points[i]);
            double dist = dist1 + dist2;
            if (dist < minDist) {
                minDist = dist;
            }
        }
    }

    result += minDist;
    cout << result << endl;

    return 0;
}