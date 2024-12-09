#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool dfs(vector<vector<int>>& graph, vector<int>& deputy, vector<int>& visited, int city, int currDeputy) {
    deputy[city] = currDeputy;
    visited[city] = 1;

    for (int neighbor : graph[city]) {
        if (deputy[neighbor] == currDeputy) {
            return false;
        }
        if (visited[neighbor] == 0 && !dfs(graph, deputy, visited, neighbor, 3 - currDeputy)) {
            return false;
        }
    }

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    vector<int> deputy(n + 1, 0);
    vector<int> visited(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0 && !dfs(graph, deputy, visited, i, 1)) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) {
        cout << deputy[i] << " ";
    }
    cout << endl;

    return 0;
}