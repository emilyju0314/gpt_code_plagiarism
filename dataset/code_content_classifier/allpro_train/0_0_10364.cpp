#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> graph;
vector<int> distances;
vector<int> max_happiness;

void dfs(int node, int parent, int current_dist, int current_happiness) {
    distances[node] = current_dist;
    max_happiness[node] = max(current_happiness, 0);

    for (auto neighbor : graph[node]) {
        if (neighbor.first != parent) {
            int new_dist = current_dist + neighbor.second;
            int new_happiness = current_happiness + neighbor.second;
            dfs(neighbor.first, node, new_dist, new_happiness);
            max_happiness[node] = max(max_happiness[node], max_happiness[neighbor.first]);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    graph.resize(n+1);
    distances.assign(n+1, 0);
    max_happiness.assign(n+1, 0);

    for (int i = 1; i < n; i++) {
        int L;
        cin >> L;
        graph[i].push_back({i+1, L});
        graph[i+1].push_back({i, L});
    }

    for (int i = 0; i < m; i++) {
        int A, H;
        cin >> A >> H;

        dfs(A, 0, 0, H);

        long long answer = 0;
        for (int j = 1; j <= n; j++) {
            if (distances[j] <= distances[A] && max_happiness[j] > 0) {
                answer += (long long)(2 * distances[A] - distances[j] + 1) * max_happiness[j] / 2;
                answer -= max(0, (long long)distances[j] - 1) * max_happiness[j];
            }
        }

        cout << answer << endl;
    }

    return 0;
}