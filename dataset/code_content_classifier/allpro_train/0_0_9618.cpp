#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int V, E;
    cin >> V >> E;

    vector<int> in_degree(V, 0);
    vector<vector<int>> adj_list(V);

    for (int i = 0; i < E; i++) {
        int s, t;
        cin >> s >> t;
        adj_list[s].push_back(t);
        in_degree[t]++;
    }

    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << endl;

        for (int neighbor : adj_list[current]) {
            in_degree[neighbor]--;
            if (in_degree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return 0;
}