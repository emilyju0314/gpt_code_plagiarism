#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    unordered_map<int, int> degree;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);

        degree[a]++;
        degree[b]++;
    }

    bool possible = true;
    for (int i = 1; i <= n; i++) {
        if (degree[i] % 2 != 0) {
            possible = false;
            break;
        }
    }

    if (!possible) {
        cout << "No solution" << endl;
    } else {
        for (int i = 1; i <= n; i++) {
            for (int j : adj[i]) {
                if (i < j) {
                    cout << i << " " << j << " " << adj[i][0] << endl;
                    adj[i].erase(adj[i].begin());
                    adj[j].erase(find(adj[j].begin(), adj[j].end(), i));
                }
            }
        }
    }

    return 0;
}