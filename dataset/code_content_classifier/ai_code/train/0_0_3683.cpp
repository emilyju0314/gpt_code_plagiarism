#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> cities[100005];
int parent[100005];
int depth[100005];
vector<int> people_in_city[100005];

void dfs(int node, int par, int d) {
    parent[node] = par;
    depth[node] = d;

    for (int child : cities[node]) {
        if (child != par) {
            dfs(child, node, d + 1);
        }
    }
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        cities[v].push_back(u);
        cities[u].push_back(v);
    }

    for (int i = 1; i <= m; i++) {
        int city;
        cin >> city;
        people_in_city[city].push_back(i);
    }

    dfs(1, 0, 0); // Assuming the root of the tree is city 1

    for (int i = 0; i < q; i++) {
        int v, u, a;
        cin >> v >> u >> a;

        vector<int> people_on_path;
        while (v != 0) {
            for (int person : people_in_city[v]) {
                people_on_path.push_back(person);
            }
            v = parent[v];
        }

        while (u != 0) {
            for (int person : people_in_city[u]) {
                people_on_path.push_back(person);
            }
            u = parent[u];
        }

        sort(people_on_path.begin(), people_on_path.end());

        int k = min((int)people_on_path.size(), a);
        cout << k;
        for (int j = 0; j < k; j++) {
            cout << " " << people_on_path[j];
        }
        cout << endl;
    }

    return 0;
}