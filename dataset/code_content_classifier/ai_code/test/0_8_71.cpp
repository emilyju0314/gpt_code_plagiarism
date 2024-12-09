#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <iomanip>

using namespace std;

const int MAXN = 2e5 + 5;
const double INF = 1e9;

vector<pair<int, int>> points;
vector<bool> visited(MAXN, false);
vector<double> dist(MAXN, INF);

double calcDistance(pair<int, int> a, pair<int, int> b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

double primMST(int start) {
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;

    double totalLen = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        totalLen += dist[u];

        for (int v = 0; v < points.size(); v++) {
            double len = calcDistance(points[u], points[v]);
            if (!visited[v] && dist[v] > len) {
                dist[v] = len;
                pq.push({dist[v], v});
            }
        }
    }

    return totalLen;
}

int main() {
    int N, K;
    cin >> N >> K;

    points.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i].first >> points[i].second;
    }

    double minPath = primMST(K - 1);

    cout << fixed << setprecision(6) << minPath << endl;

    return 0;
}