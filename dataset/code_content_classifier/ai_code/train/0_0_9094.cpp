#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    vector<bool> reachable(n + 1, false);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        for (int neighbor : graph[i]) {
            for (int neighbor_neighbor : graph[neighbor]) {
                reachable[neighbor_neighbor] = true;
            }
        }
    }

    unordered_set<int> result;
    for (int i = 1; i <= n; i++) {
        if (!reachable[i]) {
            result.insert(i);
        }
    }

    cout << result.size() << endl;
    for (int vertex : result) {
        cout << vertex << " ";
    }

    return 0;
}