#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> set;
vector<bool> visited;

void dfs(int node) {
    visited[node] = true;
    for (int i = 0; i < m; i++) {
        if ((set[i] & set[node]) == 0 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    cin >> n >> m;
    set.resize(m);
    visited.resize(m, false);

    for (int i = 0; i < m; i++) {
        cin >> set[i];
    }

    int components = 0;
    for (int i = 0; i < m; i++) {
        if (!visited[i]) {
            dfs(i);
            components++;
        }
    }

    cout << components << endl;

    return 0;
}