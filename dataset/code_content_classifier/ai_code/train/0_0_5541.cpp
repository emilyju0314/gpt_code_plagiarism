#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
const long long MOD = 1e9 + 7;

struct Node {
    long long sum = 0;
};

vector<vector<int>> adj;
vector<int> subtreeSize;
vector<int> parent;
vector<int> level;
vector<int> chainHead;
vector<int> chainPos;
vector<int> chainInd;
vector<int> chainSize;
int chainNo, posInBase;
vector<int> base;
vector<int> posInSeg;
vector<int> segTree;
int N;

void HLD(int v, int p = -1) {
    if (chainHead[chainNo] == -1) {
        chainHead[chainNo] = v;
    }
    chainInd[v] = chainNo;
    chainPos[v] = posInBase;
    posInSeg[posInBase] = v;
    posInBase++;

    int sc = -1;
    for (int u : adj[v]) {
        if (u != p) {
            if (sc == -1 || subtreeSize[u] > subtreeSize[sc]) {
                sc = u;
            }
        }
    }

    if (sc != -1) {
        HLD(sc, v);
    }

    for (int u : adj[v]) {
        if (u != p && u != sc) {
            chainNo++;
            HLD(u, v);
        }
    }
}

void build(int v, int L, int R) {
    if (L == R) {
        segTree[v] = base[L];
    } else {
        int mid = (L + R) / 2;
        build(2 * v, L, mid);
        build(2 * v + 1, mid + 1, R);
        segTree[v] = (segTree[2 * v] + segTree[2 * v + 1]) % MOD;
    }
}

void update(int v, int L, int R, int pos, int val) {
    if (L == R) {
        segTree[v] = val;
    } else {
        int mid = (L + R) / 2;
        if (pos <= mid) {
            update(2 * v, L, mid, pos, val);
        } else {
            update(2 * v + 1, mid + 1, R, pos, val);
        }
        segTree[v] = (segTree[2 * v] + segTree[2 * v + 1]) % MOD;
    }
}

long long query(int v, int L, int R, int l, int r) {
    if (L > r || R < l) {
        return 0;
    }
    if (L >= l && R <= r) {
        return segTree[v];
    }
    int mid = (L + R) / 2;
    return (query(2 * v, L, mid, l, r) + query(2 * v + 1, mid + 1, R, l, r)) % MOD;
}

int main() {
    int Q;
    cin >> N >> Q;

    adj.resize(N);
    subtreeSize.assign(N, 1);
    parent.assign(N, -1);
    level.assign(N, 0);
    chainHead.assign(N, -1);
    chainPos.resize(N);
    chainInd.resize(N);
    base.resize(N);
    posInSeg.resize(N);
    segTree.resize(4 * N);

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    HLD(0);

    for (int i = 0; i < Q; i++) {
        int type;
        cin >> type;
        if (type == 0) {
            int S, T;
            cin >> S >> T;

            int res = 0;
            while (chainInd[S] != chainInd[T]) {
                if (level[chainHead[chainInd[S]]] < level[chainHead[chainInd[T]]]) {
                    swap(S, T);
                }
                res = (res + query(1, 0, posInBase - 1, chainPos[chainHead[chainInd[S]]], chainPos[S])) % MOD;
                S = parent[chainHead[chainInd[S]]];
            }
            if (level[S] > level[T]) {
                swap(S, T);
            }
            res = (res + query(1, 0, posInBase - 1, chainPos[S], chainPos[T])) % MOD;
            cout << res << endl;
        } else if (type == 1) {
            int S, T, K, M;
            cin >> S >> T >> K >> M;

            int res = 0;
            while (chainInd[S] != chainInd[T]) {
                if (level[chainHead[chainInd[S]]] < level[chainHead[chainInd[T]]]) {
                    swap(S, T);
                }
                update(1, 0, posInBase - 1, chainPos[chainHead[chainInd[S]]], (K + level[S] * M) % MOD);
                S = parent[chainHead[chainInd[S]]];
            }
            if (level[S] > level[T]) {
                swap(S, T);
            }
            update(1, 0, posInBase - 1, chainPos[S], (K + level[S] * M) % MOD);
        }
    }

    return 0;
}