#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> p(n + 1);
    vector<int> in_degree(n + 1, 0);
    vector<vector<int>> adj_list(n + 1);
    vector<int> x(k), y(k);

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        if (p[i] != 0) {
            adj_list[p[i]].push_back(i);
            in_degree[i]++;
        }
    }

    for (int i = 0; i < k; i++) {
        cin >> x[i] >> y[i];
    }

    vector<int> order;
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        order.push_back(node);

        for (int neighbor : adj_list[node]) {
            in_degree[neighbor]--;
            if (in_degree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    if (order.size() < n) {
        cout << 0 << endl;
    } else {
        cout << 1;
        for (int i = 0; i < n; i++) {
            cout << order[i] << " ";
        }
        cout << endl;
    }

    return 0;
}