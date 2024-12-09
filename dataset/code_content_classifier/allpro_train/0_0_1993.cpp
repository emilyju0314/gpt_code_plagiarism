#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
int parent[MAXN];
int weight[MAXN];

void add(int v, int w) {
    weight[v] += w;
}

int getSum(int u) {
    int sum = weight[u];
    while(u != 0) {
        sum += weight[parent[u]];
        u = parent[u];
    }
    return sum;
}

void dfs(int u) {
    for(int v : adj[u]) {
        parent[v] = u;
        dfs(v);
    }
}

int main() {
    int n;
    cin >> n;

    for(int i = 1; i < n; i++) {
        int k;
        cin >> k;
        for(int j = 0; j < k; j++) {
            int c;
            cin >> c;
            adj[i].push_back(c);
        }
    }

    parent[0] = -1;
    dfs(0);

    int q;
    cin >> q;

    for(int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if(type == 0) {
            int v, w;
            cin >> v >> w;
            add(v, w);
        } else {
            int u;
            cin >> u;
            cout << getSum(u) << endl;
        }
    }

    return 0;
}