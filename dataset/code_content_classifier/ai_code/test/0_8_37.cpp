#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> edges;

        for(int i = 0; i < n - 1; i++) {
            edges.push_back({i+1, i+2});
        }

        for(int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
        }

        for(auto edge : edges) {
            cout << edge.first << " " << edge.second << endl;
        }
    }

    return 0;
}