#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        if (adj[i].size() >= 4) {
            cout << i << " ";

            vector<int> friends = adj[i];
            for (int j = 0; j < 3; j++) {
                cout << friends[j] << " ";
            }

            cout << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}