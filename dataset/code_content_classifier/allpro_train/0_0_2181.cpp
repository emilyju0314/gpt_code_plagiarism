#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int MAXN = 1e5 + 5;

vector<int> adj[MAXN];
double x[MAXN], y[MAXN]; 
double res = 0.0;
int n;

void dfs(int u, int p, int depth) {
    res += (double)depth * x[u] * y[u];

    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, depth + 1);
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }

    dfs(1, 0, 0);

    cout << fixed << setprecision(20) << res << endl;

    return 0;
}