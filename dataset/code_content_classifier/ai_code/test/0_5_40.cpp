#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAXN = 300005;
vector<int> adj[MAXN];
int dist[MAXN];
set<pair<int, int>> path;

void dfs(int u, int p, int d) {
    dist[u] = d;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, d + 1);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, 0, 0);

    int q;
    cin >> q;

    cout << "YES" << endl;

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;

        int even_dist = dist[a] + dist[b];
        if (even_dist % 2 == 0) {
            cout << "2" << endl;
            cout << a << " " << b << endl;
        } else {
            int z = 1;
            for (int j = 1; j <= n; j++) {
                if (dist[j] % 2 == 0 && (dist[j] < even_dist / 2 || (dist[j] == even_dist / 2 && a != j && b != j))) {
                    z++;
                    if (z == 3) {
                        cout << z << endl;
                        cout << a << " " << j << " " << b << endl;
                        break;
                    }
                    path.insert({a, j});
                    path.insert({b, j});
                }
            }
        }
    }

    return 0;
}