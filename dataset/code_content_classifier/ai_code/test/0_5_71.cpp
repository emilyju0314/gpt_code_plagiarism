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

    double minPath = 0;
    for (int i = 0; i < N; i++) {
        if (i == K - 1) continue;
        
        minPath += distance(points[i], points[K-1]);
    }

    vector<pair<double, int>> dist;
    for (int i = 0; i < N; i++) {
        if (i == K - 1) continue;
        
        dist.push_back({distance(points[i], points[K-1]), i+1});
    }

    sort(dist.begin(), dist.end());

    for (int i = 0; i < N-2; i++) {
        minPath += dist[i].first;
    }

    cout << minPath << endl;

    return 0;
}