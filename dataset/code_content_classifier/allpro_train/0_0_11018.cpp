#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> p(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    vector<vector<int>> graph(n+1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> deletedEdges(m+1);
    while (q--) {
        int queryType;
        cin >> queryType;

        if (queryType == 1) {
            int v;
            cin >> v;

            int max_p = 0;
            for (int u : graph[v]) {
                max_p = max(max_p, p[u]);
            }

            cout << max_p << endl;

            for (int u : graph[v]) {
                if (p[u] == max_p) {
                    p[u] = 0;
                    break;
                }
            }
        } else {
            int i;
            cin >> i;
            deletedEdges[i] = 1;
        }
    }

    return 0;
}