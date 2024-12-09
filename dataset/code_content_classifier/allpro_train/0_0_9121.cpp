#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<pair<int, int>> flights;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        flights.push_back({a, b});
    }

    vector<bool> visited(n, false);
    visited[0] = true;
    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int city = q.front();
        q.pop();
        
        for (int neighbor : adj[city]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    if (visited[n - 1]) {
        cout << "Yes" << endl;
        for (pair<int, int> flight : flights) {
            if (visited[flight.first] && visited[flight.second]) {
                cout << "1" << endl;
            } else {
                cout << "2" << endl;
            }
        }
    } else {
        cout << "No" << endl;
    }

    return 0;
}