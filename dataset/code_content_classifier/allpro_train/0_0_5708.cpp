#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N, M, L;
    while (cin >> N >> M >> L) {
        vector<vector<pair<int, int>>> adjList(N+1);
        for (int i = 0; i < M; i++) {
            int Ai, Bi, Di;
            cin >> Ai >> Bi >> Di;
            adjList[Ai].push_back({Bi, Di});
            adjList[Bi].push_back({Ai, Di});
        }

        vector<int> Pi(N+1), Ki(N+1);
        for (int i = 1; i <= N; i++) {
            cin >> Pi[i];
        }
        for (int i = 1; i <= N; i++) {
            cin >> Ki[i];
        }

        vector<vector<int>> dist(N+1, vector<int>(N+1, -1));
        for (int i = 1; i <= N; i++) {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            vector<int> d(N+1, -1);
            d[i] = 0;
            pq.push({0, i});
            while (!pq.empty()) {
                int u = pq.top().second;
                int dist_u = pq.top().first;
                pq.pop();
                if (dist_u > L) break;
                for (auto neighbor : adjList[u]) {
                    int v = neighbor.first;
                    int weight = neighbor.second;
                    if (d[v] == -1 || dist_u + weight < d[v]) {
                        d[v] = dist_u + weight;
                        pq.push({d[v], v});
                    }
                }
            }
            for (int j = 1; j <= N; j++) {
                dist[i][j] = d[j];
            }
        }

        int totalSurvivors = 0;
        for (int i = 1; i <= N; i++) {
            if (dist[i][i] <= Pi[i]) totalSurvivors += min(Pi[i], Ki[i]);
        }
        cout << totalSurvivors << endl;
    }

    return 0;
}