#include <iostream>
#include <vector>
#include <queue>
#define MOD 998244353

using namespace std;

int power(int x, int y) {
    int result = 1;
    for (int i = 0; i < y; i++) {
        result = (result * 3) % MOD;
    }
    return result;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> adj(n);
        vector<int> visited(n, 0);

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int even_comps = 0;
        long long res = 1;

        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                int odd_count = 0;
                int even_count = 0;

                visited[i] = 1;
                queue<int> q;
                q.push(i);

                while (!q.empty()) {
                    int u = q.front();
                    q.pop();

                    if (visited[u] == 1) {
                        odd_count++;
                    } else {
                        even_count++;
                    }

                    for (int v : adj[u]) {
                        if (visited[v] == 0) {
                            visited[v] = (visited[u] == 1) ? 2 : 1;
                            q.push(v);
                        } else if (visited[v] == visited[u]) {
                            res = 0;
                        }
                    }
                }

                if (res != 0) {
                    if (odd_count == 0) {
                        even_comps++;
                    } else {
                        res = (res * (power(2, odd_count-1))) % MOD;
                    }
                }
            }
        }

        if (even_comps > 0) {
            res = (res * power(2, even_comps)) % MOD;
        }

        cout << res << "\n";
    }

    return 0;
}