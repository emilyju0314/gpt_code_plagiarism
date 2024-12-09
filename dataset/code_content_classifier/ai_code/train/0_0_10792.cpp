#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n;
vector<int> apples;
vector<vector<int>> adj;
vector<int> subTree;
unordered_map<long long, int> cnt, total;
long long ans = 0;

void dfs(int node, int parent) {
    subTree[node] = apples[node];
    for (int child : adj[node]) {
        if (child == parent) continue;
        
        dfs(child, node);
        subTree[node] += subTree[child];
    }
}

void count_pairs(int node, int parent, bool flag, long long xorVal) {
    xorVal ^= subTree[node];
    if (flag) {
        cnt[xorVal]++;
        total[xorVal]++;
        for (int child : adj[node]) {
            if (child == parent) continue;
            count_pairs(child, node, flag, xorVal);
        }
    } else {
        ans += total[xorVal];
        for (int child : adj[node]) {
            if (child == parent) continue;
            count_pairs(child, node, flag, xorVal);
        }
    }
}

int main() {
    cin >> n;
    apples.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> apples[i];
    }

    adj.resize(n);
    subTree.resize(n);

    for (int i = 1; i < n; i++) {
        int parent;
        cin >> parent;
        parent--; // 0-indexed
        adj[parent].push_back(i);
    }

    dfs(0, -1);
    
    for (int i = 0; i < n; i++) {
        cnt.clear();
        total.clear();
        count_pairs(i, -1, true, 0);
        count_pairs(i, -1, false, 0);
    }

    cout << ans - n << endl; // subtract n to exclude the pairs (u,u)

    return 0;
}