#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    vector<int> topic(n+1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        cin >> topic[i];
    }

    vector<int> order;
    vector<bool> visited(n+1, false);
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i <= n; i++) {
        unordered_set<int> covered;
        for (int neighbor : adj[i]) {
            if (topic[neighbor] != topic[i]) {
                covered.insert(topic[neighbor]);
            }
        }
        for (int j = 1; j <= n; j++) {
            if (covered.find(j) == covered.end()) {
                pq.push(j);
            }
        }
        if (!pq.empty()) {
            order.push_back(pq.top());
            visited[i] = true;
            pq.pop();
        } else {
            cout << -1 << endl;
            return 0;
        }
    }

    for (int blog : order) {
        cout << blog << " ";
    }
    cout << endl;

    return 0;
}