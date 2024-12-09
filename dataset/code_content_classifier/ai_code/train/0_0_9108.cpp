#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<int> num_children;

void dfs(int v, int parent) {
    num_children[v] = 0;
    for (int u : adj[v]) {
        if (u != parent) {
            dfs(u, v);
            num_children[v]++;
        }
    }
}

int main() {
    int n;
    cin >> n;

    adj.resize(n+1);
    num_children.resize(n+1);

    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    int min_f = 0, max_f = 0;
    for (int i = 1; i <= n; i++) {
        if (num_children[i] == 0) {
            min_f++;
            max_f++;
        } else {
            max_f += num_children[i] - 1;
        }
    }

    cout << min_f << " " << max_f << endl;

    return 0;
}