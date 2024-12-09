#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n+1);
    vector<int> degrees(n+1, 0);
    vector<int> distance_from_root(n+1, 0);

    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        degrees[a]++;
        degrees[b]++;
    }

    queue<int> q;
    q.push(1);
    distance_from_root[1] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int neighbor : adj[cur]) {
            if (distance_from_root[neighbor] == 0) {
                distance_from_root[neighbor] = distance_from_root[cur] + 1;
                q.push(neighbor);
            }
        }
    }

    vector<int> possible_roots;
    for (int i = 1; i <= n; i++) {
        bool valid = true;
        for (int neighbor : adj[i]) {
            if (distance_from_root[i] == distance_from_root[neighbor] && degrees[i] != degrees[neighbor]) {
                valid = false;
                break;
            }
        }
        if (valid) {
            possible_roots.push_back(i);
        }
    }

    if (possible_roots.empty()) {
        cout << -1 << endl;
    } else {
        cout << possible_roots[0] << endl;
    }

    return 0;
}