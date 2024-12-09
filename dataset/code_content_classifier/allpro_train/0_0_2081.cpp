#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> graph;
vector<int> observations;

bool check(int fish) {
    vector<int> levels(graph.size(), -1);

    for (int i = 0; i < observations.size(); i += 3) {
        int day = observations[i];
        int f = observations[i + 1];
        int p = observations[i + 2];

        queue<pair<int, int>> q;
        q.push({p, 0});

        while (!q.empty()) {
            int node = q.front().first;
            int level = q.front().second;
            q.pop();

            if (level > f) {
                continue;
            }

            if (levels[node] == -1) {
                levels[node] = day;
            } else if (levels[node] != day) {
                return false;
            }

            for (auto neighbor : graph[node]) {
                int next = neighbor.first;
                int cost = neighbor.second;

                if (cost <= f - level) {
                    q.push({next, level + cost});
                }
            }
        }
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    graph.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v, l;
        cin >> u >> v >> l;
        graph[u].push_back({v, l});
        graph[v].push_back({u, l});
    }

    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        int d, f, p;
        cin >> d >> f >> p;
        observations.push_back(d);
        observations.push_back(f);
        observations.push_back(p);
    }

    int low = 0, high = 1e9;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (check(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}