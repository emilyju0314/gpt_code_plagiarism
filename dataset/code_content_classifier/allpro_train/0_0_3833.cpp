#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[200005];
vector<int> citizens;
long long total = 0;

void dfs(int v, int parent) {
    for(int u : adj[v]) {
        if(u != parent) {
            dfs(u, v);
            citizens[v] += citizens[u];
        }
    }
}

int main() {
    int n;
    cin >> n;

    for(int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }

    citizens.resize(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> citizens[i];
        total += citizens[i];
    }

    dfs(1, 0);

    cout << total - citizens[1] << endl;

    return 0;
}