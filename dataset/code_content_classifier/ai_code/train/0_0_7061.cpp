#include <iostream>
#include <vector>

using namespace std;

vector<int> vertices;
vector<int> edges;
vector<vector<int>> adj_list;
vector<int> ans;

void dfs(int v, int p) {
    int controlled_vertices = 0;
    for (int u : adj_list[v]) {
        if (u != p) {
            if (edges[v] >= edges[u]) {
                controlled_vertices++;
            }
            dfs(u, v);
        }
    }
    ans[v] = controlled_vertices;
}

int main() {
    int n;
    cin >> n;

    vertices.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> vertices[i];
    }

    edges.resize(n);
    adj_list.resize(n);
    for (int i = 1; i < n; i++) {
        int p, w;
        cin >> p >> w;
        p--;
        edges[i] = w;
        adj_list[p].push_back(i);
    }

    ans.resize(n);
    dfs(0, -1);

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}