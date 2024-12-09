#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool possible = true;
vector<int> colors;
vector<vector<int>> adj;
vector<int> colorVisited;

void dfs(int v, int parent, int c) {
    colors[v] = c;
    colorVisited[c] = true;
    for (int u : adj[v]) {
        if (u != parent) {
            c++;
            if (c > colors.size()) {
                c = 1;
            }
            while (colorVisited[c]) {
                c++;
                if (c > colors.size()) {
                    c = 1;
                }
            }
            dfs(u, v, c);
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    colors.resize(n + 1);
    colorVisited.resize(k + 1);
    adj.resize(n + 1);

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1, 1);

    for (int i = 1; i <= n; i++) {
        if (!colors[i]) {
            possible = false;
            break;
        }
    }

    if (possible) {
        cout << "Yes" << endl;
        for (int i = 1; i <= n; i++) {
            cout << colors[i] << " ";
        }
        cout << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}