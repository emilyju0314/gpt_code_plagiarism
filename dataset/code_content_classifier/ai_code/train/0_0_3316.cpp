#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int k;
    cin >> k;

    for (int t = 0; t < k; t++) {
        int s, l;
        cin >> s >> l;

        vector<bool> visited(n+1, false);
        queue<int> q;
        q.push(s);
        visited[s] = true;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int v : adj[cur]) {
                if (!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }

        if (visited[l]) {
            cout << "0" << endl;
        } else {
            int important = 0;
            for (int i = 1; i <= n; i++) {
                if (i != s && i != l) {
                    vector<bool> visited2(n+1, false);
                    queue<int> q2;
                    q2.push(s);
                    visited2[s] = true;

                    while (!q2.empty()) {
                        int cur = q2.front();
                        q2.pop();

                        for (int v : adj[cur]) {
                            if (v != i && !visited2[v]) {
                                q2.push(v);
                                visited2[v] = true;
                            }
                        }
                    }

                    if (!visited2[l]) {
                        important++;
                    }
                }
            }

            cout << important << endl;
        }
    }

    return 0;
}