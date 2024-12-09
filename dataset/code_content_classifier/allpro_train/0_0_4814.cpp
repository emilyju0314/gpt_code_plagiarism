#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;
vector<int> subtreeSize;
int n, k;
long long answer = 0;

void dfs(int v, int parent) {
    subtreeSize[v] = 1;
    for (int u : tree[v]) {
        if (u != parent) {
            dfs(u, v);
            subtreeSize[v] += subtreeSize[u];
            if (subtreeSize[u] <= k) {
                answer += subtreeSize[u];
            }
        }
    }
}

int main() {
    cin >> n >> k;
    tree.resize(n + 1);
    subtreeSize.resize(n + 1);

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1, 0);

    cout << answer * 2 << endl;

    return 0;
}