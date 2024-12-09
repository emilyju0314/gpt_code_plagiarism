#include <bits/stdc++.h>
using namespace std;

vector<int> tree[100005];
int starting_time[100005];
int current_time = 0;

void dfs(int v) {
    current_time++;
    starting_time[v] = current_time;

    random_shuffle(tree[v].begin(), tree[v].end());

    for (int u : tree[v]) {
        dfs(u);
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        int parent;
        cin >> parent;
        tree[parent].push_back(i);
    }

    dfs(1);

    for (int i = 1; i <= n; i++) {
        cout << starting_time[i] << " ";
    }

    return 0;
}