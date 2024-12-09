#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int>> adj;
vector<int> lights;
vector<int> visited;
vector<int> xor_values;

int xor_count(int a) {
    int count = 0;
    while(a > 0) {
        count += a % 2;
        a /= 2;
    }
    return count % 2;
}

void dfs(int node, int parent, int current_xor) {
    visited[node] = 1;
    int actual = xor_values[parent] ^ current_xor; // Calculate the current XOR value

    for (int child : adj[node]) {
        if (child != parent) {
            if (lights[child] == -1) {
                lights[child] = actual;
            }
            dfs(child, node, lights[child]);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        adj.clear();
        adj.resize(n);
        lights.assign(n, -1);
        visited.assign(n, 0);
        xor_values.assign(n, 0);

        for (int i = 0; i < n - 1; i++) {
            int x, y, v;
            cin >> x >> y >> v;
            x--; y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
            if (v == -1) continue;
            lights[i + 1] = v;
        }

        for (int i = 0; i < m; i++) {
            int a, b, p;
            cin >> a >> b >> p;
            a--; b--;

            int x = xor_count(p);
            xor_values[a] = x;
            xor_values[b] = x;
        }

        int root = xor_values[0];
        lights[0] = root;
        dfs(0, -1, root);

        bool possible = true;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                possible = false;
                break;
            }
        }

        if (possible) {
            cout << "YES\n";
            for (int i = 1; i < n; i++) {
                cout << i + 1 << " " << adj[i][0] + 1 << " " << lights[i] << "\n";
            }
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}