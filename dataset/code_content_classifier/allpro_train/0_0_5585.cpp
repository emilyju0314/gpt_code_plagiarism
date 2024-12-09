#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 100005

int n, q;
int f[MAXN];
vector<pair<int, int>> graph[MAXN];
int parent[MAXN];
int depth[MAXN];
int subtreeSize[MAXN];
int chainHead[MAXN];
int chainInd[MAXN];
int posInBase[MAXN];
int baseArray[MAXN];
int chainNo;
int baseArrayInd;
vector<int> chains[MAXN];
vector<int> st[4 * MAXN];

void dfs(int node, int par, int d) {
    parent[node] = par;
    depth[node] = d;
    subtreeSize[node] = 1;
    for (auto u : graph[node]) {
        if (u.first != par) {
            dfs(u.first, node, d + 1);
            subtreeSize[node] += subtreeSize[u.first];
        }
    }
}

void hld(int curNode, int cost, int prev) {
    if (chainHead[chainNo] == -1) {
        chainHead[chainNo] = curNode;
    }
    chainInd[curNode] = chainNo;
    posInBase[curNode] = baseArrayInd;
    baseArray[baseArrayInd++] = cost;

    int heavyNode = -1, heavyCost = 0;
    
    for (auto u : graph[curNode]) {
        if (u.first != prev && (heavyNode == -1 || subtreeSize[u.first] > subtreeSize[heavyNode])) {
            heavyNode = u.first;
            heavyCost = u.second;
        }
    }

    if (heavyNode != -1) {
        hld(heavyNode, heavyCost, curNode);
    }

    for (auto u : graph[curNode]) {
        if (u.first != prev && u.first != heavyNode) {
            ++chainNo;
            hld(u.first, u.second, curNode);
        }
    }
}

void build(int node, int start, int end, int chain) {
    if (start == end) {
        st[node].push_back(f[baseArray[start]]);
    } else {
        int mid = (start + end) / 2;
        build(2 * node + 1, start, mid, chain);
        build(2 * node + 2, mid + 1, end, chain);
        merge(st[2 * node + 1].begin(), st[2 * node + 1].end(), st[2 * node + 2].begin(), st[2 * node + 2].end(), back_inserter(st[node]));
    }
}

int query(int node, int start, int end, int l, int r, int x) {
    if (start > r || end < l) return 0;

    if (start >= l && end <= r) {
        return upper_bound(st[node].begin(), st[node].end(), x) - st[node].begin();
    }

    int mid = (start + end) / 2;
    return query(2 * node + 1, start, mid, l, r, x) + query(2 * node + 2, mid + 1, end, l, r, x);
}

int queryHLD(int u, int v, int w) {
    int ans = 0;
    
    while (chainInd[u] != chainInd[v]) {
        if (depth[chainHead[chainInd[u]]] < depth[chainHead[chainInd[v]]]) {
            swap(u, v);
        }

        ans += query(0, 0, baseArrayInd - 1, posInBase[chainHead[chainInd[u]]], posInBase[u], w);
        u = parent[chainHead[chainInd[u]]];
    }
    
    if (depth[u] > depth[v]) {
        swap(u, v);
    }
    
    ans += query(0, 0, baseArrayInd - 1, posInBase[u], posInBase[v], w);

    return ans;
}

int main() {
    cin >> n >> q;

    for (int i = 1; i < n; i++) {
        cin >> f[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    chainNo = 0;
    baseArrayInd = 0;
    fill(chainHead, chainHead + n, -1);
    dfs(1, 0, 0);
    hld(1, 0, 0);

    for (int i = 0; i <= chainNo; i++) {
        build(0, 0, chains[i].size() - 1, i);
    }

    for (int i = 0; i < q; i++) {
        int u, v, l;
        cin >> u >> v >> l;
        cout << queryHLD(u, v, l) << endl;
    }

    return 0;
}