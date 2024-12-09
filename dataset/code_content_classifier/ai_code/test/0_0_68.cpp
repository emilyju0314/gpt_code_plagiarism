#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> bubbles(N);
    for (int i = 0; i < N; i++) {
        cin >> bubbles[i].first >> bubbles[i].second;
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int dx, dy, K;
        cin >> dx >> dy >> K;

        double angle = atan2(dy, dx);

        vector<pair<double, int>> angles;
        for (int j = 0; j < N; j++) {
            double bubble_angle = atan2(bubbles[j].second, bubbles[j].first);
            double angle_diff = bubble_angle - angle;
            angles.push_back({angle_diff, j});
        }

        sort(angles.begin(), angles.end());

        cout << angles[N - K].second + 1 << endl;
    }

    return 0;
}