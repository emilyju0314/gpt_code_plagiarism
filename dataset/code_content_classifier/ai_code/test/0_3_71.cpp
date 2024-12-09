#include <bits/stdc++.h>
using namespace std;

double distance(pair<int, int> a, pair<int, int> b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i].first >> points[i].second;
    }

    double ans = 0;
    vector<int> path;
    path.push_back(K-1);
    vector<bool> visited(N, false);
    visited[K-1] = true;

    for (int i = 0; i < N-1; i++) {
        int curr = path.back();
        int next = -1;
        double min_dist = numeric_limits<double>::max();
        for (int j = 0; j < N; j++) {
            if (!visited[j]) {
                double dist = distance(points[curr], points[j]);
                if (dist < min_dist) {
                    min_dist = dist;
                    next = j;
                }
            }
        }
        ans += min_dist;
        visited[next] = true;
        path.push_back(next);
    }

    ans += distance(points[path.back()], points[K-1]);

    cout << fixed << setprecision(6) << ans << endl;

    return 0;
}