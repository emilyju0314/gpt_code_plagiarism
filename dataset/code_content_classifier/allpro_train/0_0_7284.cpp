#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[200000];
bool visited[200000];

int findParent(int v, int parent) {
    for (int u : adj[v]) {
        if (u != parent) {
            return u;
        }
    }
    return -1;
}

bool checkMcDic(int v, int parent) {
    if (visited[v]) {
        return false;
    }
    visited[v] = true;

    if (adj[v].size() == 0) {
        return true;
    }

    if (adj[v].size() != 2) {
        return false;
    }

    int child1 = adj[v][0];
    int child2 = adj[v][1];

    if ((child1 == parent && findParent(child2, v) == -1) || 
        (child2 == parent && findParent(child1, v) == -1)) {
        return true;
    }

    return checkMcDic(child1, v) && checkMcDic(child2, v);
}

int main() {
    int n;
    cin >> n;

    int numVertices = (1 << n) - 1;

    for (int i = 0; i < numVertices - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int root = 1;
    while (adj[root].size() == 1) {
        root++;
    }

    if (checkMcDic(root, -1)) {
        cout << "1\n";
        for (int i = 1; i <= numVertices - 1; i++) {
            if (adj[i].size() == 1) {
                int parent = adj[i][0];
                cout << parent << " ";
            }
        }
    } else {
        cout << "0\n";
    }

    return 0;
}