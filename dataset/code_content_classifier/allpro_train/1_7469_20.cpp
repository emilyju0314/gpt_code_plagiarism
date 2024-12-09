#include <bits/stdc++.h>

using namespace std;


void dfs3(int v, vector<vector<int>> &graf, vector<int> &ways) {
    ways[v] = -1;
    for (auto el : graf[v]) {
        if (ways[el] != -1) {
            dfs3(el, graf, ways);
        }
    }
}

void dfs2(int v, vector<vector<int>> &graf,  vector<int> &ways) {
    ways[v] = 2;
    for (auto el : graf[v]) {
        if (ways[el] == 1) {
            dfs2(el, graf, ways);
        }
    }
}

void dfs(int v, vector<int> &vis, vector<int> &cycle, vector<vector<int>> &graf,  vector<int> &ways, vector<int> &progr) {
    if (progr[v] == 1) {
        cycle.push_back(v);
        ways[v] = -1;
    } else if (progr[v] == 2) {
        vis.push_back(v);
        ways[v] = 2;
    } else {
        progr[v] = 1;
        for (auto el : graf[v]) {
            dfs(el, vis, cycle, graf, ways, progr);
        }
        progr[v] = 2;
        ways[v] = 1;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        if (m == 0) {
            cout << 1 << " ";
            for (int i = 1; i != n; i++) {
                cout << 0 << " ";
            }
        } else {
            vector<vector<int>> graf(n);
            vector<int> ways(n, 0);
            vector<int> progr(n, 0);
            // 1 - in progress, 0 - new, 2 - visited
            vector<int> cycle;
            vector<int> vis;
            for (int i = 0; i != m; i++) {
                int s, f;
                cin >> s >> f;
                graf[s - 1].push_back(f - 1);
            }
            dfs(0, vis, cycle, graf, ways, progr);
            for (auto el : vis) {
                dfs2(el, graf, ways);
            }
            for (auto el : cycle) {
                dfs3(el, graf, ways);
            }
            for (auto el : ways) {
                cout << el << " ";
            }
        }
        cout << '\n';
    }
    return 0;
}
