#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> in_degree(n + 1, 0);
    vector<int> wants(n + 1);

    for (int i = 0; i < m; i++) {
        int p, q;
        cin >> p >> q;
        adj[p].push_back(q);
        in_degree[q]++;
    }

    for (int i = 1; i <= n; i++) {
        cin >> wants[i];
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> result;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        result.push_back(cur);

        for (int next : adj[cur]) {
            in_degree[next]--;
            if (in_degree[next] == 0) {
                q.push(next);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (wants[i] != result[i-1]) {
            cout << "-1" << endl;
            return 0;
        }
    }

    cout << n << endl;
    for (int person : result) {
        cout << person << endl;
    }

    return 0;
}