#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> strengths(n);
    for (int i = 0; i < n; i++) {
        cin >> strengths[i];
    }

    vector<vector<int>> graph(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (graph[i].size() == 1) {
            q.push(i);
        }
    }

    int computerStrength = *max_element(strengths.begin(), strengths.end());
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
            auto it = find(graph[neighbor].begin(), graph[neighbor].end(), node);
            graph[neighbor].erase(it);

            if (strengths[neighbor] < computerStrength) {
                q.push(neighbor);
            }
        }
    }

    cout << computerStrength << endl;

    return 0;
}