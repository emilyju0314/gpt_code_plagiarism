#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 100005;

int n, m;
int x[MAXN];
vector<int> graph[MAXN];
vector<int> path;

bool dfs(int node) {
    path.push_back(node);

    for (int neighbor : graph[node]) {
        graph[node].erase(find(graph[node].begin(), graph[node].end(), neighbor));
        graph[neighbor].erase(find(graph[neighbor].begin(), graph[neighbor].end(), node));
        
        if (dfs(neighbor)) {
            return true;
        }

        graph[node].push_back(neighbor);
        graph[neighbor].push_back(node);
    }

    path.pop_back();
    return false;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }

    int start = -1;
    for (int i = 1; i <= n; i++) {
        if (x[i] == 1) {
            start = i;
            break;
        }
    }

    if (start == -1) {
        for (int i = 1; i <= n; i++) {
            if (!graph[i].empty()) {
                start = i;
                break;
            }
        }
    }

    if (start == -1) {
        cout << -1 << endl;
    } else {
        dfs(start);

        cout << path.size() << endl;
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}