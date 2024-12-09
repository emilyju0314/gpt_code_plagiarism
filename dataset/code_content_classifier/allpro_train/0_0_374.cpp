#include <iostream>
#include <vector>

using namespace std;

vector<vector<pair<int, pair<int, int>>> graph; // Graph represented as an adjacency list
int max_loyalty = 0;

void dfs(int u, int destination, int current_loyalty) {
    if (u == destination) {
        max_loyalty = max(max_loyalty, current_loyalty);
        return;
    }

    for (auto edge : graph[u]) {
        int v = edge.first;
        int lower_bound = edge.second.first;
        int upper_bound = edge.second.second;

        if (current_loyalty >= lower_bound && current_loyalty <= upper_bound) {
            dfs(v, destination, max(current_loyalty, lower_bound));
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    graph.resize(n + 1);
    
    for (int i = 0; i < m; i++) {
        int a, b, l, r;
        cin >> a >> b >> l >> r;
        graph[a].push_back({b, {l, r}});
    }

    dfs(1, n, 0);

    if (max_loyalty == 0) {
        cout << "Nice work, Dima!" << endl;
    } else {
        cout << max_loyalty << endl;
    }

    return 0;
}