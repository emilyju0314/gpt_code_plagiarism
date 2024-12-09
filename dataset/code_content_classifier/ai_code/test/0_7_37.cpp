#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> tree[n+1];
        vector<pair<int, int>> edges;

        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
        }

        int cur = 1;
        for (int i = 2; i <= n; i++) {
            edges.push_back({cur, i});
            tree[cur].push_back(i);
            cur = i;
        }

        for (auto edge : edges) {
            cout << edge.first << " " << edge.second << endl;
        }
    }

    return 0;
}