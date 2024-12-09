#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[200001];
vector<int> order;

void dfs(int u) {
    order.push_back(u);

    for(int v : tree[u]) {
        dfs(v);
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    for(int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        tree[p].push_back(i);
    }

    for(int i = 0; i < q; i++) {
        int u, k;
        cin >> u >> k;

        order.clear(); // Clear the previous order

        dfs(u);

        if(k <= order.size()) {
            cout << order[k-1] << endl;
        } else {
            cout << "-1" << endl;
        }
    }

    return 0;
}