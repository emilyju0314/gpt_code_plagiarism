#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 2e5 + 5;

int N, Q;
vector<int> adj[MAXN];
int counter[MAXN];

void dfs(int v, int parent, int increment) {
    counter[v] += increment;
    for (int u : adj[v]) {
        if (u != parent) {
            dfs(u, v, counter[v]);
        }
    }
}

int main() {
    cin >> N >> Q;

    for (int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= Q; i++) {
        int p, x;
        cin >> p >> x;
        dfs(p, 0, x);
    }

    for (int i = 1; i <= N; i++) {
        cout << counter[i] << " ";
    }
    cout << endl;

    return 0;
}