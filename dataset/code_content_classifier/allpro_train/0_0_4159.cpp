#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    vector<int> in_degree(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        in_degree[b]++;
    }

    set<int> ans;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            ans.insert(i);
            for (int v : graph[i]) {
                for (int u : graph[v]) {
                    in_degree[u]--;
                }
            }
        }
    }

    cout << ans.size() << endl;
    for (int v : ans) {
        cout << v << " ";
    }

    return 0;
}