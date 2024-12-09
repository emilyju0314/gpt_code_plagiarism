#include <iostream>
#include <vector>

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

    vector<int> party(n+1, -1);
    for (int i = 1; i <= n; i++) {
        if (party[i] == -1) {
            party[i] = 0;
            for (int j : adj[i]) {
                if (party[j] == party[i]) {
                    party[j] = 1;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (party[i] == -1) {
            cout << -1 << endl;
            return 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << party[i];
    }
    cout << endl;

    return 0;
}