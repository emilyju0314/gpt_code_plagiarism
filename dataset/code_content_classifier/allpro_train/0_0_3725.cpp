#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

double calcDistance(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> bases(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        bases[i] = make_pair(x, y);
    }

    double minSumDist = 1e9; // Initialize with a large value
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j) {
                vector<double> distances;
                for (int k = 0; k < N; k++) {
                    distances.push_back(calcDistance(bases[i].first, bases[i].second, bases[k].first, bases[k].second));
                }
                sort(distances.begin(), distances.end());
                minSumDist = min(minSumDist, distances[K-1]);
            }
        }
    }

    cout << fixed;
    cout.precision(5);
    cout << minSumDist << endl;

    return 0;
}