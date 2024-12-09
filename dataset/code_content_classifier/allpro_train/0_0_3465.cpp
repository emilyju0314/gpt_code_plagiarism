#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<vector<int>> adj;
vector<int> color;
set<pair<int, int>> availableColors;

void dfs(int u, int p, int c) {
    color[u] = c;
    set<int> usedColors;
    for(int v : adj[u]) {
        if(v != p) {
            if(availableColors.empty()) {
                cout << "NO\n";
                exit(0);
            }
            int chosenColor = *availableColors.begin();
            availableColors.erase(availableColors.begin());
            if(usedColors.find(color[v]) != usedColors.end()) {
                availableColors.insert(chosenColor);
                chosenColor = *availableColors.begin();
                availableColors.erase(availableColors.begin());
            }
            usedColors.insert(chosenColor);
            dfs(v, u, chosenColor);
        }
    }
}

int main() {
    int n;
    cin >> n;
    adj.resize(n + 1);
    color.resize(n + 1, 0);

    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int m;
    cin >> m;

    for(int i = 0; i < m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        availableColors.insert(i + 1);
    }

    dfs(1, 0, 0);

    cout << "YES\n";
    for(int i = 1; i <= n; i++) {
        cout << color[i] << endl;
    }

    return 0;
}