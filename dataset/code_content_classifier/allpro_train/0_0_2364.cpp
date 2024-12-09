#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<int> incomes;
int n;

bool dfs(int cur, int parent, int targetIncome) {
    if (targetIncome == -1) {
        targetIncome = incomes[parent] - 1;
    }
    incomes[cur] = targetIncome;

    for (int neighbor : adj[cur]) {
        if (neighbor != parent) {
            if (incomes[neighbor] != -1) {
                if (incomes[cur] != incomes[neighbor] + 1) {
                    return false;
                }
            } else {
                if (!dfs(neighbor, cur, incomes[cur] - 1)) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    int m;
    cin >> n >> m;

    adj.resize(n + 1);
    incomes.assign(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int u, v, b;
        cin >> u >> v >> b;
        adj[u].push_back(v);
        adj[v].push_back(u);
        if (b == 1) {
            incomes[u] = 1;
            incomes[v] = 0;
        }
    }

    vector<int> visited(n + 1, 0);
    if (!dfs(1, 0, -1)) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << n << endl;
        for (int i = 1; i <= n; i++) {
            cout << incomes[i] << " ";
        }
    }

    return 0;
}