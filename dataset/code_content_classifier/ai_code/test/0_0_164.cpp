#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxN = 2e5 + 5;
int n, k;
string labels;
vector<int> adj[maxN];
int duplicates[maxN] = {0};

void dfs(int u, int parent) {
    for (int v : adj[u]) {
        if (v != parent) {
            dfs(v, u);
            duplicates[u] += duplicates[v];
        }
    }

    if(u != 1 && duplicates[u] < k) {
        labels[u - 1] = labels[u - 1] + labels[u - 1];
        duplicates[u]++;
    }
}

int main() {
    cin >> n >> k;
    cin >> labels;

    for(int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        if (l) adj[i].push_back(l);
        if (r) adj[i].push_back(r);
    }

    dfs(1, 0);

    for(int i = 1; i <= n; i++) {
        cout << labels[i-1];
    }

    cout << endl;

    return 0;
}