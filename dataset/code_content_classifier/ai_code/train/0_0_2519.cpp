#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> order(n);
    for(int i = 0; i < n; i++) {
        cin >> order[i];
    }

    vector<int> bfs_order;
    queue<int> q;
    q.push(1);
    vector<bool> visited(n + 1, false);
    visited[1] = true;

    while(!q.empty()) {
        int v = q.front();
        q.pop();
        bfs_order.push_back(v);

        for(int u : adj[v]) {
            if(!visited[u]) {
                visited[u] = true;
                q.push(u);
            }
        }
    }

    if(is_permutation(order.begin(), order.end(), bfs_order.begin())) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}