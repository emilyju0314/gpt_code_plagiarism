#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> degree(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        degree[x]++;
        degree[y]++;
    }

    int odd_degrees = 0;
    for (int i = 1; i <= n; i++) {
        if (degree[i] % 2 != 0) {
            odd_degrees++;
        }
    }

    if (odd_degrees == 0 || odd_degrees == 2) {
        cout << 0 << endl;
    } else {
        cout << (odd_degrees - 2) / 2 + 1 << endl;
    }

    return 0;
}